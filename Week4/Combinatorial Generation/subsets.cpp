class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retArr;
        int powSetSize = pow(2, nums.size());
        for(int i = 0; i < powSetSize; i++){
            vector<int> subset;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            retArr.push_back(subset);
        }
        return retArr;
    }
};

/* NOTES

I was not too sure how to implement an algorithm for this since I could not find
many resources for combinatorial generation in c++ (most of them were for python
and used built in libraries). However, I googled how to deal with power set
problems and tried to understand the algorithm then implement my own.

Runtime: 4 ms, faster than 98.30% of C++ online submissions for Subsets.
Memory Usage: 9.1 MB, less than 62.06% of C++ online submissions for Subsets.

*/
