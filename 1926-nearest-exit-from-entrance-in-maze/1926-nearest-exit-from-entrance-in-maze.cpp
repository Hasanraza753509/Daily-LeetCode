class Solution {
public:
   int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size();
    int m = maze[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int sr = entrance[0];
    int sc = entrance[1];

    q.push({{sr, sc}, 0});
    vis[sr][sc] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        // Check whether this is an exit, excluding the entrance
        if ((row == 0 || row == n - 1 ||
             col == 0 || col == m - 1) &&
            !(row == sr && col == sc)) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                maze[nrow][ncol] == '.' &&
                !vis[nrow][ncol]) {

                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, dist + 1});
            }
        }
    }

    return -1;
}
};