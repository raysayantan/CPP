/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathUtil(root, res);
        
        return res;
    }
    
    int maxPathUtil(TreeNode* root, int &res){
        int maxSingle = INT_MIN;
        int maxTill = INT_MIN;
        int left = INT_MIN, right = INT_MIN;
        
        if(root == NULL) return 0;
        left = maxPathUtil(root->left, res);
        right = maxPathUtil(root->right, res);
        
        maxSingle = maxVal(maxVal(left,right) + root->val, root->val);
        maxTill = maxVal(maxSingle, left + right + root->val);
        
        res = maxVal(res, maxTill);
        return maxSingle;
    }
    
    int maxVal(int a, int b){
        return (a > b)?a:b;
    }
};
