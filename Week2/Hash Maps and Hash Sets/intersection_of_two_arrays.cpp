class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> seen;
        set<int> retArr;
        for(auto it: nums1){
            seen.insert(it);
        }
        for(auto it: nums2){
            if(seen.find(it) != seen.end()){ //if it is also in nums1
                retArr.insert(it);
            }
        }
        return vector(retArr.begin(), retArr.end());

    }
};

/* NOTES

At first I tried pushing the elements found in both into a vector but this resulted
in repeated numbers so I used a set instead and then transformed it into a vector.

Runtime: 8 ms, faster than 85.96% of C++ online submissions for Intersection of Two Arrays.
Memory Usage: 9.7 MB, less than 18.27% of C++ online submissions for Intersection of Two Arrays.

*/
