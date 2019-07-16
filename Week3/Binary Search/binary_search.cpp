class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int h){
        if(l <= h){
            int mid = (h+l)/2; //get the index between high and low
            cout << mid << endl;

            if(nums[mid] == target){
                return mid;
            } else if(target < nums[mid]){ //target must be on the left
                return binarySearch(nums, target, l, mid-1);
            } else{ //it must be on the right
                return binarySearch(nums, target, mid+1, h);
            }
        }

        return -1; //not found
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};

/* NOTES

Coming up with this solution was simple once I refreshed what binary search meant
and how it is usually implemented

Runtime: 48 ms, faster than 94.57% of C++ online submissions for Binary Search.
Memory Usage: 11.1 MB, less than 5.12% of C++ online submissions for Binary Search.

*/
