class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
    void helper(vector<char>& s, int start, int end) {
        if(start >= end) return; 
        swap(s[start], s[end]);           
        helper(s, start + 1, end - 1);    
    }
};