#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    for (int K = 1; K <= N; K++) {
        set<string> seen;
        bool unique = true;

        for (int i = 0; i + K <= N; i++) {
            string sub = s.substr(i, K);
            if (seen.count(sub)) { 
                unique = false;
                break;
            }
            seen.insert(sub);
        }

        if (unique) {
            cout << K << "\n";
            return 0;
        }
    }
}
