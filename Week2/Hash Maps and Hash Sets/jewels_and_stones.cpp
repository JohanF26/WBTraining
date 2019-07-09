class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> jewelCount;
        int totalJ = 0;
        for(int i = 0; i < S.size(); i++){
            jewelCount[S[i]]++;
        }
        for(int i = 0; i < J.size(); i++){
            totalJ += jewelCount[J[i]];
        }
        return totalJ;
    }
};

/* NOTES

This problem was fairly simple so I was able to think of a solution immediately

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.7 MB, less than 19.51% of C++ online submissions for Jewels and Stones.

*/
