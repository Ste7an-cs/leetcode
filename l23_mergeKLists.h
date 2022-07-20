//
// Created by Ste7an on 2022/7/20.
//

#ifndef ALGORITHM_L23_MERGEKLISTS_H
#define ALGORITHM_L23_MERGEKLISTS_H
//合并K个升序链表
#include "vector"
#include "queue"
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

struct status{
    int val;
    ListNode* node;
    status(int x, ListNode* cur) : val(x), node(cur) {}
    bool operator <(const status &rhs ) const {
        return val > rhs.val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<status> q;
    for(auto& list : lists){
        if(list) q.push({list->val, list});
    }
    ListNode head, *cur = &head;
    while(!q.empty()){
        auto node = q.top().node; q.pop();
        cur->next = node;
        cur = cur->next;
        if(node->next) q.push({node->next->val, node->next});
    }
    return head.next;
}
#endif //ALGORITHM_L23_MERGEKLISTS_H
