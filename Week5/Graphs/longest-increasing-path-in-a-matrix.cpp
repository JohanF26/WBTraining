class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix, vector<vector<int>>& visited, int row, int col, int curr, int cp){
        return ( (row >= 0) && (row < matrix.size()) && (col >= 0) && (col < matrix[0].size()) &&
               matrix[row][col] > curr && visited[row][col] < cp+1);
    }

    void findPath(vector<vector<int>>& matrix, vector<vector<int>>& visited, int row, int col, int& lp, int cp){
        visited[row][col] = cp;

        vector<int> rowAdj = {0,-1,0,1};
        vector<int> colAdj = {-1,0,1,0};

        for(int i = 0; i < 4; i++){
            int tempRow = row+rowAdj[i];
            int tempCol = col+colAdj[i];
            if(isSafe(matrix, visited, tempRow, tempCol, matrix[row][col], cp)){
                findPath(matrix, visited, tempRow, tempCol, lp, 1+cp);
            }
        }
        lp = max(lp, cp);
        //visited[row][col] = false;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        int longest = 0;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                findPath(matrix, visited, r, c, longest, 1);
            }
        }
        return longest;
    }
};

/* NOTES

This problem was a bit challenging because I could not think of how to avoid
some that are obviously shorter from being checked multiple times. The way I
solved it was by using the visited matrix to keep track of the counter at the
current cell, that way if a path would have a current value that is smaller than
the one at that cell then we know that path is shorter. That way when a matrix
has numbers such as
[2  3  8 ]                                      [1 2 3]
[25 23 9 ] the visited matrix will look like    [6 5 4] after the first run
[30 38 39]                                      [7 8 9]
and that way when starting at 3 the current path length will be 1 which is less
than the 2 stored in that cell, so we know that the current path is not worth
checking.

*/
