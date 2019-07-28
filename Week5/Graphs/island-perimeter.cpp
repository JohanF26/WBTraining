class Solution {
public:
    //function to check row and col are in range and grid is not 0
    bool isSafe(vector<vector<int>>& grid, int row, int col){
        //cout << "isSafe " << row << col << endl;
        return ((row >= 0) && (row < grid.size()) && (col >= 0) && (col < grid[0].size())
                && grid[row][col]);
    }

    void countSides(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int& sides){
        // if(row == 0) sides++;
        // if(row == grid.size()-1) sides++;
        // if(col == 0) sides++;
        // if(col == grid.size()-1) sides++;
        //cout << "row " << row << " col " << col << endl;
        //mark current cell as visited
        visited[row][col] = true;

        //order is left, top, right, bottom
        vector<int> rowsArnd = {0, -1, 0, 1};
        vector<int> colsArnd = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int tempRow = row+rowsArnd[i];
            int tempCol = col+colsArnd[i];
            if(isSafe(grid, tempRow, tempCol)){

                //if adjacent cell has not been visited then visit it
                if(!visited[tempRow][tempCol]){
                    countSides(grid, visited, tempRow, tempCol, sides);
                }
            } else{
                //if adjacent cell is zero or edge of matrix then it is a side
                sides++;
                //cout << "sides " << sides << endl;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int perim = 0;
        bool done = false;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    countSides(grid, visited, r, c, perim);
                    done = true;
                    break;
                }
            }
            if(done) break;
        }

        return perim;

    }
};

/* NOTES

I solved this problem using DFS, however, after looking through other possible
answers I realized there was a very easy mathematical solution to this that does
not require any knowledge about graphs.

Runtime: 184 ms, faster than 5.02% of C++ online submissions for Island Perimeter.
Memory Usage: 40.7 MB, less than 5.23% of C++ online submissions for Island Perimeter.

----- Alternative way -----

A fast way to find the solution is to
count the number of 1s in the matrix processing top-to-bottom and left-to-right,
then counting how many cells with 1 have another 1 to the left and how many
have another 1 above. In that case the answer would be four times the number of
1s (since it has four possible sides) minus 2 times the number of pairs of
adjacent ones since when two ones are adjacent each cell loses one side.

For the example:
[0 1 0 0]
[1 1 1 0]
[0 1 0 0]
[1 1 0 0]

There are 7 1s and 4*7 = 28 (possible sides)
There are 6 pairs of adjacent 1s so 2*6 = 12 (not sides)
The answer would be 28 - 12 = 16

*/
