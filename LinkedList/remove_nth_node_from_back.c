// Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        // will use two pointers, fast will move n times
        // since fast moved n times then will move fast and slow 
        // pointers, once fast->next == NULL, update the slow with
        // slow->next->next.
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
