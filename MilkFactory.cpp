#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int N;
    fin >> N;
    vector<int> in(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a >> b;
        in[b]++; 
    }
    int answer = -1;
    for (int i = 1; i <= N; i++) {
        if (in[i] == N - 1) {
            answer = i;
            break;  
        }
    }
    fout << answer << "\n";
    return 0;
}
