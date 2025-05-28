// Last updated: 5/28/2025, 9:47:55 PM
class Solution {
public:
    int minMoves(vector<string>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        if (grid[0][0] == '#')
            return -1;

        vector<string> copy_grid = grid;
        unordered_map<char, vector<pair<int, int>>> portals;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                char ch = copy_grid[i][j];
                if (ch >= 'A' && ch <= 'Z') {
                    portals[ch].emplace_back(i, j);
                }
            }
        }

        const int INF = numeric_limits<int>::max();
        vector<vector<int>> dist(R, vector<int>(C, INF));
        dist[0][0] = 0;

        vector<bool> used(26, false);
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 0);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            if (d > dist[r][c])
                continue;
            if (r == R - 1 && c == C - 1)
                return d;

            char p = copy_grid[r][c];
            if (p >= 'A' && p <= 'Z' && !used[p - 'A']) {
                used[p - 'A'] = true;
                for (auto& coord : portals[p]) {
                    int rr = coord.first;
                    int cc = coord.second;
                    if (d < dist[rr][cc]) {
                        dist[rr][cc] = d;
                        pq.emplace(d, rr, cc);
                    }
                }
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                    copy_grid[nr][nc] != '#') {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.emplace(d + 1, nr, nc);
                    }
                }
            }
        }

        return -1;
    }
};