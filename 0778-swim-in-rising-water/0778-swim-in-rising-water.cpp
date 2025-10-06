class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> visited(n, vector<int>(n, 0));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        pq.push({grid[0][0], {0,0}});
        visited[0][0] = 1;
        int ans = 0;

        while(!pq.empty()) {
            auto [time, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;
            ans = max(ans, time);

            if (r == n-1 && c == n-1)
                return ans;

            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr>=0 && nc>=0 && nr<n && nc<n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return ans;
    }
};
