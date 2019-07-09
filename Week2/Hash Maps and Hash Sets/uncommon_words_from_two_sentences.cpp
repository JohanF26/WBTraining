class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss1(A);
        stringstream ss2(B);
        string temp;
        vector<string> retArr;
        map<string, int> mymap;

        while(getline(ss1, temp, ' ')){
            mymap[temp]++;
        }
        while(getline(ss2, temp, ' ')){
            mymap[temp]++;
        }
        for(auto it = mymap.begin(); it != mymap.end(); it++){
            if(it->second == 1){
                retArr.push_back(it->first);
            }
        }
        return retArr;
    }
};

/* NOTES

This problem was also fairly simple, at first I was using istream_iterator in order
to create vectors of strings separated by space but later discovered I could use
getline along with a buffer

Runtime: 4 ms, faster than 84.24% of C++ online submissions for Uncommon Words from Two Sentences.
Memory Usage: 9 MB, less than 38.99% of C++ online submissions for Uncommon Words from Two Sentences.

*/
