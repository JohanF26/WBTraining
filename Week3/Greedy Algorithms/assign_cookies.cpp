class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};

/* NOTES

This problem was also fairly simple because once you have the arrays sorted you
try to satisfy each child, if a child is not satisfied with the current cookie look
for the next cookie that will satisfy him.

Runtime: 36 ms, faster than 96.90% of C++ online submissions for Assign Cookies.
Memory Usage: 10.2 MB, less than 95.12% of C++ online submissions for Assign Cookies.

*/
