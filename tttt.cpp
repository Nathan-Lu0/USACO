#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<char>> getLines(const vector<vector<char>>& board) {
    vector<vector<char>> lines;
    for (int i = 0; i < 3; ++i)
        lines.push_back(board[i]);
    for (int j = 0; j < 3; ++j) {
        vector<char> col;
        for (int i = 0; i < 3; ++i)
            col.push_back(board[i][j]);
        lines.push_back(col);
    }
    lines.push_back({board[0][0], board[1][1], board[2][2]});
    lines.push_back({board[0][2], board[1][1], board[2][0]});
    return lines;
}
int main() {
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    vector<vector<char>> board(3, vector<char>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            fin >> board[i][j];

    set<char> individualWinners;
    set<pair<char, char>> teamWinners;

    vector<vector<char>> lines = getLines(board);

    for (const auto& line : lines) {
        set<char> unique(line.begin(), line.end());

        if (unique.size() == 1) {
            individualWinners.insert(*unique.begin());
        } else if (unique.size() == 2) {
            auto it = unique.begin();
            char a = *it++;
            char b = *it;
            map<char, int> count;
            for (char c : line)
                count[c]++;

            if (count[a] > 0 && count[b] > 0) {
                if (a > b) swap(a, b); 
                teamWinners.insert({a, b});
            }
        }
    }

    cout << individualWinners.size() << "\n";
    cout << teamWinners.size() << "\n";

    return 0;
}
