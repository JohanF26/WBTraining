/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void postOrderHelper(Node* root, vector<int>& ret){
        if(root != nullptr){
            for(auto it: root->children){
                postOrderHelper(it, ret);
            }
            ret.push_back(root->val);
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> ret;
        postOrderHelper(root, ret);
        return ret;
    }
};

/* NOTES

I have been reading about trees and graphs recently so solving this problem
was quite straightforward.

Runtime: 132 ms, faster than 99.62% of C++ online submissions for N-ary Tree Postorder Traversal.
Memory Usage: 32.4 MB, less than 77.84% of C++ online submissions for N-ary Tree Postorder Traversal.

*/
