class Solution {
public:
    int myPartition(string& s, int low, int high){
        char pivot = s[(low+high)/2]; //get the middle char
        while(low <= high){
            //look for char on the left that should not be there
            while(s[low] < pivot) low++;

            //look for char on the right that should not be there
            while(s[high] > pivot) high--;

            //if the char that you found are on incorrect sides
            if(low <= high){
                //swap them
                std::swap(s[low],s[high]);
                low++;
                high--;
            }
        }

        return low;
    }

    void mySort(string& s, int low, int high){
        int partition = myPartition(s, low, high); //get the index of the pivot
        if(low < partition-1){
            mySort(s, low, partition-1);
        }
        if(partition < high){
            mySort(s, partition, high);
        }
    }

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        mySort(s, 0, s.size()-1);
        mySort(t, 0, t.size()-1);

        return (strcmp(s.c_str(), t.c_str()) == 0);
    }
};

/* NOTES

Once I learned how quicksort works and I looked at some sample implementations
I was able to implement it from memory and get the right result, even though
it does not have the best runtime since I am choosing the middle char every time.

Runtime: 16 ms, faster than 58.16% of C++ online submissions for Valid Anagram.
Memory Usage: 9.6 MB, less than 24.22% of C++ online submissions for Valid Anagram.

*/
