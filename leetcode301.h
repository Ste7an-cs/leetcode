//
// Created by Ste7an on 2022/7/12.
// removeInvalidParentheses

#ifndef ALGORITHM_LEETCODE301_H
#define ALGORITHM_LEETCODE301_H

#include <string>
#include <vector>

using namespace std;

class removeInvalidParentheses_{
public:
    vector<string> ans;
    bool isValid(const string& str){
        int cnt = 0;
        for(const auto& c : str){
            if(c == '('){
                cnt++;
            }else if( c == ')'){
                cnt--;
                if(cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
    void dfs(int start, int l ,int r, string str){
        if(l == 0 && r == 0){
            if(isValid(str)){
                ans.push_back(str);
            }
            return;
        }
        for(int i = start; i < str.size(); ++i){
            if(i != start && str[i] == str[i - 1]) continue;
            if(l + r > str.size() - 1) return;
            if(l > 0 && str[i] == '('){
                dfs(i, l - 1, r, str.substr(0, i) + str.substr(i + 1));
            }
            if(r > 0 && str[i] == ')'){
                dfs(i, l, r - 1, str.substr(0, i) + str.substr(i + 1));
            }
        }
    }
    vector<string> removeInvalidParentheses(string s){
        int l = 0, r = 0;
        for(auto& c : s){
            if( c == '('){
                l++;
            }else if( c == ')'){
                if(l == 0) {
                    r++;
                }else l--;
            }
        }
        dfs(0, l, r, s);
        return ans;
    }

};


#endif //ALGORITHM_LEETCODE301_H
