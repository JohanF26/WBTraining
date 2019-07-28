class Solution {
public:
    void combinationHelp(vector<int>& candidates, int target, vector<vector<int>>& retArr, vector<int>& curr, int ind){
        if(target == 0){
            retArr.push_back(curr);
        } else if(target < 0){
            return;
        } else{
            for(int i = ind; i < candidates.size(); i++){
                curr.push_back(candidates[i]);
                combinationHelp(candidates, target-candidates[i], retArr, curr, i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> retArr;
        vector<int> curr;
        combinationHelp(candidates, target, retArr, curr, 0);
        return retArr;
    }
};

/* NOTES

This problem was a bit challeging but doable using the backtracking techniques I
learned while solving previous problems.

Runtime: 8 ms, faster than 98.43% of C++ online submissions for Combination Sum.
Memory Usage: 9.3 MB, less than 80.19% of C++ online submissions for Combination Sum.

*/
