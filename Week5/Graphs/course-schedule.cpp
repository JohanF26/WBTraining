class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        //list that contains a list of courses that depend on ith course
        vector<vector<int>> adjList(numCourses, vector<int>());
        //list to track how many courses the current one depends on
        vector<int> outDegree(numCourses, 0);
        queue<int> q;
        int taken = 0;
        for(auto it: prerequisites){
            outDegree[it[0]]++;
            adjList[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < numCourses; i++){
            //if ith course does not depend on anything
            if(outDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            //cout << "course#: " << curr << endl;
            q.pop();
            taken++;
            for(auto it: adjList[curr]){
                //curr was popped so one less dependency for "it"
                outDegree[it]--;
                if(outDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        //if there is a cycle the q will be empty before taken == numCourses
        //cout << "taken: " << taken << endl;
        return taken == numCourses;
    }
};

/* NOTES

This problem was a bit challenging because I did not know what topographic ordering
was and trying to solve it any other way was a bit tedious since I was using a list
of edges instead of nodes I could mark. I could have created nodes and mark them
but that would have taken longer to process.

Runtime: 20 ms, faster than 88.69% of C++ online submissions for Course Schedule.
Memory Usage: 13.6 MB, less than 52.14% of C++ online submissions for Course Schedule.

*/
