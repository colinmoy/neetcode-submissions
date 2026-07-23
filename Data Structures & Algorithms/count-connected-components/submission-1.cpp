class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.clear();
        visited.clear();
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int cc = 0;
        for (int i = 0; i < n && visited.size() != n; i++) {
            if (dfs(i)) {
                cc++;
            }
        }
        return cc;
    }

private:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

    bool dfs(int n) {
        if (visited.find(n) != visited.end()) {
            return false;
        }
        visited.insert(n);
        for (int neighbor : adj[n]) {
            dfs(neighbor);
        }
        return true;
    }
};
