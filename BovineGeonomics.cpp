#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spotty(N), plain(N);
    for (int i = 0; i < N; i++) cin >> spotty[i];
    for (int i = 0; i < N; i++) cin >> plain[i];

    int answer = 0;

    for (int j = 0; j < M; j++) {
        set<char> s_spotty, s_plain;
        for (int i = 0; i < N; i++) {
            s_spotty.insert(spotty[i][j]);
            s_plain.insert(plain[i][j]);
        }

        bool overlap = false;
        for (char c : s_spotty) {
            if (s_plain.count(c)) {
                overlap = true;
                break;
            }
        }

        if (!overlap) answer++;
    }

    cout << answer << "\n";
    return 0;
}
