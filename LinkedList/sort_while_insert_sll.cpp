#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}  // Constructor
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}  // Constructor

    // Function to insert in sorted order
    void insertSorted(int value) {
        Node* newNode = new Node(value);

        // Case 1: Insert at the beginning or empty list
        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Case 2: Insert in the middle or end
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to print the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free memory
    ~SortedLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SortedLinkedList list;

    // Insert elements in random order
    list.insertSorted(10);
    list.insertSorted(3);
    list.insertSorted(5);
    list.insertSorted(2);
    list.insertSorted(7);

    // Print sorted linked list
    std::cout << "Sorted Linked List: ";
    list.display();

    return 0;
}
