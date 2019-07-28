class MyStack {
private:
    queue<int> stackSim;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        stackSim.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = stackSim.back();
        queue<int> stack2;
        while(stackSim.size() > 1){
            stack2.push(stackSim.front());
            stackSim.pop();
        }
        stackSim = stack2;
        return temp;
    }

    /** Get the top element. */
    int top() {
        return stackSim.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return stackSim.empty();
    }
};

/* NOTES

This problem was fairly simple once I accepted the fact that there was not a faster
way to pop than O(N) and that I would need to push all the elements but the last
one to a new stack and then copy it over.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 8.9 MB, less than 29.34% of C++ online submissions for Implement Stack using Queues.

*/
