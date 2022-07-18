//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L124_MAXPATHSUM_H
#define ALGORITHM_L124_MAXPATHSUM_H
//二叉树的最大路径和
#include "algorithm"
using namespace std;

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxSum = INT_MIN;
int dfs(TreeNode* root){
    if(!root) return 0;
    int leftGain = max(dfs(root->left), 0);
    int rightGain = max(dfs(root->right), 0);

    //当前节点的路径和
    int priceNewPath = leftGain + rightGain + root->val;
    maxSum = max(maxSum, priceNewPath);

    //递归 求每个节点的最大贡献值。
    //返回值 为 当前节点的值 + 左右节点贡献值中的最大值
    return max(leftGain, rightGain) + root->val;
}

int maxPathSum(TreeNode* root){
    dfs(root);
    return maxSum;
}
#endif //ALGORITHM_L124_MAXPATHSUM_H
