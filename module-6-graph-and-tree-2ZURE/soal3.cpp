#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    int sr, sc, fr, fc;
    cin >> sr >> sc >> fr >> fc;

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pair<int,int>> q;

    visited[sr][sc] = true;
    q.push({sr, sc});

    vector<vector<int>> dist(R, vector<int>(C, -1));
    dist[sr][sc] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == fr && c == fc) {
            cout << dist[r][c] << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C
                && !visited[nr][nc] && grid[nr][nc] == 0) {
                visited[nr][nc] = true;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
