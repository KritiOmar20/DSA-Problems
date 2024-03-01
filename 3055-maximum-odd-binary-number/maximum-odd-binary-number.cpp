class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<char>ans(s.size() ,'0');
        int j=0;
        for(int i=0;i<s.length() ; i++){
            if(s[i]== '1'){
                ans[j++]=s[i];
            }
        }
        string s1="";
        swap(ans[j-1],ans[s.size()-1]);
        for(auto x :ans){
            s1+=x;
        }
        return s1;
    }
};