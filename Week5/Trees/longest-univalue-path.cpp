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
    int longestHelper(TreeNode* root, int& uni){
        int uniL = 0;
        int uniR = 0;
        bool sameL = false;
        bool sameR = false;
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        }
        if(root->left != nullptr){
            if(root->left->val == root->val){
                uniL = 1 + longestHelper(root->left, uni);
                sameL = true;
            } else{
                uniL = longestHelper(root->left, uni);
            }
        }
        if(root->right != nullptr){
            if(root->right->val == root->val){
                uniR = 1 + longestHelper(root->right, uni);
                sameR = true;
            } else{
                uniR = longestHelper(root->right, uni);
            }
        }
        if(sameL && sameR){
            uni = max(uni, uniL + uniR);
            return max(uniL, uniR);
        } else if(sameL){
            uni = max(uni, uniL);
            return uniL;
        } else if(sameR){
            uni = max(uni, uniR);
            return uniR;
        } else{
            return 0;
        }

    }
    int longestUnivaluePath(TreeNode* root) {
        int uni = 0;
        longestHelper(root, uni);
        return uni;
    }
};

/* NOTES

This problem was very similar to the previous one, all I had to add was making
sure that I only added to the diameter if the branch had the same value as the
current node

Runtime: 116 ms, faster than 96.25% of C++ online submissions for Longest Univalue Path.
Memory Usage: 49.7 MB, less than 62.50% of C++ online submissions for Longest Univalue Path.

*/
