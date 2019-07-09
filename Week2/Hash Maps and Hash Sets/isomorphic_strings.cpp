class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> iso1;
        set<char> tSet;
        for(int i = 0; i < s.size(); i++){
            if(iso1.count(s[i]) != 0){
                if(iso1[s[i]] != t[i]){
                    return false;
                }

            } else{
                iso1[s[i]] = t[i];
                tSet.insert(t[i]);
            }
        }
        return (iso1.size() == tSet.size());
    }
};

/* NOTES

I was able to come up with a solution quickly but it required me to use two maps
and did not have a good runtime. After giving it some thought I realized I could
use a set to keep track of the number of different chars in the second string
and that if the tests in the for loop passed then the size of the map and set must
be the same in order for the strings to be isomorphic

Runtime: 8 ms, faster than 91.00% of C++ online submissions for Isomorphic Strings.
Memory Usage: 9.3 MB, less than 41.61% of C++ online submissions for Isomorphic Strings.

*/
