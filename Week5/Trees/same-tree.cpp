/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    void sameHelper(TreeNode* root, vector<int>& ret){
        if(root != nullptr){
            ret.push_back(root->val);
            sameHelper(root->left, ret);
            sameHelper(root->right, ret);
        } else{
            ret.push_back(-1);
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ret1;
        vector<int> ret2;
        sameHelper(p, ret1);
        sameHelper(q, ret2);
        return ret1 == ret2;
    }
};

/* NOTES

This problem was fairly easy but after solving it I discovered there is a much
simpler solution. For the two trees to be identical then the left branches must
be identical, the right branches must be identical, and their values must be the
same. This means I can call the function recursively on the branches. My current
solution does not work for negative numbers so below is my improved answer.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
Memory Usage: 9.5 MB, less than 99.77% of C++ online submissions for Same Tree.

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr) return p == q;
        return(p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
