//
// Created by Ste7an on 2022/7/16.
//

#ifndef ALGORITHM_L20_ISVALID_H
#define ALGORITHM_L20_ISVALID_H
//有效的括号

#include "string"
#include "unordered_map"
#include "stack"
using namespace std;

//输入：s = "()[]{}"
//输出：true
bool isValid(string& s){
    int n = s.size();
    if(n % 2) return false;
    unordered_map<char ,char> dict{
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    stack<char> stk;
    for(auto& ch : s){
        if(dict.count(ch)){
            if(stk.empty() || dict[ch] != stk.top()){
                return false;
            }else{
                stk.pop();
            }
        }else{
            stk.push(ch);
        }
    }
    return stk.empty();

}
#endif //ALGORITHM_L20_ISVALID_H
