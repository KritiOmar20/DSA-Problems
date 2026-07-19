class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        for(int i=0;i<s.size();i++) last[s[i]-'a'] =i;
        vector<bool> intStack(26,false);
        string st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(intStack[ch-'a'])  continue;
            while (!st.empty() && st.back() > ch &&last[st.back() - 'a'] > i) {
                intStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            intStack[ch - 'a'] = true;
        }
        return st;
    }
};