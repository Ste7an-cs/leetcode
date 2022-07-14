//
// Created by Ste7an on 2022/7/14.
//

#ifndef ALGORITHM_LENGTHOFLONGESTSUBSTRING3_H
#define ALGORITHM_LENGTHOFLONGESTSUBSTRING3_H
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

#include "string"
#include "unordered_map"
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> dict;
    int l = 0;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(dict.count(s[i])){
            l = max(l, dict[s[i]] + 1);
        }
        dict[s[i]] = i;
        ans = max(ans, i - l + 1);
    }
    return ans;
}

#endif //ALGORITHM_LENGTHOFLONGESTSUBSTRING3_H
