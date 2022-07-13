//
// Created by Ste7an on 2022/7/7.
//


#include <iostream>
#include "leetcode208.h"
#include "leetcode671.h"
#include "leetcode394.h"
using namespace std;


int main(){
    MagicDictionary dict;
    vector<string> words{"hello", "leetcode"};
    string s = "3[a]2[bc]";
    string ret = decodeString(s);
    for(auto& c : ret){
        cout<< c<<" " ;
    }
}
