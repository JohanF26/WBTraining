class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> candyTypes;
        for(int i = 0; i < candies.size(); i++){
            candyTypes.insert(candies[i]);
            if(candyTypes.size() > candies.size()/2){
                return (candies.size()/2);
            }
        }
        return candyTypes.size();
    }
};

/* NOTES

This problem was fairly easy but my runtime was horrible even though it is O(N)
I am going to try to see how to improve it

Runtime: 332 ms, faster than 37.39% of C++ online submissions for Distribute Candies.
Memory Usage: 41.4 MB, less than 78.66% of C++ online submissions for Distribute Candies.

*/
