class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int diff = x ^ y; // xor sets the different bits to 1
        //this loop counts the number of ones in the binary representation
        while(diff != 0){
            diff = diff & (diff-1); //this gets rid of the rightmost 1
            count++;
        }
        return count;
    }
};

/* NOTES

I strugged a bit at first trying to understand this problem but after learning
some bit manipulation tricks I was able to come up with an optimal algorithm

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
Memory Usage: 8.1 MB, less than 86.72% of C++ online submissions for Hamming Distance.

*/
