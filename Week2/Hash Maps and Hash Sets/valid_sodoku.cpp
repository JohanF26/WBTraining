class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rowSets(9);
        vector<set<int>> colSets(9);
        vector<vector<set<int>>> squareSets(3, vector<set<int>>(3));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board.size(); c++){
                if(board[r][c] == '.'){
                    continue;
                } else if(rowSets[r].count(board[r][c]) == 0 && colSets[c].count(board[r][c]) == 0 && squareSets[r/3][c/3].count(board[r][c]) == 0){
                    rowSets[r].insert(board[r][c]);
                    colSets[c].insert(board[r][c]);
                    squareSets[r/3][c/3].insert(board[r][c]);
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};

/* NOTES

The first approach I thought of would have been O(N) but would require me to
iterate over the cells in the table 3 times (one for rows, cols, and squares)
This approach goes through the board once and makes sure the number is not in
either of the sets.

Runtime: 12 ms, faster than 94.40% of C++ online submissions for Valid Sudoku.
Memory Usage: 12 MB, less than 12.48% of C++ online submissions for Valid Sudoku.

*/
