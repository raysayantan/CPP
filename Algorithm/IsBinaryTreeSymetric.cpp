/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        return IsMirror(root,root);
    }
    
    bool IsMirror(TreeNode *root1, TreeNode *root2){
        //if both are empty the return true
        if(root1 == NULL && root2 == NULL) return true;
        
        //if root data are same, then check left subtree of first and right subtree of second
        // and right subtree of first and left subtree of second must be same
        if(root1 && root2 && root1->val == root2->val){
            return(IsMirror(root1->left, root2->right) &&
                  IsMirror(root1->right, root2->left));
        }
        
        return false;
    }
};
