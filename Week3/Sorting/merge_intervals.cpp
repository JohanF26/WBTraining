class Solution {
public:

    int myPartition(vector<vector<int>>& intervals, int low, int high){
        vector<int> pivot = intervals[(low+high)/2];
        while(low <= high){
            //lexicographical comparison
            while(intervals[low] < pivot) low++;

            while(intervals[high] > pivot) high--;

            if(low <= high){
                std::swap(intervals[low], intervals[high]);
                low++;
                high--;
            }
        }
        return low;
    }

    void mySort(vector<vector<int>>& intervals, int low, int high){
        int partition = myPartition(intervals, low, high);
        if(low < partition-1){
            mySort(intervals, low, partition-1);
        }
        if(partition < high){
            mySort(intervals, partition, high);
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return vector<vector<int>>(0);
        mySort(intervals, 0, intervals.size()-1);
        int first = intervals[0][0];
        int second = intervals[0][1];
        vector<vector<int>> retArr;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= second){
                second = std::max(intervals[i][1], second);
            } else{
                retArr.push_back(vector<int>(2) = {first, second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        retArr.push_back(vector<int>(2) = {first,second});

        return retArr;
    }
};

/* NOTES

I implemented a quicksort for this problem as well. Using std::sort my performance
was above 90% but using mine it dropped sigfinicantly. I suspect that it is because
using iterators makes the sorting easier. After sorting the arrays in increasing
order all I had to do was to check if the first value of the next pair is less than
the current second value. If it was not then I pushed the current pair into a vector.

Runtime: 28 ms, faster than 34.20% of C++ online submissions for Merge Intervals.
Memory Usage: 23.7 MB, less than 12.30% of C++ online submissions for Merge Intervals.

*/
