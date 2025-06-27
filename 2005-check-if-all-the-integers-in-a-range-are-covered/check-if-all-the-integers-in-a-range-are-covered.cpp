class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0); 
        for (auto& range : ranges) {
            diff[range[0]] += 1;
            diff[range[1] + 1] -= 1;
        }
        vector<int> prefix(52, 0);
        for (int i = 1; i <= 51; ++i) {
            prefix[i] = prefix[i - 1] + diff[i];
        }
        for (int i = left; i <= right; ++i) {
            if (prefix[i] == 0) return false;
        }
        return true;
    }
};