class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        vector<int> retArr;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mymap.count(diff) > 0){
                retArr.push_back(i);
                retArr.push_back(mymap[diff]);
                break;
            } else{
                mymap[nums[i]] = i;
            }
        }
        return retArr;
    }
};

/* NOTES

At first I struggled to come up with an answer to this but then I realized
I could store the index of the numbers in the array using their values as keys
and use the difference between the target and the current number as a key
to the map to find the index that produced that value.

Runtime: 12 ms, faster than 74.70% of C++ online submissions for Two Sum.
Memory Usage: 10.1 MB, less than 44.92% of C++ online submissions for Two Sum.

*/
