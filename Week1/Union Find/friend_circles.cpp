class Solution {
public:
    void dfs(vector<vector<int>>& M, int person, set<int>& visited){
        for(int i = 0; i < M[person].size(); i++){
            if((M[person][i]) && (visited.find(i) == visited.end())){
                visited.insert(i);
                dfs(M, i, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int numCircles = 0;
        set<int> visited;

        for(int i = 0; i < M.size(); i++){
            if(visited.find(i) == visited.end()){ //if person i not visited then dfs
                numCircles++;
                dfs(M, i, visited);
            }
        }
        return numCircles;
    }
};

/* NOTES

This problem was hard for me and I did not see how I could use union find to come
up with a solution. Instead I had to google similar problems and understand how they
work in order to solve this one.

Runtime: 20 ms, faster than 89.67% of C++ online submissions for Friend Circles.
Memory Usage: 11.4 MB, less than 24.77% of C++ online submissions for Friend Circles.

*/
