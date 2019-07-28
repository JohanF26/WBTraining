class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        if(!s2.empty()){
            front = s2.top();
        }
        return temp;
    }

    /** Get the front element. */
    int peek() {
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/* NOTES

This problem was very similar to the previous one, I just had to think the opposite
way as the last one. After that it was fairly simple.

Runtime: 4 ms, faster than 66.03% of C++ online submissions for Implement Queue using Stacks.
Memory Usage: 8.8 MB, less than 52.74% of C++ online submissions for Implement Queue using Stacks.

*/
