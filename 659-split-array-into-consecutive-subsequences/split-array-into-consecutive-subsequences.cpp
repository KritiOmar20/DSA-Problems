class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }
        // Try to assign numbers greedily
        for (int num : nums) {
            if (freq[num] == 0) continue;
            freq[num]--;

            // Case 1: Append to existing subsequence
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            }
            // Case 2: Start new subsequence
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            // Not possible
            else {
                return false;
            }
        }

        return true;
    }
};