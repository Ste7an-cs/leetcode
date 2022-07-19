//
// Created by Ste7an on 2022/7/19.
//

#ifndef ALGORITHM_L17_LETTERCOMBINATIONS_H
#define ALGORITHM_L17_LETTERCOMBINATIONS_H
//电话号码组合
// 回溯

#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

void dfs(unordered_map<char,string>& dict, string& combination, vector<string>& Combinations,int pos, string& digits){
    if(pos == digits.size()){
        Combinations.push_back(combination);
    }else{
        char digit = digits[pos];
        string letters = dict[digit];
        for(auto& letter : letters){
            combination.push_back(letter);
            dfs(dict, combination, Combinations, pos + 1, digits);
            combination.pop_back();
        }
    }
}
vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    int len = digits.size();

    string combination;
    unordered_map<char, string> dict = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> Combinations;

    dfs(dict, combination, Combinations, 0, digits);
    return Combinations;
}
#endif //ALGORITHM_L17_LETTERCOMBINATIONS_H
