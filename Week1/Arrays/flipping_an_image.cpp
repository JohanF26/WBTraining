//FIRST SOLUTION

/*

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size() % 2 != 0){
            for(int i = 0; i < A.size(); i++){
                for(int j = 0; j < (A.size() - 1) / 2; j++){
                    if(A[i][j] == A[i][A[0].size() - j - 1]){
                        A[i][j] = A[i][A[0].size() - j - 1] = 1 - A[i][j];
                    }
                }
                A[i][(int) A[0].size() / 2] = 1 - A[i][(int) A[0].size() / 2];
            }
        } else{
            for(int i = 0; i < A.size(); i++){
                for(int j = 0; j < A.size() / 2; j++){
                    if(A[i][j] == A[i][A[0].size() - j - 1]){
                        A[i][j] = A[i][A[0].size() - j - 1] = 1 - A[i][j];
                    }
                }
            }
        }
        return A;
    }
};

*/

// IMPROVED SOLUTION

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A.size() / 2; j++){
                if(A[i][j] == A[i][A[0].size() - j - 1]){
                    A[i][j] = A[i][A[0].size() - j - 1] = 1 - A[i][j];
                }
            }
            if(A[0].size() % 2 != 0){
                A[i][(int) A[0].size() / 2] = 1 - A[i][(int) A[0].size() / 2];
            }
        }
        return A;
    }
};

/* NOTES

Once again, this problem looked harder than it actually was, I tried writing
a simple solution first then tried to improve on it

Runtime: 8 ms, faster than 99.13% of C++ online submissions for Flipping an Image.
Memory Usage: 9.2 MB, less than 84.44% of C++ online submissions for Flipping an Image.

*/
