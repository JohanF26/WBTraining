#include <vector>

class Solution {
public:
    string reverseWords(string s) {
        string retString;
        std::istringstream iss(s);
        vector<string> wordList((istream_iterator<string>(iss)), istream_iterator<string>());

        for(int w = 0; w < wordList.size(); w++){
            for(int i = 0; i < wordList[w].size()/2; i++){
                std::swap(wordList[w][i], wordList[w][wordList[w].size()-i-1]);
            }
            if(w < wordList.size()-1){
                retString.append(wordList[w] + " ");
            } else{
                retString.append(wordList[w]);
            }
        }
        return retString;
    }
};

/* NOTES

My solution is not efficient at all since I have to constantly append strings
and I am using a nested for loop but I will work on finding a faster solution
later.

Runtime: 28 ms, faster than 39.76% of C++ online submissions for Reverse Words in a String III.
Memory Usage: 17.8 MB, less than 10.09% of C++ online submissions for Reverse Words in a String III.

*/
