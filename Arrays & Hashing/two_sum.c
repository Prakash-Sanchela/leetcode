/* question:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;

        for(int index = 0; index < nums.size(); index++){
            int complement = target - nums[index];

            if (umap.find(complement) != umap.end())
            {
                res.push_back(umap[complement]);
                res.push_back(index);
                break;
            }
            else
            {
                umap.insert({nums[index],index});
            }
        }
        return res;
    }
};
