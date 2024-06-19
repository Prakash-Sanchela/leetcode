// https://www.geeksforgeeks.org/lru-cache-implementation/
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRU{
private:
    int csize;
    
    // actual pages
    std::list<int> dq;
    
    // hashmap;
    std::unordered_map<int, std::list<int>::iterator> mp;
public:
    LRU(int size):csize(size){}
    
    void push(int data)
    {
        if(mp.find(data) == mp.end())
        {
            if(dq.size() == csize)
            {
                int last = dq.back();
                dq.pop_back();
                mp.erase(last);
            }
        }
        else
            dq.erase(mp[data]);
        
        dq.push_front(data);
        mp[data] = dq.begin();
        
    }
    void print(){
        for(auto itr = dq.begin(); itr != dq.end(); ++itr){
            cout<<*itr<<" ";
        }
        cout <<endl;
    }
};
int main()
{
    LRU one(3);
    one.push(10);
    one.push(20);
    one.push(30); // 30, 20, 10
    one.print();
    one.push(40); // 40,30,20
    one.print();
    one.push(10); // 10, 40, 30
    one.print();
    one.push(30); // 30, 10, 40
    one.print();
    return 0;
}
