class Solution {
public:
    bool detectCapitalUse(string word) {
        // A = 65
        // Z = 90
        int i = 0;
        if(word[i] > 96){
            //if first char is lowercase then the rest must also be lowercase
            i++;
            while(i < word.size()){
                if(word[i] < 91){
                    return false;
                }
                i++;
            }
            return true;
        } else if(word.size() > 1){
            i = 2;
            //if first is capital
            if(word[0] > 64 && word[0] < 91){
                //and second is also capital then the rest must be capital
                if(word[1] > 64 && word[1] < 91){
                    while(i < word.size()){
                        if(word[i] > 96){
                            return false;
                        }
                        i++;
                    }
                    return true;
                } else{
                    while(i < word.size()){
                        if(word[i] < 91){
                            return false;
                        }
                        i++;
                    }
                    return true;
                }
            }
        }
        return true;
    }
};

/* NOTES

While this one was not very difficult I struggled to find an answer shorter than
this one.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
Memory Usage: 8.2 MB, less than 56.13% of C++ online submissions for Detect Capital.

*/
