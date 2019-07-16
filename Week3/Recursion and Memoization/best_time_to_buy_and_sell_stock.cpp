class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            } else if(prices[i] - minPrice > maxProf){
                maxProf = prices[i] - minPrice;
            }
        }
        return maxProf;
    }
};

/* NOTES
This problem was fairly simple but I did not understand how I could use recursion
or dynamic programming for it. I guess this could be considered dynamic programming
since at every step we choose the best solution in hopes of finding an optimal
answer.

Runtime: 4 ms, faster than 98.90% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 9.5 MB, less than 42.92% of C++ online submissions for Best Time to Buy and Sell Stock.

*/
