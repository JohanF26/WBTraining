class Solution {
public:
    //ensure row and col are in range of board, that cell has not been visited, and cell contains next char
    bool isSafe(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, char c){
        return( (row>=0) && (row < board.size()) && (col>=0) && (col < board[0].size())
               && !visited[row][col] && (board[row][col] == c));
    }

    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int row, int col, string word, int i){
        visited[row][col] = true;
        i++;

        //if word has been found return
        if(i == word.size()) return true;

        vector<int> rowAdj = {0, -1, 0, 1};
        vector<int> colAdj = {-1, 0, 1, 0};

        for(int j = 0; j < 4; j++){
            int tempRow = row+rowAdj[j];
            int tempCol = col+colAdj[j];

            if(isSafe(board, visited, tempRow, tempCol, word[i])){
                //if letter is found around it return true, otherwise keep looking in the next adj cell
                if(DFS(board, visited, tempRow, tempCol, word, i)){
                    return true;
                }
            }
        }
        //if not found in adj cell unmark current cell for future use and return false
        visited[row][col] = false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0]){
                    //if found return otherwise keep looking
                    if(DFS(board, visited, r, c, word, 0)) return true;
                }
            }
        }
        return false;
    }
};

/* NOTES

This problem was fairly simple once I tried to follow the DFS on paper. That
allowed me to see how I needed to update the visited matrix and how to determine
if the word had been found or not.

Runtime: 120 ms, faster than 44.95% of C++ online submissions for Word Search.
Memory Usage: 31.5 MB, less than 40.96% of C++ online submissions for Word Search.
Next challenges:

*/
