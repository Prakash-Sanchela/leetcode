// https://leetcode.com/problems/single-number/
#include<unordered_map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto i:nums)
        {
            umap[i]++;
        }
        for(auto i:umap)
        {
            if (i.second == 1)
                return i.first;
        }
        return 0;
    }
};
