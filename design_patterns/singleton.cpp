
4. Thread safe Singleton
#include <iostream>
#include <mutex>
using namespace std;
// thread safe singleton
class singleton
{
private :
    static singleton *st_ptr;
    singleton()
    {
        cout << "singleton constructor " << endl;
    }
    singleton(const singleton& obj) = delete;
    singleton& operator=(const singleton& obj) = delete;
public:
    static singleton& getInstance()
    {
        if (!st_ptr)
        {
            mutex _mutex;
            lock_guard<mutex> lock(_mutex);
            if (!st_ptr)
            {   
                st_ptr = new singleton();
            }
        }
        return *st_ptr;
    }
};
singleton* singleton::st_ptr = nullptr;
int main()
{
    cout<<"Hello World";
    
    return 0;
}
