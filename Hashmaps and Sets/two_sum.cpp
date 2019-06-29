class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        vector<int> retArr;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mymap.count(diff) > 0){ //if number with inded of diff is in map
                retArr.push_back(i); //then current index is an answer
                retArr.push_back(mymap[diff]); //as well as the index in the map
                break;
            } else{
                mymap[nums[i]] = i; //else store the index in the map
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

Runtime: 8 ms, faster than 96.29% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 27.18% of C++ online submissions for Two Sum.

*/
