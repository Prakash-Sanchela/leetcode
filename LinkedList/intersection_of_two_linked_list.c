// link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <unordered_map>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == NULL)
            return NULL;
        if(headB == NULL)
            return NULL;
        
		// sol 1: using two pointers
        /*		
		ListNode *a = headA;
        ListNode *b = headB;
        while(a != b)
        {
            if (a != NULL)
                a = a->next;
            else
                a = headB;

            if(b != NULL)
                b = b->next;
            else
                b = headA;
        }
        return a;*/
		// sol 2 : using unordered_map
        unordered_map<ListNode*,int>mpp;
        for(auto p = headA; p != NULL; p=p->next) {
            mpp[p]=p->val;
        }
        for(auto p = headB; p != NULL; p = p->next){
            if(mpp.find(p) != mpp.end())
                return p;
        }
        return NULL;
    }
};
