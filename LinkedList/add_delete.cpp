// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void add_begin(node** head, int data){
    
    if (*head == nullptr)
    {
        // first node
        node *temp = new node();
        temp->data = data;
        *head = temp;
    }
    else
    {
        node *temp = new node();
        temp->data = data;
        temp->next = *head;
        *head = temp;
    }
}
void add_end(node** head, int data){
    if (head == nullptr)
        return;
    
    node *temp = *head;
    while(temp->next !=nullptr){
        temp = temp->next;
    }
    node *temp1 = new node();
    temp1->data = data;
    temp1->next = temp->next;
    temp->next = temp1;
}
node* add_middle(int pos){
    return nullptr;
}

void delete_node_from_end(node** head, int pos)
{
    if(*head == nullptr)
        return;
    node *ptr1 = *head;
    int len = pos;
    while(len--)
        ptr1 = ptr1->next;
    node *ptr2 = *head;
    node *prev = nullptr;
    while(ptr1)
    {
        ptr1 = ptr1->next;
        prev = ptr2;
        ptr2 = ptr2->next;
    }
    prev->next = ptr2->next;
    free(ptr2);
    //ptr2->data = ptr2->next->data;
    //ptr2->next = ptr2->next->next;
    //free(ptr2);
}
void reverse_iterative(node **head)
{
    if (*head == nullptr)
        return;
        
    node* prev = nullptr;
    node* curr = *head;
    node* next;
    
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void reverse_recursive(node **head)
{
    
}
void print(node *head)
{
    while(head){
        cout << head->data<<" " <<endl;
        head = head->next;
    }
    cout <<"==================="<<endl;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro"<<endl;
    node *head = nullptr;
    add_begin(&head, 10);
    add_begin(&head, 20);
    add_begin(&head, 30);
    add_end(&head, 40);
    add_end(&head, 50);
    add_end(&head, 60);
    add_end(&head, 70);
    print(head);
    delete_node_from_end(&head, 3);
    print(head);
    reverse_iterative(&head);
    print(head);
    return 0;
}
