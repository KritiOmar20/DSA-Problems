class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini =0;
        int prefix = 0;
        for(int num : nums){
            prefix += num;
            mini = min(mini, prefix);
        }
        return mini < 0 ? abs(mini)+1 :1;
    }
};