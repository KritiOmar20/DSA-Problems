class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int r = 1;
        for (int num : temp) {
            //store rank in map
            if (!rank.count(num)) {
                rank[num] = r++;
            }
        }//assign ranks in original array
        for (int &num : arr) {
            num = rank[num];
        }
        return arr;
    }
};