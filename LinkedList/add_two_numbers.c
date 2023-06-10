// link : https://leetcode.com/problems/add-two-numbers/description/
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
      
        ListNode* l3 = new ListNode();
        l3->next = NULL;
        ListNode* ptr = l3;
        int carry = 0;
        while(l1 || l2 || carry)
        {   
            unsigned int sum = 0;
            if (l1 != NULL) {
                //sum = sum + l1->val;
                sum += l1->val; 
                l1=l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val; 
                l2=l2->next;
            }
            
            sum += carry;
            carry = sum/10;            
            ListNode *temp = new ListNode(sum%10);
            ptr->next = temp;
            ptr = ptr->next;
        }
        return l3->next;
    }
};
