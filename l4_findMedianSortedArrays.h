//
// Created by Ste7an on 2022/7/14.
//

#ifndef ALGORITHM_L4_FINDMEDIANSORTEDARRAYS_H
#define ALGORITHM_L4_FINDMEDIANSORTEDARRAYS_H
//寻找两个数组中的中位数
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
//分割两个数组
//A[0,i - 1] | A[i, m]
//B[0,j - 1] | B[j, n]
//max A(left) < min A(right)
//max B(left) < min B(right)
// i + j = m - i + n - j + 1
//在数组A中找到 最大的A【i - 1】 <= A[i]

#include "vector"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();
    int n = nums2.size();
    int left = 0;
    int right = m;
    int median1 = 0, median2 = 0;
    while(left <= right){
        int i = left + (right - left) /2;
        int j = (m + n + 1) /2 - i;

        int num1_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int num1_i = (i == m ? INT_MAX : nums1[i]);
        int num2_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int num2_j = (j == m ? INT_MAX : nums2[j]);
        if(num1_im1 <= num2_j){
            median1 = max(num1_im1, num2_jm1);
            median2 = min(num1_i, num2_j);
            left = i + 1;
        }else{
            right = i - 1;
        }
    }
    return (m + n) % 2 == 0 ? (median1 + median2) /2.0 : median1;



}





#endif //ALGORITHM_L4_FINDMEDIANSORTEDARRAYS_H
