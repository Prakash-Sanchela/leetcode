class ST {
public:
    int data;
    ST* next;
   
    // Constructor
    ST(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};
class myStack
{
private:
    ST *top;
public:
    void push(int data)
    {
        ST* temp = new ST(data);
        
        temp->next = top;
        top = temp;
    }
    int pop()
    {
        if (top == NULL)
        {
            cout<< "Stack is empty" << endl;
        }
        ST *temp = top;
        top = top->next;
        
        temp->next = NULL;
        free(temp);
    }
};
