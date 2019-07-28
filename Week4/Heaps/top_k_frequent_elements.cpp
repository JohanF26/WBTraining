class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<pair<int,int> > heapArr;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            heapArr.push_back(make_pair(it->second, it->first));
        }
        make_heap(heapArr.begin(), heapArr.end());
        for(int i = 0; i < k; i++){
            ret.push_back(heapArr.front().second);
            pop_heap(heapArr.begin(), heapArr.end()); heapArr.pop_back();
        }
        return ret;

    }
};

/* NOTES

This problem could have also been solved just using sort on heapArr but using a
heap is almost just as good.

Runtime: 20 ms, faster than 83.49% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 11.4 MB, less than 70.47% of C++ online submissions for Top K Frequent Elements.

*/
