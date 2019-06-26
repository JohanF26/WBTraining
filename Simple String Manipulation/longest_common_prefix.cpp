class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string retStr;
        bool isPref = true;
        if(strs.size() > 0){
            for(int c = 0; c < strs[0].size(); c++){
                for(int i = 1; i < strs.size(); i++){
                    if(c == strs[i].size() || strs[0][c] != strs[i][c]) return retStr;
                }
                retStr.append(string(1, strs[0][c]));
            }
        }
        return retStr;
    }
};

/* NOTES

This reminds me of the longest common subsequence problem and it makes me wonder
if there is a solution similar to it that would be better than this one.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Common Prefix.
Memory Usage: 8.9 MB, less than 46.50% of C++ online submissions for Longest Common Prefix.


I tried to use a buffer to avoid using so much memory but could not understand
where the buffer overflow was happening

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char* buf;
        if(strs.size() > 0){
            buf = new char[strs[0].size() + 1];
            for(int c = 0; c < strs[0].size(); c++){
                for(int i = 1; i < strs.size(); i++){
                    if(c == strs[i].size() || strs[0][c] != strs[i][c]) return string(buf);
                }
                buf[c] = strs[0][c];
            }
        }
        return string(buf);
    }
};
*/
