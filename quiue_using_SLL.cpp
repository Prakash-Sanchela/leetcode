// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} queue;
void initQueue(queue *q){
  q->front = q->rear = NULL;
}
int isEmpty(queue *q)
{
  return (q->front == NULL);
}
void enqueue(queue *q, int num)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  if (!newNode)
  {
    printf("failed to allocate mem\n");
    return;
  }
  newNode->data = num;
  newNode->next = NULL;
  if (q->rear == NULL) // if queue is empty
  {
    q->front = q->rear = newNode;
  }
  else{
    q->rear->next = newNode;
    q->rear = newNode;
  }
  printf("Enqueued: %d\n", num);
}
int dequeue(queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty! Cannot dequeue.\n");
    return -1;
  }
  Node *temp = q->front;
  int data = temp->data;
  q->front = q->front->next;
  if(q->front == NULL)
  {
    q->rear = NULL;
  }
  free(temp);
  printf("Dequeued: %d\n", data);
  return data;
}

// Function to display the queue
void displayQueue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    
    Node* temp = q->front;
    printf("Queue: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the queue memory
void freeQueue(queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}
int main() {
    queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    freeQueue(&q);
    return 0;
}
