class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int comp = 0;
        while(num != 0){
            int bit = (num & 1)? 0 : 1;
            comp += (1 << i) * bit;
            num = num >> 1;
            i++;
        }
        return comp;
    }
};

/* NOTES

I really struggled with this problem because I could not think of how to get rid
of the leading zeroes.

Runtime: 4 ms, faster than 77.48% of C++ online submissions for Number Complement.
Memory Usage: 8.1 MB, less than 87.12% of C++ online submissions for Number Complement.

*/
