class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt =0, maxi =0;
        for(int val: gain){
            alt += val;
            maxi = max(maxi, alt);
        }
        return maxi;
    }
};