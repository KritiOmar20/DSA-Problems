class Solution {
public:
    long long mergeSort(vector<long long> &pre, int l, int r, int low, int high) {
        if (r - l <= 1) return 0;
        int mid = (l + r) / 2;
        long long ans = mergeSort(pre, l, mid, low, high) +
                        mergeSort(pre, mid, r, low, high);
        int i = mid, j = mid;
        for (int left = l; left < mid; left++) {
            while (i < r && pre[i] - pre[left] < low) i++;
            while (j < r && pre[j] - pre[left] <= high) j++;
            ans += j - i;
        }

        inplace_merge(pre.begin() + l, pre.begin() + mid, pre.begin() + r);
        return ans;
    }

    long long countSubarray(vector<int> &arr, int l, int r) {
        int n = arr.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + arr[i];

        return mergeSort(pre, 0, n + 1, l, r);
    }
};