class Solution {
    struct Node {
        Node* child[26];
        int cnt;

        Node() {
            cnt = 0;
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(const string& s) {
        Node* cur = root;

        for (char ch : s) {
            int idx = ch - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new Node();

            cur = cur->child[idx];
            cur->cnt++;
        }
    }

    string uniquePrefix(const string& s) {
        Node* cur = root;
        string pref;

        for (char ch : s) {
            int idx = ch - 'a';
            cur = cur->child[idx];
            pref.push_back(ch);

            if (cur->cnt == 1)
                break;
        }

        return pref;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        for (auto& s : arr)
            insert(s);

        vector<string> ans;
        for (auto& s : arr)
            ans.push_back(uniquePrefix(s));

        return ans;
    }
};