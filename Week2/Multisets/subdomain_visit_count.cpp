class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> domCount;
        vector<string> retArr;
        std::string::size_type sz;
        for(int i = 0; i < cpdomains.size(); i++){
            int count = stoi(cpdomains[i], &sz);
            string sub = cpdomains[i].substr(sz+1);
            string temp;
            istringstream iss(sub);
            domCount[sub] += count;
            for(int i = sub.find('.'); i != string::npos; i = sub.find('.')){
                domCount[sub.substr(i+1)] += count;
                sub = sub.substr(i+1);
            }
        }
        for(auto it: domCount){
            retArr.push_back(to_string(it.second) + " " + it.first);
        }
        return retArr;
    }
};
