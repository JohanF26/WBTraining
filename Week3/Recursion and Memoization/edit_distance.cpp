class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = 0;
        int c = 0;
        vector<vector<int>> reverseLcs(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(r = 0; r < word1.size()+1; r++){
            reverseLcs[r][0] = r;
        }
        for(c = 0; c < word2.size()+1; c++){
            reverseLcs[0][c] = c;
        }

        for(r = 1; r < reverseLcs.size(); r++){
            for(c = 1; c < reverseLcs[0].size(); c++){
                if(word1[r-1] == word2[c-1]){
                    reverseLcs[r][c] = reverseLcs[r-1][c-1];
                }
                else {
                    reverseLcs[r][c] = min(reverseLcs[r-1][c-1], min(reverseLcs[r-1][c], reverseLcs[r][c-1])) + 1;
                }
            }
        }

        return reverseLcs[r-1][c-1];

    }
};

/* NOTES

This problem was very similar to LCS but instead of finding the longest common
subsequence I had to keep track of the times the strings differed and by how much.
By adding 1 to the min of the three surrounding cells whenever the characters in
the string did not match, I get to count the current edit difference while also
choosing the shortest distance.

Runtime: 16 ms, faster than 47.71% of C++ online submissions for Edit Distance.
Memory Usage: 11.2 MB, less than 53.52% of C++ online submissions for Edit Distance.

*/
