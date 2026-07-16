class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max =0;
        for(auto& i:nums){
            max = ::max(max,i);
            i=gcd(i,max);
        }
        ranges :: sort(nums);
        long long ans = 0;
        for(int j=0, k=nums.size()-1; j<k; j++,k--){
            ans += gcd(nums[j],nums[k]);
        }
        return ans;
    }
};