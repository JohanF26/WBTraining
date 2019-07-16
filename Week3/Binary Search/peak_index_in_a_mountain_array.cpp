class Solution {
public:
    int binSearch(vector<int>& A, int l, int h){
        int mid = (l+h)/2;
        if(A[mid] < A[mid+1]){
            return binSearch(A, mid+1, h);
        } else if(A[mid] < A[mid-1]){
            return binSearch(A, l, mid-1);
        } else{
            return mid;
        }
    }

    int peakIndexInMountainArray(vector<int>& A) {
        return binSearch(A, 1, A.size()-2);
    }
};

/* NOTES

Once I understood how Binary Search works I was able to come up with a simple
solution applying the same ideas. Since we are looking for the max value I
basically said: If the current middle value is less than the one on the right
then it must be on the right, otherwise, if it is less than the one on the left
then it must be on the left. If neither of those conditions passed then we must
be in the max value.

Runtime: 12 ms, faster than 97.40% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 9.8 MB, less than 5.32% of C++ online submissions for Peak Index in a Mountain Array.

*/
