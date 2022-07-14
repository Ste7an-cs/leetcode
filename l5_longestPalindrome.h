//
// Created by Ste7an on 2022/7/14.
//

#ifndef ALGORITHM_L5_LONGESTPALINDROME_H
#define ALGORITHM_L5_LONGESTPALINDROME_H
//最长回文字串
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。



//中心扩展法
#include "string"
#include <vector>
using namespace std;

pair<int, int> expandAroundCenter(const string& s, int left, int right){
    while(left >=0 && right < s.size() && s[left] == s[right]){
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

string longestPalindrome(string s){
    int n = s.size();
    if(n < 2) return s;
    int start = 0,  end = 0;
    for(int i = 0; i < n; ++i){
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);

        if(right1 - left1 > end - start){
            start = left1;
            end = right1;
        }
        if(right2- left2 > end - start){
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1 );
}


// dp
// dp[i][j] 表示s[i][j] 为true
//dp[i][j] = dp[i+1][j-1] if s[i] == s[j]

    string longestPalindrome_dp(string s){
    int n = s.size();
    if(n < 2) return s;
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    int begin = 0;
    int maxLen = 0;

    for(int L = 2; L <= n; L++){

        for(int i = 0; i < n; ++i){
            //j - i + 1 = L
            int j = L - 1 + i;
            if(j >= n){
                break;
            }
            if(s[i] != s[j]){
                dp[i][j] = false;
            }else{
                if(j - i < 3){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j] && j - i + 1 > maxLen){
                begin = i;
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return s.substr(begin, maxLen);
    }

#endif //ALGORITHM_L5_LONGESTPALINDROME_H
