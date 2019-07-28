class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        map<int, vector<vector<int>> > graph;
        vector<int> dist(N+1, INT_MAX);
        set<int> nodesLeft;
        for(int i = 1; i <= N; i++){
            nodesLeft.insert(i);
        }
        for(auto it: times){
            graph[it[0]].push_back({it[1],it[2]});
            //cout << graph[it[0]][0][0] << " " << graph[it[0]][0][1] << endl;
        }


        dist[K] = 0;
        nodesLeft.erase(K);

        int currDist = 0;
        int currK = K;
        while(!nodesLeft.empty()){
            for(auto it: graph[currK]){
                //set distance to the min between the previos stored distance
                //or the distance to this node plus the distance to that node
                dist[it[0]] = min(dist[it[0]], currDist+it[1]);
            }
            currDist = INT_MAX;
            for(auto i: nodesLeft){
                if(dist[i] < currDist){
                    currDist = dist[i];
                    currK = i;
                    //cout << i << endl;
                }
            }
            nodesLeft.erase(currK);
            if(currDist == INT_MAX){
                return -1;
            }
        }

        return currDist;
    }
};

/* NOTES

The one thing that was a bit tedious about this problem was implementing my own
version of Dijkstra's algorithm but after sleeping on it I was able to come up
with a solution.

Runtime: 136 ms, faster than 28.95% of C++ online submissions for Network Delay Time.
Memory Usage: 43.6 MB, less than 12.08% of C++ online submissions for Network Delay Time.

*/
