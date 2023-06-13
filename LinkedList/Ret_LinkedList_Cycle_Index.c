#include <unordered_map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = NULL;
        std::unordered_map<ListNode*, int> map;

        unsigned int counter = 0;
        while(slow){
            if(map.find(slow) == map.end())
            {
                map[slow] = counter++;
                slow = slow->next;
            }
            else{
                fast = slow;
                break;
            }
        }
        return fast;
    }
};
