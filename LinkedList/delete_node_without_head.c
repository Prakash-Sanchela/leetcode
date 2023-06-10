typedef struct SL_list
{
  int data;
  SL_list* next;
}SLL;

void delete_node_without_head(SLL *node)
{
  // create temp node and save the node->next node
  SLL *temp = node->next;
  // copy the node->next->data to current given node
  node->data = node->next->data;
  // copy the next node address to the given node->next
  node->next = node->next->next;
  //delete the temp (node->next) node;
  delete temp;
  temp = NULL;
}
