class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Split list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // Step 2: Sort both halves
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge sorted halves
        return mergeTwoLists(left, right);
    }

    // Function to find mid (end of first half)
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if (l1 != NULL) temp->next = l1;
        if (l2 != NULL) temp->next = l2;

        return dummy.next;
    }
};
