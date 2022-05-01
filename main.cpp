#include <iostream>
#include <vector>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

//bubble sort
void bubbleSort(std::vector<int>& nums) {

    auto len = nums.size();
    for(int i = 0; i < len; ++i){
       for(int j = 0; j < len - i - 1; ++j){
           if(nums[j] > nums[j + 1])
               std::swap(nums[j], nums[j + 1]);
       }
    }
    cout << "bubble sort: " << endl;
    for(auto x : nums){
        cout << x << " ";
    }
    cout << endl << endl;
}

//selection sort
void selectionSort(vector<int>& nums){
    int minIndex = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i){
        minIndex = i;
        for(int j = i + 1; j < len; ++j){
            if(nums[j] < nums[minIndex])
                minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}


//insertion sort a
void insertionSort_a(vector<int>& nums){
    for(int i = 1; i < nums.size(); ++i){
        for(int j = i -1; j >= 0 && nums[j] > nums[j + 1]; --j){
            swap(nums[j], nums[j + 1]);
        }
    }
}

//insertion sort b
void insertionSort_b(vector<int>& nums){
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] < nums[i - 1]){
            int j = i - 1;
            int x = nums[i];
            while(j >= 0 && x < nums[j]){ //当前位置数比前一位置树小的时候，
                nums[j + 1] = nums[j];    //把前一位置数向后移动
                j--;                      // 继续往前看
            }
            nums[j + 1] = x;       //第i元素大于第i-1元素 插入到i位置。
        }
    }
}

//quicksort
void quicksort(vector<int>& nums, int begin, int end ){
    if (begin >= end) return;//结束标志；
    int first = begin, last = end;
    int key = nums[first]; //把第一个数当作基准
    while(first < last){
        //从后往前看 把 比key大的数移动到前面
        while(first < last && nums[last] >= key)
            last--;
        if(first < last)
            nums[first++] = nums[last];
        //从前往后看 把比key大的数 移动到后面
        while(first < last && nums[first] <= key)
            first++;
        if(first < last)
            nums[last--] = nums[first];
    }
    nums[first] = key; //第一遍 排序结束 把数组分为 以key为分界点的两个部分 first为分界点下标
    cout << "quick sort: " << endl;
    cout << begin << " " << end << " " << key << endl;
    for (auto a : nums)
        cout << a << " ";
    cout << endl << endl;
    quicksort(nums, begin, first - 1);
    quicksort(nums, first + 1, end);

}

//merge_sort
void __merge_sort(vector<int>& data, vector<int>& dataTmp, int low, int high ){
    if(low >= high) return;
    int mid = low + ((high - low) >> 1 ) ;
    int low1 = low, end1 = mid;
    int low2 = mid + 1,  end2 = high;
    __merge_sort(data, dataTmp, low1, end1);
    __merge_sort(data, dataTmp, low2, end2);
    int index = low1;
    while (low1 <= end1 && low2 <= end2){
        dataTmp[index++] = data[low1] < data[low2] ? data[low1++] : data[low2++];
    }
    while(low1 <= end1){
        dataTmp[index++] = data[low1++];
    }
    while(low2 <= end2){
        dataTmp[index++] = data[low2++];
    }
    for(index = low; index <= high; ++index){
        data[index] = dataTmp[index];
    }
}

void merge_sort(vector<int>& data){
    vector<int> dataTmp(data.size(), 0);
    __merge_sort(data, dataTmp, 0, data.size()-1);
    cout << "merge sort: " << endl;
    for(auto x : data){
        cout<< x << " ";
    }
    cout << endl << endl;
}

//heap sort
void heapfiy(vector<int>& nums, int n, int i){
    int l = 2*i + 1;  //当前节点left child
    while(l < n){
        int largest = (l + 1 < n) && (nums[l + 1] > nums[l]) ? l + 1 : l; //左右孩子中最大的一个
        largest = nums[largest] > nums[i] ? largest : i;

        if (largest == i)
            break;
        std::swap(nums[largest], nums[i]);
        i = largest;
        l = 2 * i + 1;
    }
}

void build_heap(vector<int>& nums){
    int temp = (nums.size()  - 2  ) / 2;
    for(int i = temp; i >=0; --i ){
        heapfiy(nums, nums.size(), i);
    }
}

