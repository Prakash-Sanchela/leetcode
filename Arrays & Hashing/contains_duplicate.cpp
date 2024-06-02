/*
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.
Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
*/
#include<set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> st;
        int size = nums.size();
        for(int index = 0; index < size; index++)
        {
            if (st.find(nums[index]) != st.end())
                return true;
            else
                st.insert(nums[index]);
        }
        return false;
    }
};
