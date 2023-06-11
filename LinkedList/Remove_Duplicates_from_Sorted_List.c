class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp != NULL && temp->next !=NULL)
        {
            prev = temp->next;
            if(temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
                delete prev;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};
