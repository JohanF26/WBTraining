class Solution {
public:

    bool isSelfDividing(int num){
        int tempNum = num;
        int currDigit;
        while(tempNum > 10){
            currDigit = tempNum - ((int) (tempNum / 10)) * 10;
            if(currDigit == 0 || num % currDigit != 0) return false;
            tempNum = ((int) (tempNum / 10));
        }
        return (num % tempNum == 0 && tempNum % 10 != 0);
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> retArr;
        for(int i = left; i <= right; i++){
            if(isSelfDividing(i)){
                retArr.push_back(i);
            }
        }
        return retArr;
    }
};

/* NOTES

This problem was a bit tough since I could not think of a way to get the digits
from a given integer. As I laid in bed, an answer immediately came to my mind and
I was able to implement it the next day.

Runtime: 4 ms, faster than 85.33% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 8.2 MB, less than 96.41% of C++ online submissions for Self Dividing Numbers.

*/
