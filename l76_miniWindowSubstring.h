//
// Created by Ste7an on 2022/7/19.
//

#ifndef ALGORITHM_L76_MINIWINDOWSUBSTRING_H
#define ALGORITHM_L76_MINIWINDOWSUBSTRING_H
//最小覆盖字串

#include "string"
#include "vector"
#include "unordered_map"
using namespace std;

string miniWindow(string& s, string& t){
    unordered_map<char, int> dict;

    for(const auto& c : t){
        ++dict[c];
    }

    int cnt = 0;
    int left = 0, right = 0, len = s.size() + 1;
    int begin = -1;

    while(right < int(s.size())){
        if(dict.count(s[right]) && --dict[s[right]] >= 0){
            ++cnt;
        }
        ++right;

        while(cnt == t.size()){
            if(right - left < len){
                len = right - left;
                begin = left;
            }
            if(dict.count(s[left]) && ++dict[s[left]] > 0){
                --cnt;
            }
            ++left;
        }
    }
    return begin == -1 ? string() : s.substr(begin, len);
}
#endif //ALGORITHM_L76_MINIWINDOWSUBSTRING_H
