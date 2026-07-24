class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() ==1) return 1;
        const int MAX = 2048;
        vector<bool> one(MAX, false);
        vector<bool> two(MAX, false);
        vector<bool> three(MAX, false);
        for(int val :nums){
            for(int i=0; i<MAX; i++){
                if(one[i]) two[i^val] = true;
            }
            one[val] = true;
        }

        for(int val :nums){
            for(int i =0; i<MAX; i++){
                if(two[i]) three[i^val] = true;
            }
        }

        int ans =0;
        for(bool exists: three) ans += exists;
        return ans;

    }
};