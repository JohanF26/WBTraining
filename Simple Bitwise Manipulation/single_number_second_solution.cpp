class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int retVal = 0;
        for(int i = 0; i < nums.size(); i++){
            retVal ^= nums[i];
        }
        return retVal;
    }
};

/* NOTES

After giving it some thought I was able to come up with a solution using bit
manipulation. I had previously used this method but for some reason not initializing
retVal to 0 resulted in a wrong result.

Runtime: 12 ms, faster than 96.86% of C++ online submissions for Single Number.
Memory Usage: 9.7 MB, less than 67.74% of C++ online submissions for Single Number.

*/
