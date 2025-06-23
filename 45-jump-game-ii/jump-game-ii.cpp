class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0, end=0, longest =0;
        for(int i=0; i<nums.size()-1;i++){
            longest = max(longest,i+nums[i]);

            if(i == end){
                jump++;
                end = longest;
            }
        }
        return jump;
    }
};