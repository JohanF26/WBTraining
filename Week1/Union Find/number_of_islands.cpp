class Solution {
public:
    void burnIsland(vector<vector<char>>& grid, int r, int c, int row, int col){
        if(r < 0 || c < 0 || r >= row || c >= col) return; //index check
        if(c+1 < col && grid[r][c+1] == '1'){
            grid[r][c+1] = '0';
            burnIsland(grid, r, c+1, row, col);
        }
        if(c-1 >= 0 && grid[r][c-1] == '1'){
            grid[r][c-1] = '0';
            burnIsland(grid, r, c-1, row, col);
        }
        if(r+1 < row && grid[r+1][c] == '1'){
            grid[r+1][c] = '0';
            burnIsland(grid, r+1, c, row, col);
        }
        if(r-1 >= 0 && grid[r-1][c] == '1'){
            grid[r-1][c] = '0';
            burnIsland(grid, r-1, c, row, col);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == '1'){
                    count++;
                    burnIsland(grid, r, c, row, col);
                }
            }
        }
        return count;
    }
};

/* NOTES

I also struggled a bit with this problem because I did not want to "burn" the islands
but realized that doing so would be the easiest way for me.

Runtime: 12 ms, faster than 95.55% of C++ online submissions for Number of Islands.
Memory Usage: 10.6 MB, less than 88.19% of C++ online submissions for Number of Islands.

*/
