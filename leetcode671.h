//
// Created by Ste7an on 2022/7/12.
//

#ifndef ALGORITHM_LEETCODE671_H
#define ALGORITHM_LEETCODE671_H

//MagicDictionary

#include <string>
#include <vector>
#include <functional>
using namespace std;

struct Tire{
    vector<Tire*> child;
    bool isEnd;

    Tire() :child(26), isEnd(false){}
};

class MagicDictionary{

public:
    MagicDictionary(){
        root = new Tire();
    }

    void build(vector<string> words){
        for(auto& w : words){
            Tire* node = root;
            for(auto& ch : w){
                ch -= 'a';
                if(!node->child[ch]){
                    node->child[ch] = new Tire();
                }
                node = node->child[ch];
            }
            node->isEnd = true;
        }
    }

    bool search(string w){
        function<bool(Tire*, int, bool)> dfs = [&](Tire* cur, int pos, bool modified){
            if(pos == w.size()) return modified && cur->isEnd;
            int idx = w[pos] - 'a';
            if(cur->child[idx]){
                if(dfs(cur->child[idx], pos + 1, modified)){
                    return true;
                }
            }
            if(!modified){
                for(int i = 0; i < 26; ++i){
                    if(i != idx && cur->child[i]){
                        if(dfs(cur->child[i], pos + 1, true)) return true;
                    }
                }
            }
            return false;
        };

        return dfs(root, 0, false);
    }

private:
    Tire* root;
};



#endif //ALGORITHM_LEETCODE671_H
