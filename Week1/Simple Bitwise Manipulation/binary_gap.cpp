class Solution {
public:
    int binaryGap(int N) {
        int i = 0; // first bit
        int j = -1; // second bit
        int maxGap = 0; //max gap
        if(N == 0 || N & (N-1) == 0) return 0; //because if it is a power of 2 then there is one 1
        while((N >> i) > 0){
            int temp = 1 << i;
            if((N & temp) != 0){ //if the i bit == 1
                if(j != -1){
                    maxGap = max(maxGap, i-j);
                }
                j = i;
            }
            i++;
        }
        return maxGap;
    }
};

/* NOTES

I knew the solution to this problem I just thought it would take long so I did not
bother on implemeting it. After giving it some thought I realized that it was a
good algorithm to use and went ahead. Turns out it was one of the best if not the
best algorithm for this problem.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Gap.
Memory Usage: 8.3 MB, less than 26.10% of C++ online submissions for Binary Gap.

*/
