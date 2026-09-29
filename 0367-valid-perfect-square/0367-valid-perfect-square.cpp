class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 1, high = num;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long sqr = mid * mid;
            if (sqr == num) return true;
            else if (sqr > num) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};