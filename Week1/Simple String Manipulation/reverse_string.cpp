class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size()/2; i++){
            std::swap(s[i], s[s.size()-i-1]);
        }
    }
};

/* NOTES

This was also fairly easy, at first I made my own swap function but then remembered
there was one available in the utility library (which for some reason I did not
have to import)

Runtime: 48 ms, faster than 86.11% of C++ online submissions for Reverse String.
Memory Usage: 15.1 MB, less than 78.16% of C++ online submissions for Reverse String.

*/
