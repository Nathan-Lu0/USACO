#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> zodiac = {
        "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse",
        "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
    };

    map<string, int> birthYear;
    birthYear["Bessie"] = 0;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string cow1, born, in, direction, zodiacSign, year, from, cow2;
        ss >> cow1 >> born >> in >> direction >> zodiacSign >> year >> from >> cow2;

        int baseYear = birthYear[cow2];
        int baseZodiacIndex = (baseYear % 12 + 12) % 12;
        int targetZodiacIndex = find(zodiac.begin(), zodiac.end(), zodiacSign) - zodiac.begin();

        int offset;
        if (direction == "next") {
            offset = (targetZodiacIndex - baseZodiacIndex + 12) % 12;
            if (offset == 0) offset = 12;
            birthYear[cow1] = baseYear + offset;
        } else { // previous
            offset = (baseZodiacIndex - targetZodiacIndex + 12) % 12;
            if (offset == 0) offset = 12;
            birthYear[cow1] = baseYear - offset;
        }
    }

    cout << abs(birthYear["Elsie"]) << endl;
    return 0;
}
