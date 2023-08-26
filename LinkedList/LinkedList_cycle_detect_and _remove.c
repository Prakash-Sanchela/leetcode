class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            
            slow = slow->next;
            if(slow == fast)
                return true;
            /*
            logic to remove cycle
            if(slow == fast)
                return true;
            */
        }
        return false;
    }
/*
Another solution could be to use the hash_map.
1. use unordered_map;
2. insert one by one node starting from head node and make it's value as 1
3. if list has look there will be a point where before inserting into map
   if we find the node and value with 1 it means it has a loop at that node
*/
};
