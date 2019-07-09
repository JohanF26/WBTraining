class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> retArr;
        vector<int> oddArr;
        for(int i = 0; i < A.size(); i++){
            if(A[i] % 2 == 0){
                retArr.push_back(A[i]);
            } else{
                oddArr.push_back(A[i]);
            }
        }
        retArr.insert(retArr.end(), oddArr.begin(), oddArr.end());
        return retArr;
    }
};

/* NOTES

I thought of adding the vector of odd numbers to the vector to return using a for loop
but after reading the cpp documentation I remembered the insert function uses iterators.

Runtime: 28 ms, faster than 86.92% of C++ online submissions for Sort Array By Parity.
Memory Usage: 10 MB, less than 37.68% of C++ online submissions for Sort Array By Parity.

I would like to learn to make my code faster and lighter.

*/
