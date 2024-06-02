/*
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/
#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if(s.compare(t)==0)
            return true;
        return false;
    }
};
