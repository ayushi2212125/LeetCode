/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
ListNode* getStartingNode(ListNode* head){
    if(head == NULL)
    return NULL;
    ListNode* intersection = detectCycle(head);
    ListNode* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

public:
    ListNode *detectCycle(ListNode *head) {
    if(head == NULL)
    return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
    }
}; */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // cycle detected
                // Step 2: Find start of cycle
                ListNode* ptr1 = head;
                ListNode* ptr2 = slow;

                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1; // start node of cycle
            }
        }
        return NULL; // no cycle
    }
};