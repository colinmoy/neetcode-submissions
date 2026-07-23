class DJS {
    public:
        vector<int> arr;

        DJS(int n) {
            arr = vector<int>(n, -1);
        }

        int find(int ind) {
            if (arr[ind] < 0) {
                return ind;
            }
            return find(arr[ind]);
        }

        void join(int x, int y) {
            int a = find(x), b = find(y);
            if (a == b) {
                return;
            }
            if (arr[a] <= arr[b]) {
                arr[a] += arr[b];
                arr[b] = a;
            } else {
                arr[b] += arr[a];
                arr[a] = b;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DJS set(edges.size());
        vector<int> result;
        for (vector<int> edge : edges) {
            if (set.find(edge[0] - 1) == set.find(edge[1] - 1)) {
                result = edge;
            }
            set.join(edge[0] - 1, edge[1] - 1);
        }
        return result;
    }
};
