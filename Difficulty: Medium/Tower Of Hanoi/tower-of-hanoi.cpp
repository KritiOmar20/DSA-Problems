class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0)
            return 0;
        int left = towerOfHanoi(n - 1, from, aux, to);
        int right = towerOfHanoi(n - 1, aux, to, from);
        return left + 1 + right;
    }
};