using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
            if (freq[num] > arr.size() / 2) {
                return num;
            }
        }
        return -1;
    }
};