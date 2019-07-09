class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            mymap[s[i]]++; //count every letter in s in the map
            mymap[t[i]]--; //subtract every letter in t from the map
        }
        for(auto it = mymap.begin(); it != mymap.end(); it++){
            if(it->second != 0) return false;
        }
        return true;
    }
};


/* NOTES

This problem was fairly simple but it took me a second to come up with a solution
that would not have a high time complexity. However, I'm sure it could still be
improved.

Runtime: 12 ms, faster than 89.34% of C++ online submissions for Valid Anagram.
Memory Usage: 9.6 MB, less than 18.89% of C++ online submissions for Valid Anagram.

*/
