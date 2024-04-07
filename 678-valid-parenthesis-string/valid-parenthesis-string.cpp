class Solution {
public:
    bool checkValidString(string s) {
        int curr = 0; 
        int total = 0; 
        for (auto ch : s) {
            if (ch == '(') {
                curr++;
                total++;
            } else if (ch == ')') {
                curr--;
                total--;
            } else {
                curr--;
                total++;
            }
            if (curr < 0) curr = 0; 
            if (total < 0) return false; 
        }
        return curr == 0;
    }
};