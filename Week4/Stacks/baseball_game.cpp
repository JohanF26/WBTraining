class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int score = 0;
        int prevRound = 0;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i].compare("C") == 0){
                score -= st.top();
                st.pop(); //invalid
            } else if(ops[i].compare("D") == 0){
                prevRound = 2 * st.top();
                score += prevRound;
                st.push(prevRound);
            } else if(ops[i].compare("+") == 0){
                int prev = st.top();
                st.pop();
                prevRound = prev + st.top();
                score += prevRound;
                st.push(prev);
                st.push(prevRound);
            } else{
                st.push(stoi(ops[i]));
                score += st.top();
            }
        }
        return score;
    }
};

/* NOTES

This program was fairly simple. At first I had a stack of strings but realized
I was doing redundant work so I switched to a stack of ints and pushed the points
scored each round. It could be improved if I saved all the score updates for the
end.

Runtime: 4 ms, faster than 97.30% of C++ online submissions for Baseball Game.
Memory Usage: 9.5 MB, less than 32.39% of C++ online submissions for Baseball Game.

*/
