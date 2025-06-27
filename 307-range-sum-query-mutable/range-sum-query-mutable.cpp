class NumArray {
public:
    int N = 0;
    vector<int>segTree;
    NumArray(vector<int>& nums) {
        N = nums.size();
        segTree.resize(2 * N + 1);   
        for (int i = 0; i < N; i++)
        {
            segTree[N + i] = nums[i];
        }
        for (int i = N - 1; i > 0; i--)
        {
            segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
        } 
    }
    
    void update(int index, int val) {
        index += N;
        segTree[index] = val;
        while (index > 1)
        {
            index /= 2;
            segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
        }
    }
    
    int sumRange(int left, int right) {
        left += N;
        right += N;
        int sum = 0;
        while (left <= right)
        {
            if (left & 1)
            {
                sum += segTree[left];
                left++;
            }
            if (!(right & 1))
            {
                sum += segTree[right];
                right--;
            }
            left = left >> 1;
            right = right >> 1;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */