//
// Created by Ste7an on 2022/7/12.
//

#ifndef ALGORITHM_LEETCODE621_H
#define ALGORITHM_LEETCODE621_H
// 任务调度器

#include <unordered_map>
#include <vector>

using namespace std;

class Task{
    int leastInterval(vector<char> tasks, int n ){
        unordered_map<char, int> freq;
        for(auto& c : tasks){
            ++freq[c];
        }

        vector<int> nextValid, rest;
        int m = freq.size();
        int time = 0;
        for(int i = 0; i < tasks.size(); i++ ){
            int minNextValid = INT_MAX;
            ++time;
            for(int j = 0; j < m; j++){
                if(rest[j]){
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid);
            int best = -1;
            for(int j = 0; j < m; j++){
                if(rest[j] && nextValid[j] <= time){
                    if(best == -1 || rest[j] > rest[best]){
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }
        return time;
    }
};

#endif //ALGORITHM_LEETCODE621_H
