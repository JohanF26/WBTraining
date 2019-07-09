class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> patMap;
        unordered_set<string> strSet;

        stringstream iss(str);
        string temp;
        int i = 0;
        while(getline(iss,temp,' ')){
            if(patMap.count(pattern[i]) != 0){
                if(strcmp(patMap[pattern[i]].c_str(), temp.c_str()) != 0){
                    return false;
                }
            } else{
                patMap[pattern[i]] = temp;
                strSet.insert(temp);
            }
            i++;
        }
        return ((patMap.size() == strSet.size()) && i == pattern.size());
    }
};

/* NOTES

This was very similar to the isomorphic strings problem, only that I had to map
each char in the pattern to a substring. I also had to make sure that there were
the same number of words in str as char in pattern.

Runtime: 4 ms, faster than 71.73% of C++ online submissions for Word Pattern.
Memory Usage: 8.5 MB, less than 84.36% of C++ online submissions for Word Pattern.

*/
