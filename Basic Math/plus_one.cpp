class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(digits[i] == 9){
            if(i != 0){
                digits[i] = 0;
                i--;
            } else{
                digits[i] = 1;
                digits.push_back(0);
                return digits;
            }
        }
        digits[i]++;
        return digits;
    }
};

/* NOTES

My first solution was wrong since I did not account for numbers that increment
the number of digits (such as 9 or 99) but besides that it was fairly easy.

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 8.6 MB, less than 39.52% of C++ online submissions for Plus One.

*/
