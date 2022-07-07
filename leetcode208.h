//
// Created by Ste7an on 2022/7/7.
//

#ifndef ALGORITHM_LEETCODE208_H
#define ALGORITHM_LEETCODE208_H
// 字典树(Trie)用于判断字符串是否存在或者是否具有某种字符串前缀。
#include <iostream>
#include <vector>
#include <string>



using namespace std;

class Trie{


public:
    Trie(): child(26), isEnd(false){}

    void insert(string& word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(!node->child[c]){
                node->child[c] = new Trie();
            }
            node = node->child[c];
        }
        node->isEnd = true;
    }

    bool search(string& word){
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startWith(string prefix){
        return this->searchPrefix(prefix) != nullptr;
    }

private:
    Trie* searchPrefix(string& prefix){
        Trie* node = this;
        for(char& ch : prefix){
            if(node->child[ch] == nullptr){
                return nullptr;
            }
            node = node->child[ch];
        }
        return node;
    }

private:
    vector<Trie*> child;
    bool isEnd;
};


#endif //ALGORITHM_LEETCODE208_H
