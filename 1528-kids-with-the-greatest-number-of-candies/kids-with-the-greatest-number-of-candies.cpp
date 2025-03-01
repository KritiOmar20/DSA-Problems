class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int greatest = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(int i=0; i<n; i++){
            if(candies[i]+extraCandies >= greatest){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};