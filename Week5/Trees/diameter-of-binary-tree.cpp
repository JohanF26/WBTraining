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
    int diameterHelper(TreeNode* root, int& diam){
        int dimL = 0;
        int dimR = 0;
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        }
        if(root->left != nullptr){
            dimL = 1 + diameterHelper(root->left, diam);
        }
        if(root->right != nullptr){
            dimR = 1 + diameterHelper(root->right, diam);
        }
        diam = max(diam, dimL + dimR);
        return max(dimL, dimR);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        diameterHelper(root, diam);
        return diam;
    }
};

/* NOTES

This problem was a bit tricky to think about but once you consider the edge cases
it becomes clear that you need to keep track of the longest branch as well as
the longest diameter encountered so far

Runtime: 12 ms, faster than 75.39% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 19.7 MB, less than 69.03% of C++ online submissions for Diameter of Binary Tree.

*/
