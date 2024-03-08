class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mpp;
        int maxi = 0;
        for(int i = 0 ; i < nums.size(); i++){
            mpp[nums[i]]++;
            maxi = max(maxi,mpp[nums[i]]);
        }
        int cnt = 0;
        for(auto it : mpp){
            if(it.second == maxi){
                cnt += maxi;
            }
        }
        return cnt;
    }
};