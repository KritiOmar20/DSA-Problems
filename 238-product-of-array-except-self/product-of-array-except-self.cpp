class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int prod = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0){
                prod *= nums[i];
            }
            else{
                count++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (count == 1){
                if (nums[i] != 0){
                    nums[i] = 0;
                }
                else{
                    nums[i] = prod;
                }
            }else if(count>1){
                nums[i]=0;
            }else{
                nums[i]=prod/nums[i];
            }
        }
        return nums;
    }
};