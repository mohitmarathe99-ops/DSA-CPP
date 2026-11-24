class Solution {
private:
    void dfs(int node, vector<vector<int>>& ls, vector<int>& vis) {
        vis[node] = 1;
        for (int neighbor : ls[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, ls, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> ls(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ls[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, ls, vis);
            }
        }
        return cnt;
    }
};