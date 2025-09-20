#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> grass(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        bool used[5] = {false}; 

        for (int neighbor : adj[i]) {
            if (grass[neighbor] != 0) {
                used[grass[neighbor]] = true;
            }
        }

        for (int g = 1; g <= 4; g++) {
            if (!used[g]) {
                grass[i] = g;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        fout << grass[i];
    }
    fout << "\n";

    return 0;
}
