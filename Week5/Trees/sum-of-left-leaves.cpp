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
    void sumHelper(TreeNode* root, int& acc){
        if(root == nullptr) return;
        if(root->left != nullptr){
            sumHelper(root->left, acc);
            if(root->right != nullptr &&
               (root->right->left != nullptr || root->right->right != nullptr)){
                //only check the right branch if it is not a leaf node
                sumHelper(root->right, acc);
            }
        } else if(root->right != nullptr){
            if(root->right->left != nullptr || root->right->right != nullptr){
            //only check the right branch if it is not a leaf node
                sumHelper(root->right, acc);
            }
        } else{
            acc += root->val;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int acc = 0;
        if(root != nullptr && (root->left != nullptr || root->right != nullptr)){
            sumHelper(root, acc);
        }
        return acc;
    }
};

/* NOTES

This problem was a bit tricky since you needed to take into account the cases
where the right branch has a left branch in any of its subsequent branches. I
also had to make sure that I was not adding the root node just because it does not
have left and right branches, which I took care of before calling the helper function.

Runtime: 4 ms, faster than 87.12% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.2 MB, less than 98.82% of C++ online submissions for Sum of Left Leaves.

*/
