//
// Created by Ste7an on 2022/7/14.
//

#ifndef ALGORITHM_ADDTWONUMBERS_H
#define ALGORITHM_ADDTWONUMBERS_H
//add Two numbers

//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.

struct ListNode{
    int val;

    ListNode* next;

    ListNode(int value) :val(value), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(0);
    ListNode* node = dummy;
    int carry = 0;
    while(l1 || l2){
        int x1 = l1? l1->val : 0;
        int x2 = l2? l2->val : 0;
        int sum = x1 + x2 + carry;

        node->next = new ListNode(sum % 10);
        node = node->next;

        carry = sum / 10;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(carry > 0) node->next = new ListNode(carry);
    return dummy->next;


}

#endif //ALGORITHM_ADDTWONUMBERS_H
