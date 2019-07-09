class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, int> trans;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i = 0; i < words.size(); i++){
            string temp;
            for(int j = 0; j < words[i].size(); j++){
                temp += morse[words[i][j] - 'a'];
            }
            trans[temp]++;
        }
        return trans.size();
    }
};

/* NOTES

This problem was also fairly simple but I would be interested in seeing a better Solution

Runtime: 4 ms, faster than 90.56% of C++ online submissions for Unique Morse Code Words.
Memory Usage: 9 MB, less than 58.01% of C++ online submissions for Unique Morse Code Words.

*/
