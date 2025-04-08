class Solution {
public:
int days(vector<int>&nums,int div){
    int sm = 0;
    int n= nums.size();
    for(int i=0;i<n;i++){
        sm = sm + ceil((double)(nums[i])/(double)(div));
    }
    return sm;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l =1, h = *max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = (l+h)/2;
            if(days(nums,mid)<=threshold){
                h = mid-1;
            }else {
                l = mid+1;
            }
        }
        return l;
    }
};