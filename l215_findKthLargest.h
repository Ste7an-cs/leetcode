//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L215_FINDKTHLARGEST_H
#define ALGORITHM_L215_FINDKTHLARGEST_H
#include "vector"
using namespace std;

void maxHeapify(vector<int>& nums, int i, int heapSize){
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;
    if(l < heapSize && nums[l] > nums[largest]){
        largest = l;
    }
    if(r < heapSize && nums[r] > nums[largest]){
        largest = r;
    }
    if(largest != i){
        swap(nums[i], nums[largest]);
        maxHeapify(nums, largest, heapSize);
    }
}
void buildHeap(vector<int>& a, int heapSize){
    for(int i = heapSize / 2; i >=0; i--){
        maxHeapify(a, i, heapSize);
    }
}

int findKthLargest(vector<int> nums, int k){
    int heapSize = nums.size();
    buildHeap(nums, heapSize);
    for(int i = nums.size() - 1; i >= nums.size() - k + 1; i--){
        swap(nums[0], nums[i]);
        --heapSize;
        maxHeapify(nums, 0, heapSize);
    }
    return nums[0];
}

#endif //ALGORITHM_L215_FINDKTHLARGEST_H
