class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity) {
    int D = 1;      // Start on day 1
    int ship = 0;
    
    for (int weight : weights) {
        // If adding this package exceeds the capacity, start a new day.
        if (ship + weight > capacity) {
            D++;
            ship = weight;
            // If we exceed the allowed number of days, return false.
            if (D > days) {
                return false;
            }
        } else {
            ship += weight;
        }
    }
    return true; // All packages can be shipped within days.
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
        int mid = left + (right - left) / 2;
        // If mid is a valid capacity, try to find a smaller valid capacity.
        if (canShip(weights, days, mid)) {
            right = mid;
        } else {
            // Otherwise, increase the capacity.
            left = mid + 1;
        }
    }
    return left;
    }
};