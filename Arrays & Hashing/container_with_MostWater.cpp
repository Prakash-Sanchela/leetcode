
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
int max_area(std::vector<int>vec)
{
    int max_area = 0;
    int left = 0;
    int right = vec.size()-1;
    
    while(left < right){
        int currentArea = min(vec[left], vec[right]) * (right-left); // for e.g min(1,7) min will return 1 * max(1,7) it returns 7
        max_area = max(max_area, currentArea);
        if(vec[left]<vec[right])
            left++;
        else
            right--;
    }
    return max_area;
}
int main() {
    //std::vector<int> vec{1,8,6,2,5,4,8,3,7};
    std::vector<int> vec{1,5,4,3};
    int abc = max_area(vec);
    cout << "max area : " <<abc <<endl;
    return 0;
}
