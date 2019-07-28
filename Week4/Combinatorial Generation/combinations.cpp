class Solution {
public:
    void combineHelp(int n, int k, int ind, vector<vector<int>>& retArr, vector<int>& curr){
        if(k == 0){
            retArr.push_back(curr);
        } else{
            for(int i = ind; i <= n; i++){
                curr.push_back(i);
                combineHelp(n, k-1, i+1, retArr, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> retArr;
        vector<int> curr;
        combineHelp(n, k, 1, retArr, curr);
        return retArr;
    }
};

/* NOTES

This problem was a bit challeging but I was able to solve it after running it once
and seeing that I was comitting the mistake of repeating ints in the array.

Runtime: 72 ms, faster than 82.02% of C++ online submissions for Combinations.
Memory Usage: 11.9 MB, less than 63.05% of C++ online submissions for Combinations.

*/
