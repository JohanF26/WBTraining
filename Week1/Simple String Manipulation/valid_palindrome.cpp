class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> letters;
        for(int i = 0; i < s.size(); i++){
            //lowercase or num
            if((s[i] > 96 && s[i] < 123) || (s[i] > 47 && s[i] < 58)){
                letters.push_back(s[i]);
            } else if( s[i] > 64 && s[i] < 91){ //uppercase
                //32 is difference between "A" and "a"
                letters.push_back(s[i]+32);
            }
        }
        for(int i = 0; i < letters.size()/2; i++){
            if(letters[i] != letters[letters.size()-i-1]){
                return false;
            }
        }
        return true;
    }
};

/* NOTES

There is definitely a faster way of doing this but this was the solution I came
up with first, I will be attempting to create another solution that iterates
the string from the front and back and stops when the difference between the iterators
is 2 or less (since the middle letter would not matter).

Runtime: 12 ms, faster than 62.74% of C++ online submissions for Valid Palindrome.
Memory Usage: 9.9 MB, less than 5.03% of C++ online submissions for Valid Palindrome.

*/
