class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> countMap;
        vector<int> retArr(2,0);
        for(int i = 0; i < nums.size(); i++){
            countMap[nums[i]]++;
        }
        for(int i = 1; i <= nums.size(); i++){
            if(countMap.count(i) > 0){
                if(countMap[i] == 2){
                    retArr[0] = i;
                }
            } else{
                retArr[1] = i;
            }
        }
        return retArr;
    }
};

/* NOTES

this is another problem I need to find a faster way of solving, I struggled to
improve its runtime or using a multisets

*/
