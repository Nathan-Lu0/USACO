#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N;
    cin >> N;
    vector<pair<int,int>> pts(N);
    for (int i = 0; i < N; i++) cin >> pts[i].first >> pts[i].second;

    int best = 0;

    for (int i = 0; i < N; i++) {
        int x = pts[i].first;
        int y = pts[i].second;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (pts[j].second != y) continue; 
            int base = abs(pts[j].first - x);

            for (int k = 0; k < N; k++) {
                if (i == k) continue;
                if (pts[k].first != x) continue; 
                int height = abs(pts[k].second - y);

                best = max(best, base * height);
            }
        }
    }

    cout << best << "\n";
    return 0;
}
