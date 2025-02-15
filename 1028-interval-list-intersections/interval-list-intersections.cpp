class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0,j=0;
        int n1 = firstList.size();
        int n2 = secondList.size();
        while(i<n1 && j<n2){
            if(secondList[j][0] <= firstList[i][1] && firstList[i][0] <= secondList[j][1]){
                // Calculate the start and end of the intersection
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                ans.push_back({start, end});
            }
            // Move the pointer that has the smaller endpoint, just increasing if the next interval will in the current highest range 
            // so we incremnet the smallest
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};