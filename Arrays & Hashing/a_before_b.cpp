// Check if all A's appears before All B's
/*
Example 1:

Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
Example 2:

Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
Example 3:

Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
*/

class Solution {
public:
    bool checkString(string s) {
        int len = s.length();
        bool hitB = false;
        for(int i=0; i<len; ++i){

            if (s[i] == 'a')
                if (hitB)
                    return false;
                else
                    continue;
                
            if (s[i] == 'b')
                hitB = true;
        }
        return true;
    }
};
