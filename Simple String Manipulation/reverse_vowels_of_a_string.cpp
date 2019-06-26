class Solution {
public:
    bool isVowel(char c){
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
            return false;
        }
        return true;
    }

    string reverseVowels(string s) {
        int front = 0;
        int back = s.size()-1;
        while(back > front){
            char temp = s[front];
            while(!isVowel(temp) && back > front){
                temp = s[++front];
            }
            temp = s[back];
            while(!isVowel(temp) && back > front){
                temp = s[--back];
            }
            if(back != front){
                std::swap(s[front], s[back]);
                front++;
                back--;
            }
        }
        return s;
    }
};


/* NOTES

I decided to implement the system I discussed in the previous problem of having
a front and a back iterator and that made answering this problem simpler

Runtime: 8 ms, faster than 96.22% of C++ online submissions for Reverse Vowels of a String.
Memory Usage: 9.8 MB, less than 85.16% of C++ online submissions for Reverse Vowels of a String.

*/
