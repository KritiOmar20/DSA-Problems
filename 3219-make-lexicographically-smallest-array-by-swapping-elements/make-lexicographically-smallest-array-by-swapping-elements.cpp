class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n= nums.size();
        vector<pair<int,int>>Arr;
        for(int i=0;i<n;i++){
            Arr.push_back({nums[i],i});
        }
        sort(Arr.begin(),Arr.end());
        int left = 0,right = 1;
        while(right<n){
            vector<int>idx;
            idx.push_back(Arr[left].second);
            while(right<n && abs(Arr[right].first-Arr[right-1].first)<=limit){
                idx.push_back(Arr[right].second);
                right++;
            }
            sort(idx.begin(),idx.end());
            for(int i=0;i<idx.size();i++){
                nums[idx[i]] = Arr[i+left].first;
            }
            left = right;
            right++;
        }

        return nums;
    }
};