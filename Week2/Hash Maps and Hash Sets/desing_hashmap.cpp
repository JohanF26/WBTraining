class MyHashMap {
private:
    vector<pair<int,int>> mymap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        for(auto it = mymap.begin(); it != mymap.end(); it++){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        mymap.push_back(pair<int,int>(key,value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(auto it: mymap){
            if(it.first == key) return it.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(auto it = mymap.begin(); it != mymap.end(); it++){
            if(it->first == key){
                mymap.erase(it);
                return;
            }
        }
    }
};

/* NOTES

The runtime for this problem was horrible but I know I could improve it if I
took advantage of the upper and lower bounds for the ints. This would make
putting, getting, and removing elements easier since I would not need to loop
over the vector. I will improve this later.

*/
