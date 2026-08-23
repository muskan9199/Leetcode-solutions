class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#') return 0;

        vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(m, {1e9, 1e9}));
        priority_queue<tuple<int, int, int, int>, 
                       vector<tuple<int, int, int, int>>, 
                       greater<tuple<int, int, int, int>>> pq;

        dist[r][c] = {0, 0};
        pq.push({0, 0, r, c});

        int visitedCount = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [up, down, cr, cc] = pq.top();
            pq.pop();

            if (visited[cr][cc]) continue;
            visited[cr][cc] = true;
            visitedCount++;

            for (int i = 0; i < 4; ++i) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.') {
                    int nup = up + (i == 0 ? 1 : 0);
                    int ndown = down + (i == 1 ? 1 : 0);

                    if (nup <= u && ndown <= d) {
                        if (make_pair(nup, ndown) < dist[nr][nc]) {
                            dist[nr][nc] = {nup, ndown};
                            pq.push({nup, ndown, nr, nc});
                        }
                    }
                }
            }
        }

        return visitedCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna