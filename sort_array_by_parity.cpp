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
