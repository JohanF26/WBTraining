class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> doubleMap;
        int retVal;
        for(int i = 0; i < nums.size(); i++){
            if(doubleMap.count(nums[i]) > 0){
                doubleMap.erase(nums[i]);
            } else{
                doubleMap[nums[i]] = 1;
            }
        }
        return doubleMap.begin()->first;
    }
};

/* NOTES

I did not get to use bitwise manipulation for this because I could not think of
a way to do it

Runtime: 28 ms, faster than 15.26% of C++ online submissions for Single Number.
Memory Usage: 11.6 MB, less than 9.23% of C++ online submissions for Single Number.

*/
