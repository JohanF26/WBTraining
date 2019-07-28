class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> q;
        vector<int> retArr;
        k = k%nums.size();
        for(int i = 0; i < k; i++){
            q.push(nums[(nums.size()-k)+i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(i < k){
                retArr.push_back(q.front());
                q.pop();
            } else{
                retArr.push_back(nums[i-k]);
            }
        }
        nums = retArr;

    }
};


/* NOTES

I feel that a queue was not necessary for this problem and it would have been
just as easy if I were to use another vector.

Runtime: 12 ms, faster than 99.50% of C++ online submissions for Rotate Array.
Memory Usage: 10 MB, less than 5.11% of C++ online submissions for Rotate Array.

*/
