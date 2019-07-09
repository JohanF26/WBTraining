class Solution {
public:
    int titleToNumber(string s) {
        int retVal = 0;
        for(int i = 0; i < s.size(); i++){
            retVal *= 26;
            retVal++;
            char temp = s[i];
            char subs = 'A';
            retVal += (int) (temp - subs);
        }
        return retVal;
    }
};

/* NOTES



Runtime: 4 ms, faster than 86.99% of C++ online submissions for Excel Sheet Column Number.
Memory Usage: 8.3 MB, less than 23.98% of C++ online submissions for Excel Sheet Column Number.

*/
