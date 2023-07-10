class Solution {
private:
void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
{
	if (curr == NULL)
	{
		head = prev;
		return;
	}
	reverse(head, curr->next, prev);
	curr->next = prev;
}
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
    
        // take 3 pointer : curre prev and next
	      // initialize it with 
	      // curr = head
	      // prev = null
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;

        // sol 2 : this needs to be checked as leetcode says time out 
        /*ListNode* temp = head;
        std::stack<ListNode*> stack_s;
        while(head) {
            stack_s.push(temp);
        }
        //auto itr = stack_s.begin();

        ListNode* temp1 = NULL;
        while(!stack_s.empty()) {
            ListNode* temp2 = stack_s.top();
            temp1->next = temp2;
            temp1 = temp1->next;
            stack_s.pop();
        }
        return temp1->next;*/
	/*
 	//sol-3 : recursive approach
  	ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
 	*/
     }
};
