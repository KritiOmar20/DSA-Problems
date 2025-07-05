class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char , int> mpp;
        int count = 0;
        for(char a : s){
            mpp[a]++;
            if(mpp[a] % 2 == 1)
                count++;
            else 
                count--;
        }

        if(count>1)
            return (s.length() - count + 1);
        return s.length();
    }
};