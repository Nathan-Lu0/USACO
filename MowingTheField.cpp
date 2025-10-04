#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N;
    cin >> N;

    map<pair<int,int>, int> lastVisit;

    int x = 0, y = 0, t = 0;
    lastVisit[{x, y}] = 0;

    int answer = INT_MAX;

    // Direction arrays: N, E, S, W
    char dirs[] = {'N','E','S','W'};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < N; i++) {
        char D;
        int S;
        cin >> D >> S;

        int dir = 0;
        for (int j = 0; j < 4; j++) if (dirs[j] == D) dir = j;

        for (int step = 0; step < S; step++) {
            t++;
            x += dx[dir];
            y += dy[dir];

            pair<int,int> pos = {x, y};

            if (lastVisit.count(pos)) {
                answer = min(answer, t - lastVisit[pos]);
            }
            lastVisit[pos] = t;
        }
    }

    if (answer == INT_MAX) cout << -1 << "\n";
    else cout << answer << "\n";

    return 0;
}
