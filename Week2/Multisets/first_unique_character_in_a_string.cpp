class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        for(int i = 0; i < s.size(); i++){
            if(s.find(s[i], s.find(s[i])+1) == string::npos){
                return i;
            }
        }
        return -1;
    }
};
