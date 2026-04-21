
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            string x = words[i];
            for (int j = 0; j < x.length(); j++) {
                adj[x[j]];
                indeg[x[j]];
            }
        }

        string prev = words[0];
        for (int i = 1; i < words.size(); i++) {
            string x = words[i];
            int l1 = prev.length();
            int l2 = x.length();
            int j;
            for (j = 0; j < min(l1, l2); j++) {
                adj[prev[j]];
                indeg[prev[j]];
                adj[x[j]];
                indeg[x[j]];
                if (prev[j] != x[j]) {
                    if (!adj[prev[j]].count(x[j])) {
                        adj[prev[j]].insert(x[j]);
                        indeg[x[j]]++;
                    }
                    break;
                }
            }
            if(j==min(l1,l2)&& l1!=l2 && j==l2) return ans;
            prev = x;
        }


        queue<char> q;

        for (auto& p : adj) {
            if (!indeg[p.first]) {
                cout << p.first << " ";
                q.push(p.first);
            }
        }

        
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            for (auto x : adj[node]) {
                cout << x;
                indeg[x]--;
                if (indeg[x] == 0)
                    q.push(x);
            }

            ans.push_back(node);
        }
        if(ans.length()==indeg.size())
        return ans;
        else
        return "";
    }
};