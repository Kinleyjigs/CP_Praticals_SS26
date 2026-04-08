#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool seen[26] = {false};

    for (char c : s) {
        seen[c - 'a'] = true;
    }

    int distinct = 0;
    for (bool x : seen) {
        if (x) distinct++;
    }

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!" << '\n';
    else
        cout << "IGNORE HIM!" << '\n';

    return 0;
}