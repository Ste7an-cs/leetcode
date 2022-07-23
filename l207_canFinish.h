//
// Created by Ste7an on 2022/7/20.
//

#ifndef ALGORITHM_L207_CANFINISH_H
#define ALGORITHM_L207_CANFINISH_H
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
//拓扑排序

#include "vector"
#include "queue"
using namespace std;

vector<vector<int>> adj; // 邻接表
vector<int> visited;
bool valid = true; // 是否存在环 ，不存拓扑排序

void dfs(int u){
    visited[u] = 1; //搜索中
    for(const auto& v : adj[u]){//所有 u 中 的所有顶点
        if(visited[v] == 0){ // 如果v 没有访问过 则访问v
            dfs(v);
            if(!valid){//v访问完之后 在访问过程中发现了 环
                return;
            }
        }else if(visited[v] == 1){ // v 正在访问中 ，发现了环
            valid = false;
        }
    }
    visited[u] = 2; // u 访问完成
}

bool canFinish_DFS(int numsCourses, vector<vector<int>> prerequisites){
    adj.resize(numsCourses);
    visited.resize(numsCourses);
    //建立邻接表
    for(const auto& info : prerequisites){
        adj[info[1]].push_back(info[0]);
    }
    for(int i = 0; i < numsCourses && valid; i++){//选择一个顶点开始搜索
        if(!visited[i]){
            dfs(i);
        }
    }
    return valid;
}

bool canFinish_BFS(int numCourses, vector<vector<int>> prerequisites){

    vector<vector<int>> edges(numCourses, vector<int>()); // 邻接表
    vector<int> inDegree(numCourses, 0), res;
    for(const auto& info : prerequisites){
        edges[info[1]].push_back(info[0]);
        ++inDegree[info[0]];
    }
    queue<int> q;

    //把所有入度为0的顶点放入队列
    for(int i = 0; i < inDegree.size(); i++){
        if(!inDegree[i]) q.push(i);
    }

    while(!q.empty()){
        //弹出队首元素 加入拓扑排序列表
        int u = q.front();
        res.push_back(u);
        q.pop();
        for(const auto& v : edges[u]){//所有跟u邻接的点v 入度 -1；
            --inDegree[v];
            if(!inDegree[v]){//如果v的入度为0， 加入队列
                q.push(v);
            }
        }
    }
    for(const auto& in : inDegree){// 如果还有节点 的 入度 不为 0 ， 则不存在 拓扑排序
        if(in){
            return false;
        }
    }
    return res.size() == numCourses;
}
#endif //ALGORITHM_L207_CANFINISH_H
