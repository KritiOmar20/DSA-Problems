class Solution {
public:
    int t[366];
    int solve(vector<int>& days, vector<int>& costs, int& n, int ind){
        if(ind >= n) return 0;
        if (t[ind] != -1) return t[ind];
        int cost = costs[0] + solve(days, costs, n, ind+1);
        int i= ind;
        while(i<n && days[i] < days[ind]+7){
            i++;
        }
        int cost7= costs[1] +solve(days, costs, n, i);
        int j = ind;
        while(j<n && days[j] < days[ind]+30){
            j++;
        }
        int cost30= costs[2] +solve(days, costs, n, j);

        return t[ind] = min({cost, cost7, cost30});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t, -1, sizeof(t));
        int n= days.size();
        return solve(days,costs,n,0);
        
    }
};