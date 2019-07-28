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
    void getLeaves(TreeNode* root, vector<int>& ret){
        if(root == nullptr) return;
        if(root->left != nullptr){
            getLeaves(root->left, ret);
            if(root->right != nullptr){
                getLeaves(root->right, ret);
            }
        } else if(root->right != nullptr){
            getLeaves(root->right, ret);
        } else{
            ret.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1;
        vector<int> ret2;
        getLeaves(root1, ret1);
        getLeaves(root2, ret2);
        return ret1 == ret2;
    }
};

/* NOTES

This problem was also fairly easy, I forgot that after searching the left branch
I also needed to search the right branch so it did not work at first. But once I
saw that only the left was being added to the vector I noticed I only checked the
right branch if the left was null.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Leaf-Similar Trees.
Memory Usage: 14.3 MB, less than 26.07% of C++ online submissions for Leaf-Similar Trees.

*/
