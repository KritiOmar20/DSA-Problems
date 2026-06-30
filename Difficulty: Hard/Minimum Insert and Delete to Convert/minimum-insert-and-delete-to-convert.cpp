class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> pos;
        for (int i = 0; i < b.size(); i++) pos[b[i]] = i;

        vector<int> lis;
        for (int x : a) {
            auto it = pos.find(x);
            if (it == pos.end()) continue;
            int idx = it->second;
            auto p = lower_bound(lis.begin(), lis.end(), idx);
            if (p == lis.end())
                lis.push_back(idx);
            else
                *p = idx;
        }

        int lcs = lis.size();
        return (a.size() - lcs) + (b.size() - lcs);
    }
};