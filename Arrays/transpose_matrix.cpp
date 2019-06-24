class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> retArr(A[0].size());
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                retArr[j].push_back(A[i][j]);
            }
        }
        return retArr;
    }
};

/* NOTES

When I first saw this problem I was a bit intimidated since it seemed more
complicated than it actually was but after writing it on paper I was able to
come up with a simple solution. Though I believe it could still be improved.

Runtime: 28 ms, faster than 78.61% of C++ online submissions for Transpose Matrix.
Memory Usage: 11.6 MB, less than 48.34% of C++ online submissions for Transpose Matrix.

*/
