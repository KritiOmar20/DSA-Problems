class Solution {
public:
    string mini;

    void solve(int i, string curr, string& target, vector<int>& count) {
        int n = target.size();

        if (i == n) return;
        int x = target[i] - 'a';

        if (count[x] > 0) {
            count[x]--;
            solve(i + 1, curr + target[i], target, count);
            count[x]++;
        }
        for (int j = x + 1; j < 26; j++) {

            if (count[j] > 0) {
                count[j]--;
                string temp = curr + char('a' + j);
                for (int k = 0; k < 26; k++) {
                    while (count[k] > 0) {
                        temp += char('a' + k);
                        count[k]--;
                    }
                }

                mini = min(mini, temp);
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        sort(s.rbegin(), s.rend());
        if (s <= target)
            return "";
        mini = s;
        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        solve(0, "", target, count);

        return mini;
    }
};