void heap_sort(vector<int>& nums){
    build_heap(nums);
    cout << "build heap : " << endl;
    for(auto x : nums){
        cout << x << " ";
    }
    cout << endl;
    int n = nums.size() ;
    for(int i = 0; i < n; i++){
        std::swap(nums.front(), nums[n - i -1]);
        heapfiy(nums, n - i - 1, 0);
    }
    cout << "heap sort: " << endl;
    for(auto x : nums){
        cout << x << " ";
    }
}

//radix sort
int maxbit(int data[], int n)
{
    int maxData = data[0];
    for (int i = 1; i < n; ++i) {
       if(maxData < data[i])
           maxData = data[i];
    }
    int d = 1;
    while(maxData != 0){
        d++;
        maxData /= 10;
    }
    return d;
}

void radixSort(int data[], int n){
    int d = maxbit(data, n);
    int *temp = new int[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for( i = 1; i <= d; ++i){
        for ( j = 0; j < 10; ++j) {
            count[j] = 0;
        }

        for(j = 0; j < n; ++j){
            k = (data[j] / radix) % 10;
            count[k]++;
        }

        for(j = 1; j < 10; ++j){
            count[j] = count[j - 1] + count[j];
        }

        for(j = n - 1; j>=0; --j){
            k = (count[j] / radix) % 10;
            temp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; ++j){
            data[j] = temp[j];
        }

        radix = radix * 10;
    }
    delete[] temp;
    delete[] count;
}


//**********************************binary tree***************************************************
//binary tree
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





//************************************linked List***************************************************
//singly-linked list
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

 ListNode* listInit(int a, int b, int c, int d, int f, int g){
    ListNode* head = new ListNode(a);
    ListNode* head1 = new ListNode(b);
    ListNode* head2 = new ListNode(c);
    ListNode* head3 = new ListNode(d);
    ListNode* head4 = new ListNode(f);
     ListNode* head5 = new ListNode(g);
    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = nullptr;

    return head;
}

ListNode* midNode(ListNode *head)
{
     if(!head)
         return head;
     ListNode* slow = head, *fast = head->next;
     while(fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
     }
     return slow;
}
void printList(ListNode* head){
    while(head != nullptr)
    {
        cout << head->val << " ";

        head = head->next;
    }
    cout << endl;
}
//reverse list
ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr, *next ;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* reverseList_headInsert(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode dummy = ListNode(0);
    ListNode *pre = &(dummy);
    pre->next = head;
    ListNode* curr = head->next;
    head->next = nullptr;
    ListNode* temp;
    while(curr != nullptr){
        temp = curr;
        curr = curr->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    return dummy.next;
}

ListNode* recur_reverseList(ListNode* head, ListNode* prev = nullptr){
    if (!head){
        return prev;
    }
    ListNode *next = head->next;
    head->next = prev;
    return recur_reverseList(next, head );
}

ListNode* mergeTwolists(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(0), *node = dummy;
    while(l1 && l2){
        if (l1->val <= l2->val){
           node->next = l1;
           l1 = l1->next;
        } else{
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    node->next = l1? l1:l2;
    return dummy->next;
}

ListNode* recur_mergeTwolists(ListNode* l1, ListNode* l2){
    //递归黑盒告诉我两个链表合并之后的头节点
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    if(l1->val > l2->val)
    {
        l2->next = recur_mergeTwolists(l1, l2->next);
        return l2;
    }
    l1->next = recur_mergeTwolists(l1->next, l2);
    return l1;
}

//is Palindrome
bool isPalindrome(ListNode* head)
{
     if(!head || !head->next)
     {
         return true;
     }
     ListNode* slow = head, *fast = head;
     while(fast->next && fast->next->next)
     {
         slow = slow->next;
         fast = fast->next->next;
     }
     slow->next = reverseList_headInsert(slow->next);
     slow = slow->next;
     printList(slow);
     printList(head);
     while(slow)
     {
         if(slow->val != head->val)
             return false;
         slow = slow->next;
         head = head->next;
     }
     cout << "Yes ,It is" << endl;
     return true;
}


//sort list
ListNode* recur_sortList(ListNode* head)
{
     if(!head || !head->next)
         return head;

     ListNode* midnode = midNode(head);
     ListNode* rightNode = midnode->next;
     midnode->next = nullptr;
     return mergeTwolists(recur_sortList(head), recur_sortList(rightNode));
}

ListNode* sortList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    //遍历链表得到链表长度
    int length = 0;
    ListNode* node = head;
    while(node)
    {
        length++;
        node = node->next;
    }

    ListNode* dummy = new ListNode(0, head);
    for(int subLen = 1; subLen < length; subLen <<= 1)
    {
        ListNode* prev = dummy, *curr = dummy->next;
        while(curr)
        {
            ListNode* head1 = curr;
            for(int i = 1; i < subLen && curr->next; i++)
            {
                curr = curr->next;
            }
            ListNode* head2 = curr->next;
            curr->next = nullptr;
            curr = head2;

            for(int i = 1; i < subLen && curr && curr->next; i++)
            {
                curr = curr->next;
            }

            ListNode* next = nullptr;
            if(curr)
            {
                next = curr->next;
                curr->next = nullptr;
            }

            ListNode* merged = mergeTwolists(head1, head2);
            prev->next = merged;
            while(prev->next)
            {
                prev = prev->next;
            }

            curr = next;
        }
    }
    return dummy->next;
}

//oddEven List
ListNode* oddEvenList(ListNode* head)
{
     if(!head) return head;
     ListNode* odd = head;
     ListNode* evenHead = head->next;
     ListNode* even = evenHead;
     while(even && even->next)
     {
         odd->next = even->next;
         odd = odd->next;
         even->next = odd->next;
         even = even->next;
     }

     odd->next = evenHead;
     return head;
}


//remove NthFromEnd

ListNode* removeNthFromEnd(ListNode* head, int n)
{
     ListNode* dummy = new ListNode(0, head);
     ListNode* first = head;
     ListNode* second = dummy;

     for(int i = 0; i < n; ++i)
     {
         first = first->next;
     }
     while(first)
     {
         first = first->next;
         second = second->next;
     }

     second->next = second->next->next;

     ListNode* ans = dummy->next;
     delete dummy;
     return ans;
}

//deleteDuplicates
ListNode* deleteDuplicates(ListNode* head)
{
     if (!head) return head;

     ListNode* dummy = new ListNode(0,head);
     ListNode* pre = dummy;
     pre = pre->next;
     while(pre->next)
     {
         if(pre->val == pre->next->val)
         {
             pre->next = pre->next->next;
         }else{
             pre = pre->next;
         }
     }

     return dummy->next;

}

//hasCycle?
bool hasCycle(ListNode* head)
{
     if (!head ) return true;

     ListNode* fast = head->next->next;
     ListNode* slow = head->next;

     while(fast != slow)
     {
         slow = slow->next;
         if(!fast || !fast->next ) return false;
         fast = fast->next->next;

     }
     return true;
}

//detectCycle
ListNode* detectCycle(ListNode* head)
{
    if (!head || !head->next) return nullptr;

    ListNode* fast = head->next->next;
    ListNode* slow = head->next;

    while(fast != slow)
    {
        slow = slow->next;
        if(!fast || !fast->next ) return nullptr;
        fast = fast->next->next;
    }

    ListNode* ptr = head;
    while(ptr != slow)
    {
        ptr = ptr->next;
        slow = slow->next;
    }
    return ptr;
}

//swapPairs
ListNode* swapPairs(ListNode* head)
{
     ListNode* cur = head , *s;

     if(cur && cur->next)
     {
         s = cur->next;
         cur->next = s->next;
         s->next = cur;
         head = s;
         while(cur->next && cur->next->next)
         {
             s = cur->next->next;
             cur->next->next = s->next;
             s->next = cur->next;
             cur->next = s;
             cur = s->next;
         }
     }

     return head;
}

int main(){
    ListNode* head = listInit(1,2,3, 3, 2,1);
//    printList(head);
//    head = reverseList_headInsert(head);
//    ListNode* midnode = midNode(head);
    printList(head);
    head = swapPairs(head);
//    printList(reversedMid);
//    isPalindrome(head);
//    head = deleteDuplicates(head);
    printList(head);









    //sort
//    vector<int> nums = {4 , 10 , 3 ,0, 5, 12};
//    quicksort(nums,0, nums.size() - 1);
//    merge_sort(nums);
//    bubbleSort(nums);
//    heap_sort(nums);



}

