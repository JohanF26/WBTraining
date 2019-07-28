class Solution {
public:
    vector<int> memo;
    bool robFirst;
    int robHelp(vector<int>& nums, int i){
        if(i < 0 || (i == 0 && !robFirst)) return 0;
        if(memo[i] >= 0) return memo[i];
        int result = max(nums[i] + robHelp(nums, i-2), robHelp(nums, i-1));
        memo[i] = result;
        return result;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        memo = vector<int>(nums.size(),-1);
        robFirst = true;
        int result1 = robHelp(nums, nums.size()-2);
        memo = vector<int>(nums.size(),-1);
        robFirst = false;
        int result2 = robHelp(nums, nums.size()-1);
        return max(result1, result2);
    }
};

/* NOTES

I really struggled coming up with a solution for this. I went and worked on
house robber 1 to understand it better but it only helped me solve the problem
while ignoring the restriction that houses are arranged in a circle. The best
solution I could think of was to run it starting at the penultimate house and
allowing to rob the first house, and then starting at the last house and setting
a flag to prohibit robbing the first house.

Runtime: 4 ms, faster than 70.19% of C++ online submissions for House Robber II.
Memory Usage: 8.7 MB, less than 14.59% of C++ online submissions for House Robber II.

*/
