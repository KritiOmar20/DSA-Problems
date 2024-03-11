class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char,int> mpp;
        for(auto i:s){
            mpp[i]++;
        }
        for(auto i:order){  
            if(mpp.find(i)!=mpp.end()){
                while(mpp[i]!=0){
                    ans+=i;
                    mpp[i]--;
                }
            }
        }
        for(auto i:mpp){
            while(i.second!=0){
                ans+=i.first;
                i.second--;
            }
        }
        return ans; 
    }
};