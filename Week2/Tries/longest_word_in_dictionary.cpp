class Solution {
public:
    struct Node{
        struct Node* children[26];
        bool isLeaf = false;
    };

    struct Node* getNode(){
        struct Node* newNode = new Node();
        for(int i = 0; i < 26; i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    void insert(struct Node* root, string key){
        struct Node* temp = root;
        for(int i = 0; i < key.size(); i++){
            int index = key[i]-'a';
            if(!temp->children[index]){ //if char not in trie
                temp->children[index] = getNode(); // create new node for this char
            }
            temp = temp->children[index];
        }
        //make last node the leaf
        temp->isLeaf = true;
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        int length = 0;
        string retStr;
        struct Node* root = new Node();
        struct Node* temp = root;
        for(int i = 0; i < words.size(); i++){
            //cout << words[i] << endl;
            insert(root, words[i]);
        }
        for(int i = words.size()-1; i >= 0; i--){
            if(words[i].size() >= length){
                for(int j = 0; j < words[i].size(); j++){
                    int index = words[i][j]-'a';
                    if((!temp->children[index]) || !(temp->children[index]->isLeaf)){
                        break;
                    }
                    temp = temp->children[index];
                }
                if(temp != nullptr && temp->isLeaf){
                    if(words[i].size() == length){
                        if(strcmp(words[i].c_str(), retStr.c_str()) < 0){
                            retStr = words[i];
                        }
                    } else{
                        length = words[i].size();
                        retStr = words[i];
                    }
                }
            }
        }
        return retStr;

    }
};

/* NOTES

I believe I have the soluton for this problem even though I am failing a test

*/
