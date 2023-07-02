/*Reorder List
You are given the head of a singly linked-list. 
Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/
 #include <deque>
class Solution {
public:
    void reorderList(ListNode* head) {
        std::deque<ListNode*>dq;
        
        ListNode* temp = head;
        while(temp){
            dq.push_back(temp);
            temp = temp->next;
            dq.back()->next = NULL;
        }
        dq.pop_front();
        bool check = 1;
        while(dq.size()!=0)
        {
            if (check) {
                head->next = dq.back();
                dq.pop_back();
            }
            else {
                head->next = dq.front();
                dq.pop_front();
            }
            head = head->next;
            check = !check;
        }
    }
};
