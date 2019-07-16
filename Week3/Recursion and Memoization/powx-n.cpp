class Solution {
public:

    double myPow(double x, int n) {
        unsigned int power;
        if(n < 0){
            power = n;
            power *= -1;
        } else{
            power = n;
        }

        double result;

        if(power == 0){
            result = 1;
        } else if(power%2 == 0){
            result = myPow(x, power/2);
            result*= result;
        } else{
            result = x * myPow(x, power-1);
        }

        if(n < 0){
            return 1/result;
        } else{
            return result;
        }
    }
};

/* NOTES

I struggled a bit with this problem because I could not figure out how to deal
with negative numbers, specially with the smallest negative number since I could
not cast it directly to a positive int

Runtime: 4 ms, faster than 72.85% of C++ online submissions for Pow(x, n).
Memory Usage: 8.4 MB, less than 51.99% of C++ online submissions for Pow(x, n).

*/
