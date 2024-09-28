#include <iostream>
using namespace std;

bool powerOf2(int num)
{
  if(num & (num-1))
    return false;
  else
    return true;
}
int main()
{
    int num =128;
    if (powerOf2(num))
      cout <<" is power of 2 "<<num<<endl;
    else
      cout <<" not a power of 2 "<<num<<endl;
    return 0;
}
