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
    int findBottomLeftValue(TreeNode* root) {
        int left;
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);

        while(!nodeQ.empty()){
            TreeNode* r = nodeQ.front();
            nodeQ.pop();
            //first analyze the right so the last value used is the leftmost
            if(r->right != nullptr){
                if(r->right->left == nullptr && r->right->right == nullptr){
                    left = r->right->val;
                } else{
                    nodeQ.push(r->right);
                }
            }
            if(r->left != nullptr){
                if(r->left->left == nullptr && r->left->right == nullptr){
                    left = r->left->val;
                } else{
                    nodeQ.push(r->left);
                }
            }
        }

        return left;
    }
};

/* NOTES

This problem was not so hard once I realized that the best approach was to use
BFS. The first restriction was to find the bottom-most value, and if there were
more than 1 then return the leftmost. The way I solved this was by processing the
nodes with BFS from right to left so the last processed node was the leftmost at
the lowest level.

Runtime: 16 ms, faster than 71.03% of C++ online submissions for Find Bottom Left Tree Value.
Memory Usage: 20.7 MB, less than 70.76% of C++ online submissions for Find Bottom Left Tree Value.

*/
