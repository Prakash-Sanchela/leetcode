/*
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        cout << n << endl;
        int count = 0;
        int i = 0;
        while(i<32)
        {
            if(n & (1<<i)){
                count++;
                i++;
            }
        }
        return count;
    }
};
