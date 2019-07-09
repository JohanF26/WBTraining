class Solution {
public:
    bool isHappy(int n) {
        map<int, int> mymap;
        int temp = n;
        while(++mymap[temp] == 1){
            temp = 0;
            while(n > 0){
                //digit = ((n - ((int) n/10) * 10));
                //temp += (digit*digit); //shifting 1 is like power of 2
                temp += pow(n%10, 2);
                n /= 10;
            }
            if(temp == 1){
                return true;
            }
            n = temp;
        }
        return false;
    }
};

/* NOTES

This problem was fairly simple but I felt that my solution was not too elegant
and needed some improvement. After looking at the discussions I realized I could
simplify my digit parsing. I knew I could use mod to do so but I could not remember
how so that helped.

Commented out version:
Runtime: 4 ms, faster than 80.72% of C++ online submissions for Happy Number.
Memory Usage: 8.5 MB, less than 26.57% of C++ online submissions for Happy Number.

Improved version:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
Memory Usage: 8.5 MB, less than 29.51% of C++ online submissions for Happy Number.

*/
