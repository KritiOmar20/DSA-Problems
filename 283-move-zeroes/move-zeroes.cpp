class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                if(nums[count] == 0) {
                    swap(nums[i], nums[count]);
                }
                count++;
            }
        }
    }
};