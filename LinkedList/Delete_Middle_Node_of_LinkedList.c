class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL)
            return head;
        int size = 0;
        // sol 1 : find the length of list and send the length/2th node. 
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        if (size == 1)
            return NULL;
        for (int index = 0; index < (size/2) ; index++)
        {
            prev = temp;;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        return head;
      
        // sol 2 could be to use 2 pointers, 1 fast pointer & 1 slow pointer
        // fast will move 2 jump at a time and slow will move 1 jump at a time. 
        // by the time fast will reach at the end of list slow will be at middle of list
        // delete the middle of list and return the head
    }
};
