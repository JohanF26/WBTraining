class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> mystack;
        mystack.push(0);

        for(int i = 0; i < S.size(); i++){
            if(S[i] == '\('){
                mystack.push(0);
            } else{
                int temp = mystack.top();
                mystack.pop();
                int temp2 = mystack.top();
                mystack.pop();
                mystack.push(max(1, 2*temp) + temp2);
            }
        }

        return mystack.top();
    }
};

/* NOTES

It was a bit difficult to start thinking about how to solve this but I realized
it would be wiser to use the stack to calculate the score. I decided to use 0
as a placeholder for a future score and to calculate the depth of the current char.
That way, whenever I saw a closing parentheses all I had to do was pop the top,
multiply by two, and add it to the score of the next level (the int at the top).
However, whenever I had () the score at the top would be 0 but the actual output
should be 1 so I used max to take care of that.

Runtime: 4 ms, faster than 66.67% of C++ online submissions for Score of Parentheses.
Memory Usage: 8.5 MB, less than 18.34% of C++ online submissions for Score of Parentheses.

*/
