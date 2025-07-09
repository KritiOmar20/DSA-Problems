class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
         int n = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> val(n,0);
        for(int num : nums){
            val[num] += num;
        }
        int take =0, notTake =0;
        for(int i=0; i<n; i++){
            int takei = notTake + val[i];
            int notTakei = max(notTake, take);
            take = takei;
            notTake = notTakei;
        }
        return max(take, notTake);
    }
};