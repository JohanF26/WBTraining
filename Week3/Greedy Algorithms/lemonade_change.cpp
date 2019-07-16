class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bills5 = 1, bills10 = 0; //20 isnt used for change so no need to track
        if(bills[0] != 5) return false;
        for(int i = 1; i < bills.size(); i++){
            if(bills[i] == 5){
                bills5++;
            } else {
                if(bills5 == 0) return false;
                if(bills[i] == 10){
                    bills5--;
                    bills10++;
                } else { //if 20
                    if(bills10 == 0){
                        if(bills5 >= 3){
                            bills5 -= 3;
                        } else{
                            return false;
                        }
                    } else{
                        bills10--;
                        bills5--;
                    }
                }
            }
        }
        return true;
    }
};

/* NOTES

This problem was fairly easy if approached the same way you would if you were
running a lemonade stand.

Runtime: 16 ms, faster than 85.00% of C++ online submissions for Lemonade Change.
Memory Usage: 9.7 MB, less than 50.51% of C++ online submissions for Lemonade Change.

*/
