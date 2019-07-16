class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        std::sort(points.begin(), points.end(), std::greater<vector<int>>()); //sort descending
        int arrows = 1;
        int start = points[0][0];
        for(int i = 1; i < points.size(); i++){
            if(start <= points[i][1]){
                continue;
            }
            arrows++;
            start = points[i][0];
        }
        return arrows;
    }
};

/* NOTES

Coming up with a solution for this problem was easy once I learned about greedy
algorithms, but I do not know why my runtime is so low or how to improve it.
Somehow implementing my own greater function gave me a better runtime but I believe
this solution is better

Runtime: 144 ms, faster than 39.50% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
Memory Usage: 26.9 MB, less than 10.50% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.

*/
