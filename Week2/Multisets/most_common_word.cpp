class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banSet(banned.begin(), banned.end());
        int count = 0;
        multiset<string> wordSet;
        string temp;
        string finalWord;
        for(int i = 0; i < paragraph.size(); i++){
            if(!isalpha(paragraph[i])){
                paragraph[i] = ' ';
            } else{
                paragraph[i] = tolower(paragraph[i]);
            }
        }
        cout << paragraph << endl;
        istringstream iss(paragraph);

        while(getline(iss, temp, ' ')){
            wordSet.insert(temp);
        }
        for(auto it: banSet){
            wordSet.erase(it);
        }
        for(auto it: wordSet){
            if(wordSet.count(it) > count && it != ""){
                count = wordSet.count(it);
                finalWord = it;
            }
        }
        return finalWord;
    }
};

/* NOTES

I could not think at the moment of how to improve the runtime for this problem,
mainly because I have never dealt with multisets before.

*/
