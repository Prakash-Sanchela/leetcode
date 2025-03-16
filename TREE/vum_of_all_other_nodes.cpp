Ex Input.
       4
     /   \
   2     6
  / \    /
 1   3  5


Given a Binary Search Tree transform it in to a tree where each node will have the value as sum of all other nodes which are greater than the current node value.
Ex. Output
       11
      /  \
    18    0
   /  \  /
  20  15 6
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to compute total sum of the tree
int computeSum(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return root->data + computeSum(root->left) + computeSum(root->right);
}

// Function to update each node's value
void transformTree(TreeNode* root, int totalSum) {
    if (root == nullptr)
        return;
    
    root->data = totalSum - root->data;  // Update the node
    transformTree(root->left, totalSum);
    transformTree(root->right, totalSum);
}

// Inorder traversal to print the tree
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Constructing the given BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    int totalSum = computeSum(root);  // Get the total sum of the tree

    transformTree(root, totalSum);  // Transform the tree

    cout << "Inorder Traversal of Transformed Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
