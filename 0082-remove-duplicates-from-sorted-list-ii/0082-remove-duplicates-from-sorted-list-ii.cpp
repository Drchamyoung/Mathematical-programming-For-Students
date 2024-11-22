class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        int prev_value = -101;
        int count = 1;

        while(curr != nullptr){
            bool is_duplicate = false;
            while (curr->next != nullptr && curr->val == curr->next->val){
                is_duplicate = true;
                curr = curr->next;
            }
            
            if (is_duplicate) {
               
                prev->next = curr->next;
            } else {
              
                prev = prev->next;
            }
            
            curr = curr->next; 
        }

        return dummy->next;

    }
};