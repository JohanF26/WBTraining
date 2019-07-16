class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; j < s.size() && i < t.size(); i++){
            if(s[j] == t[i]) j++;
        }
        return (j == s.size());
    }
};

/* NOTES

This problem was also fairly easy. It was similar to the assign cookies problem
since all you had to do was iterate over string t and if the current character
of string s matched it then we increment the index for s

Runtime: 56 ms, faster than 97.03% of C++ online submissions for Is Subsequence.
Memory Usage: 17.1 MB, less than 40.77% of C++ online submissions for Is Subsequence.

*/
