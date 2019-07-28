/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/* NOTES

This problem was fairly easy once I wrote down what things I needed to keep
track of each iteration.

Runtime: 8 ms, faster than 83.73% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.2 MB, less than 43.76% of C++ online submissions for Reverse Linked List.

*/

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        //if head or next is NULL then we reached the tail / the new head
        if(head == NULL || head->next == NULL) return head;
        //otherwise make the next of the next point to the current
        //but before doing that I need to reverse the rest of the list
        ListNode* curr = reverseList(head->next);
        head->next->next = head;
        //to avoid a cycle the next of head must be null
        //otherwise the second node will point to the first and the first back to the second
        head->next = NULL;
        return curr;
    }
};

/* NOTES

This is a recursive solution, it was hard to come up with a method but after
watching videos and reading about it I was able to understand it. I wrote the
reasoning as comments so I can understand better.

*/
