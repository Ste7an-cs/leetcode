//
// Created by Ste7an on 2022/7/13.
//

#ifndef ALGORITHM_LEETCODE394_H
#define ALGORITHM_LEETCODE394_H


//字符串解码
//输入：s = "3[a]2[bc]"
//输出："aaabcbc"
#include <string>
#include "vector"

using namespace std;

string getDigits(string& s, int& ptr){
    string ret;
    while(isdigit(s[ptr])) ret.push_back(s[ptr++]);
    return ret;
}

string getString(vector<string>& str){
    string ret;
    for(auto& x : str){
        ret += x;
    }
    return ret;
}
string decodeString(string s){
    int n = s.size();
    int ptr = 0;
    vector<string> stk;
    while(ptr < n){
        char ch = s[ptr];
        if(isdigit(ch)){
            string digits = getDigits(s, ptr);
            stk.push_back(digits);
        }else if(isalpha(ch) || ch == '['){
            stk.push_back(string(1, s[ptr++]));
        }else{
            ++ptr;
            vector<string> sub;
            while(stk.back() != "[" ){
                sub.push_back(stk.back());
                stk.pop_back();
            }
            reverse(sub.begin(), sub.end());
            stk.pop_back();
            int rept = stoi(stk.back());
            stk.pop_back();
            string t, o =getString(sub);
            while(rept--)  t += o;
            stk.push_back(t);
        }

    }
    return getString(stk);
}

#endif //ALGORITHM_LEETCODE394_H
