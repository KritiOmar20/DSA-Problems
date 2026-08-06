class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int doubles = 0;
        for (int x : arr) {
            increments += __builtin_popcount(x);

            int bits = 0;
            while (x) {
                bits++;
                x >>= 1;
            }

            doubles = max(doubles, max(0, bits - 1));
        }

        return increments + doubles;
    }
};