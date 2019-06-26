class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            mymap[s[i]]++;
            mymap[t[i]]--;
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

Runtime: 16 ms, faster than 59.23% of C++ online submissions for Valid Anagram.
Memory Usage: 9.5 MB, less than 28.11% of C++ online submissions for Valid Anagram.

*/
