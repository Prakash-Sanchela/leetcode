// Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        ListNode *fast = head, *slow = head;
        while(n--) 
        {
            fast = fast->next;
        }  
        if (!fast)
            return head->next;
        while(fast->next) 
        {
            fast = fast->next; 
            slow = slow->next;
        }
        slow->next = slow->next->next; 
        return head;
    }
};