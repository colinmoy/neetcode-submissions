class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.clear();
        visited.clear();
        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1) && visited.size() == n;
    }

private:
    unordered_map<int, vector<int>> adj;
    set<int> visited;

    bool dfs(int n, int prev) {
        if (visited.find(n) != visited.end()) {
            return false;
        }
        visited.insert(n);
        for (int neighbor : adj[n]) {
            if (neighbor == prev) {
                continue;
            }
            if (!dfs(neighbor, n)) {
                return false;
            }
        }
        return true;
    }
};
