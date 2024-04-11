#include <iostream>

using namespace std;

int binarySearch(int *arr, int low, int high, int key)
{
    
    while (low <= high)
    {
        int mid = (low + high)/2;
        //cout << endl<< "Mid : " << mid << endl;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid-1;
        else if (arr[mid] < key)
            low = mid+1;
    }
    
    return -1;
}

struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
    tree():data(0), left(nullptr), right(nullptr){}
};

void add(tree** ppTree, int num)
{
    if (*ppTree == nullptr)
    {
        *ppTree = new tree();
        // *ppTree = malloc(sizeof(tree));
        
        (*ppTree)->data = num;
        (*ppTree)->left = nullptr;
        (*ppTree)->right = nullptr;
    }
    else if ((*ppTree)->data > num)
    {
        add(&(*ppTree)->left, num);
    }
    else if ((*ppTree)->data < num)
    {
        add(&(*ppTree)->right, num);
    }
    else
        cout << "Number is already exist" << endl;
    
}

// recursive 
void Inorder(tree* pTree)
{
    // In-Order Left Print Right
    if (pTree != nullptr)
    {
        Inorder(pTree->left);
        cout << "-"<< pTree->data;
        Inorder(pTree->right);
    }
}
void preOrder(tree* pTree)
{
    // preOrder : Print Left Right
    if (pTree != nullptr)
    {
        cout << "-"<< pTree->data;
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}
void postOrder(tree* pTree)
{
    // postOrder : Left Right print
    if (pTree != nullptr)
    {
        postOrder(pTree->left);
        postOrder(pTree->right);
        cout << "-"<< pTree->data;;
    }
}
int count(tree* pTree)
{
    if (pTree == nullptr) // portion 1 null condition
        return 0;
    
    int leftsize = count(pTree->left); // 2. For traverse
    int rightsize = count(pTree->right);
    
    return  leftsize + rightsize + 1; // 3. return condition
}

int heightOfTree(tree* pTree)
{
    if (pTree == nullptr) // portion 1 null condition
        return 0;
    
    int leftHeight = heightOfTree(pTree->left); // 2. For traverse
    int rightHeight = heightOfTree(pTree->right);
    
    return  std::max(leftHeight, rightHeight) + 1; // 3. return condition
}
int count_leaf(tree* pTree)
{
    if (pTree == nullptr)
        return 0;
    
    if ( (pTree->left == nullptr) && (pTree->right == nullptr) )
        return 1;
    else
    {
        return count_leaf(pTree->left) + count_leaf(pTree->right);
    }
}

// check if given Tree is BST or not

bool isBST(tree* pTree)
{
	
	
	
}

tree* search(tree* pTree, int num)
{
    if (pTree == nullptr)
        return 0;
    else if (pTree->data == num)
        return pTree;
    else if (pTree->data > num)
        return (search(pTree->left, num));
    else if (pTree->data < num)
        return (search (pTree->right, num));
}

int main()
{
    cout<<"Hello World" << endl;

    int arr[] = {1, 3, 5, 8, 9, 10, 12, 15};

    //cout << binarySearch(arr, 0, 7, 8) << endl;
    //cout << binarySearch(arr, 0, 7, 12) << endl;

    tree* head = nullptr;
    add(&head, 20);
    add(&head, 10);
    add(&head, 15);
    add(&head, 30);
    add(&head, 25);
    add(&head, 5);
    add(&head, 35);
    add(&head, 30);
    
    Inorder(head);
    cout<< endl;
    preOrder(head);
    cout<< endl;
    postOrder(head);
    cout<< endl;
    
    tree *ptr = search(head, 25);
    cout << ptr->data << endl;
    
    cout << "Leaf  = " << count_leaf(head) << endl;
    cout << "No of Nodes = " << count(head) << endl;
    cout << "Height = " << heightOfTree(head) << endl;
    
    return 0;
}
