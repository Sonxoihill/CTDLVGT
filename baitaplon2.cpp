#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct Point {
    int x, y, steps; 
};

bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int minMoves(int n, int m, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;
    q.push({x1, y1, 0}); 
    visited[x1][y1] = true;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx == x2 && ny == y2) {
                return p.steps + 1;
            }
            if (isValid(nx, ny, n, m) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, p.steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    int x1, y1, x2, y2;
    cout << "Nhập kích thước bàn cờ (n m): ";
    cin >> n >> m;
    cout << "Nhập tọa độ điểm bắt đầu (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Nhập tọa độ điểm đích (x2 y2): ";
    cin >> x2 >> y2;
    int result = minMoves(n, m, x1, y1, x2, y2);
    cout << result << endl;

    return 0;
}
