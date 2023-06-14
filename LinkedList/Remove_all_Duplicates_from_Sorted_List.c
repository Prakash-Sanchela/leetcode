class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* temp = prev;

        while(temp->next != nullptr && temp->next->next != nullptr){     
            if (temp->next->val == temp->next->next->val){
                int var = temp->next->val;   
                while(temp->next != nullptr && temp->next->val == var)
                    temp->next = temp->next->next;
            }
            else 
                temp = temp->next;
        }
        return prev->next;
        // sol 2. use map<int, int>. add entry to each node
        // map.first is the integer in list node and map.second is 
        // number of integer in list so after adding into list
        // create a new list, rotate through map and if map.second == 1
        // for that node only we add into the list. 
        /*
        map <int, int> mp;

        while(head != NULL)
        {
            mp[head -> val]++;
            head = head -> next;
        }

        ListNode* newHead = new ListNode(); //Creating new list for answer
        ListNode* temp = newHead; //temp variable to keep track of the last node
        for(auto & it: mp)
        {
            if(it.second == 1)
            {
                ListNode* ans = new ListNode(it.first); //to avoid integer to pointer conversion
                temp -> next = ans;
                temp = ans;
            }
        }
        return newHead -> next;
        */
    }
};
