class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> retArr;
        for(int i = 1; i <= n; i++){
            if(i % 15 == 0){
                retArr.push_back("FizzBuzz");
            } else if(i % 5 == 0){
                retArr.push_back("Buzz");
            } else if(i % 3 == 0){
                retArr.push_back("Fizz");
            } else{
                retArr.push_back(std::to_string(i));
            }
        }
        return retArr;
    }
};

/* NOTES

This problem was fairly simple and was able to come up with a solution within
seconds.

Runtime: 4 ms, faster than 98.52% of C++ online submissions for Fizz Buzz.
Memory Usage: 10.4 MB, less than 28.49% of C++ online submissions for Fizz Buzz.

*/
