class Solution {
public:
    int myPartition(vector<int>& nums, int low, int high){
        int pivot = nums[(low+high)/2];
        while(low <= high){
            while(nums[low] < pivot) low++;

            while(nums[high] > pivot) high--;

            if(low <= high){
                std::swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }
        return low;
    }

    void mySort(vector<int>& nums, int low, int high){
        int partition = myPartition(nums, low, high);
        if(low < partition-1){
            mySort(nums, low, partition-1);
        }
        if(partition < high){
            mySort(nums, partition, high);
        }
    }

    int arrayPairSum(vector<int>& nums) {
        mySort(nums, 0, nums.size()-1);
        int min = 0;
        for(int i = 0; i < nums.size(); i+=2){
            min += nums[i];
        }
        return min;
    }
};

/* NOTES
Once I got used to creating a quicksort from scratch I was able to implement one
for this problem fairly quickly. I noticed that in order to maximize the sum of
the min of pairs I must get rid of as many small values as possible so I sorted
in ascending order. In the example [1,3,2,4] by sorting in order I get rid of 2
and allows me to use the second largest number in the array.

Runtime: 68 ms, faster than 91.59% of C++ online submissions for Array Partition I.
Memory Usage: 11.4 MB, less than 11.64% of C++ online submissions for Array Partition I.

*/
