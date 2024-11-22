class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head; 
            node = node->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(next, k);
        return prev;
    }
};
