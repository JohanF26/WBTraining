class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i < t.size(); i++){
            if(std::count(s.begin(), s.end(), t[i]) != std::count(t.begin(), t.end(), t[i])) return t[i];
        }
        return ' ';
    }
};

/* NOTES

My first few submissions did not have a good runtime but after realizing there was
a std::count my runtime improved drastically

Runtime: 4 ms, faster than 90.06% of C++ online submissions for Find the Difference.
Memory Usage: 8.8 MB, less than 95.52% of C++ online submissions for Find the Difference.

*/
