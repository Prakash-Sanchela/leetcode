#include <iostream>
using namespace std;
int main()
{
    // multiple of 4
    int num = 10;
    while(num)
    {
        if ( ! (num & 1) && ! (num & (1<<1) ) )
        {
            cout << "multiple of four : "<<num<<endl;
        }
        num++;
        if (num > 150)
            break;
    }
    //multiple of 8
    int num_8 = 10;
    while(num_8)
    {
        if ( ! (num_8 & 1) && ! (num_8 & (1<<1) ) && ! (num_8 & (1<<2)) ){
            cout << "multiple of eight : "<<num_8<<endl;
        }
        num_8++;
        if (num_8 > 150)
            break;
    }
    //multiple of 8
    int num_16 = 10;
    while(num_16)
    {
        if ( ! (num_16 & 1) && ! (num_16 & (1<<1) ) && 
             ! (num_16 & (1<<2)) && ! (num_16 & (1<<3)) ){
            cout << "multiple of sixteen : "<<num_16<<endl;
        }
        num_16++;
        if (num_16 > 150)
            break;
    }
  return 0;
}
