#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertInSortedOrder(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    // Case 1: Insert at the beginning or empty list
    if (head == nullptr || head->val >= val) {
        newNode->next = head;
        return newNode;
    }
    // Case 2: Insert after the head
    ListNode* current = head;
    while (current->next != nullptr && current->next->val < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
