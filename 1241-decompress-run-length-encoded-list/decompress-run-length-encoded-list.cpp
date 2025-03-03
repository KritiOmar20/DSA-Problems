class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans; 
        for (int i = 0; i < nums.size(); i++) {
            int fre = nums[i++];
            int val = nums[i]; 
            for (int j = 0; j < fre; j++)
                ans.push_back(val);
        }
        return ans;
    }
};