class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int count = 1;
        for(int i = 1; (i < candies.size()) && (count < candies.size()/2); i++){
            if(candies[i] != candies[i-1]){
                count++;
            }
        }
        return count;

    }
};

/* NOTES

For some reason this solution, which is O(N log N) is giving me a better runtime
than my O(N) solution.

Runtime: 264 ms, faster than 85.20% of C++ online submissions for Distribute Candies.
Memory Usage: 16.1 MB, less than 96.64% of C++ online submissions for Distribute Candies.

*/
