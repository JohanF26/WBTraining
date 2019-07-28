/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        //head and odd will be head and tail of odd list
        ListNode* odd = head;
        //ehead and even will be head and tail of even list
        ListNode* ehead = head->next;
        ListNode* even = ehead;
        while(odd->next != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = ehead;

        return head;
    }
};

/* NOTES

My first solution was a bit messy and harder to understand than it should be, however
the thought process I used was correct. Below is my first version.

Runtime: 12 ms, faster than 98.61% of C++ online submissions for Odd Even Linked List.
Memory Usage: 9.5 MB, less than 79.40% of C++ online submissions for Odd Even Linked List.

*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* snd = head->next;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(next != NULL){
            curr->next = next->next;
            if(next->next != NULL) next->next = next->next->next;
            if(curr->next != NULL) curr = curr->next;
            next = curr->next;
        }
        curr->next = snd;
        return head;
    }
};
