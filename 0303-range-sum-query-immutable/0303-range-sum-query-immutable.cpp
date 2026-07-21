class NumArray {
public:
    int n;
    vector<int> segmentTree;
    void buildSegmentTree(int l, int r, vector<int> &nums,int i,vector<int> &segmentTree){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l)/2;
        buildSegmentTree(l,mid,nums,2*i+1,segmentTree);
        buildSegmentTree(mid+1,r,nums,2*i+2,segmentTree);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

     int query(int start,int end,int i,int l, int r,vector<int> &segTree){
        if(l > end || r < start)    return 0;
        if(l >= start && r <= end)  return segTree[i];
        else{
            int mid = l + (r - l) / 2;
            return query(start,end,2*i+1,l,mid,segTree) + query(start,end,2*i+2,mid+1,r,segTree);
        }
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,n-1,nums,0,segmentTree);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1,segmentTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */