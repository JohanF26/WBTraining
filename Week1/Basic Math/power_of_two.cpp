class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1){
            return true;
        } else if(n % 2 == 0 && n != 0){
            return isPowerOfTwo((int)n/2);
        } else {
            return false;
        }
    }
};

/* NOTES

This problem was fairly easy but I felt that my answer could be improved using
some library functions and I was correct. After coming up with this I found a
much simpler solution online which uses log2 from math.h instead of recursion.

https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/

*/
