class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int pas[1001] = {0}; 
        for (auto& trip : trips) {
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];

            pas[from] += num;  
            pas[to] -= num;   
        }
        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += pas[i];
            if (curr > capacity)
                return false;
        }
        return true;
    }
};