class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> mystack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '\('){
                mystack.push(s[i]);
            } else if(s[i] == '\{'){
                mystack.push(s[i]);
            } else if(s[i] == '\['){
                mystack.push(s[i]);
            } else if(s[i] == '\)' && !mystack.empty() && mystack.top() == '\('){
                mystack.pop();
            } else if(s[i] == '\}' && !mystack.empty() && mystack.top() == '\{'){
                mystack.pop();
            } else if(s[i] == '\]' && !mystack.empty() && mystack.top() == '\['){
                mystack.pop();
            } else{
                return false;
            }
        }
        return mystack.empty();
    }
};

/* NOTES

This problem was fairly simple since I just had to think about it the way
I did in my automata theory class since every time you saw a ( there had to be
a ) afterwards.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 8.6 MB, less than 19.93% of C++ online submissions for Valid Parentheses.

*/
