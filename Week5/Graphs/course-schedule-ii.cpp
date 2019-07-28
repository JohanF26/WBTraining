class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        if(prerequisites.size() == 0){
            order = vector<int>(numCourses);
            std::iota(order.begin(), order.end(), 0);
            return order;
        }
        //list of courses with a list of courses that depend on it
        vector<vector<int>> adjList(numCourses, vector<int>());
        //list to track how many courses the current one depends on
        vector<int> outDegree(numCourses, 0);
        //queue to process order of classes
        queue<int> q;
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            outDegree[it[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(outDegree[i] == 0){
                q.push(i);
                order.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it: adjList[curr]){
                outDegree[it]--;
                if(outDegree[it] == 0){
                    q.push(it);
                    order.push_back(it);
                }
            }
        }

        if(order.size() == numCourses){
            return order;
        }
        return vector<int>();

    }
};

/* NOTES

This problem was very similar to course schedule one and since I had already
used topographic ordering to solve the problem it was fairly easy to find the
order courses should be taken in since it is the same order in which I was
pushing numbers to the queue.

Runtime: 28 ms, faster than 55.41% of C++ online submissions for Course Schedule II.
Memory Usage: 14.1 MB, less than 41.33% of C++ online submissions for Course Schedule II.

*/
