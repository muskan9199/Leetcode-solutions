class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;
        vector<int> moves(N + 1, -1);

        for (int i = 0; i < lad.size(); i += 2) {
            moves[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            moves[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(N + 1, false);
        queue<pair<int, int>> q;

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int u = curr.first;
            int dist = curr.second;

            if (u == N) return dist;

            for (int dice = 1; dice <= 6; ++dice) {
                int v = u + dice;
                if (v <= N) {
                    int next_cell = (moves[v] != -1) ? moves[v] : v;
                    if (!visited[next_cell]) {
                        visited[next_cell] = true;
                        q.push({next_cell, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna