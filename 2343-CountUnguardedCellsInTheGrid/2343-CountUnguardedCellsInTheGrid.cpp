// Last updated: 5/28/2025, 9:51:14 PM
class Solution {
public:
    int countUnguarded(int rows, int cols, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        int grid[rows][cols];
        memset(grid, 0, sizeof(grid)); 

        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        int directions[5] = {-1, 0, 1, 0, -1};

        for (auto& guard : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = guard[0], y = guard[1];
                int dx = directions[k],
                    dy = directions[k + 1]; 

                while (x + dx >= 0 && x + dx < rows && y + dy >= 0 &&
                       y + dy < cols && grid[x + dx][y + dy] < 2) {
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    unguardedCount++;
                }
            }
        }
        return unguardedCount;
    }
};