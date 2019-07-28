class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int toPush = 0;
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size() != 0){
                toPush = i;
                break;
            }
        }
        queue<int> q;
        vector<int> placement(graph.size(), 0);
        q.push(toPush);
        int i = 0;
        int visited = 0;
        while(visited != graph.size()){
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                visited++;
                if(placement[curr] == 0){
                    placement[curr] = (i%2) + 1;
                }
                for(auto it: graph[curr]){
                    if(placement[it] == 0){
                        placement[it] = (placement[curr] % 2) + 1;
                        //cout << "push " << it << endl;
                        q.push(it);
                    } else if(placement[it] == placement[curr]){
                        return false;
                    }
                }
                i = placement[curr]+1;
            }
             for(int i = 0; i < placement.size(); i++){
                if(placement[i] == 0){
                    q.push(i);
                    break;
                }
            }
        }

        return true;
    }
};

/* NOTES

This problem was a bit challenging for me but once I decided that it would be
better to use BFS to solve it and to color the nodes accordingly, it was fairly
simple. After that I ran into the problem where the graph is not connected so
I decided to add a while loop to make sure that if we have not failed and we
have not visited all nodes then to look for the next node that needs to be
visited.

Runtime: 24 ms, faster than 84.32% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 11.2 MB, less than 58.09% of C++ online submissions for Is Graph Bipartite?.

*/
