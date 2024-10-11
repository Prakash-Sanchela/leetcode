#include "../inc/base.h"
#include <unordered_map>

class LRUCache{
public:
    class node
    {
        public:
            node *prev;
            int key;
            int value;
            node *next;
            node(int _key, int _val){
                key = _key;
                value = _val;
            }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

private:
    int cap;
    std::unordered_map<int, node*> _mapOfEntry;

private:
    void printMap(){
        cout << "Map entries"<<endl;
        std::unordered_map<int, node*>::iterator itr = _mapOfEntry.begin();
        while(itr != _mapOfEntry.end())
        {
            cout << itr->first << " : " <<itr->second<<endl;
            itr++;
        }
    }
    void printList(){
        cout << "list entries"<<endl;
        node *temp = head->next;
        cout << temp->key<<endl;
        while(temp->value != -1)
        {
            cout << temp->key << " : " << temp->value<<endl;
            temp = temp->next;
        }
    }
public:
    LRUCache(int capacity){
        cout << " In LRUCache ctor() : " << endl;
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->prev = head;
        newNode->next = temp;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode)
    {
        /*node *temp = delNode->prev;
        node *tempNext = delNode->next;
        temp->next = tempNext;
        tempNext-prev = temp;
        */
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    int get(int key){
        int ret  = -1;
        if (_mapOfEntry.find(key) != _mapOfEntry.end())
        {
            node *temp = _mapOfEntry[key];
            ret = temp->value;

            _mapOfEntry.erase(key);
            // delete that node and add it to head
            deleteNode(temp);
            addNode(temp);
            _mapOfEntry[key] = head->next;
        }
        //printMap();
        printList();
        return ret;
    }
    
    void put(int key, int value){
        
        if (_mapOfEntry.find(key) != _mapOfEntry.end())
        {
            node *temp = _mapOfEntry[key];
            _mapOfEntry.erase(key);
            deleteNode(temp);
        }
        if (_mapOfEntry.size() == cap)
        {
            _mapOfEntry.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        _mapOfEntry[key] = head->next;
        //printMap();
        printList();
    }
    ~LRUCache()
    {

    }
};

int main()
{
    // LRU cache
    LRUCache *lru = new LRUCache(3);
    lru->put(1, 100);
    lru->put(2, 200);
    lru->put(3, 300);
    cout << "get 2 : " << lru->get(2)<<endl;
    lru->put(4, 400);
    cout << "get 6 : " <<lru->get(6)<<endl;

    //lru.put(3,300);
    return 0;
}
