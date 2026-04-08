#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool isMagic = true;

    // Rule 1: Must start with '1'
    if (s[0] != '1') {
        isMagic = false;
    }

    for (int i = 0; i < s.length(); i++) {
        // Rule 2: Only '1' and '4' allowed
        if (s[i] != '1' && s[i] != '4') {
            isMagic = false;
        }

        // Rule 3: No three '4's in a row ("444")
        if (i >= 2 && s[i] == '4' && s[i-1] == '4' && s[i-2] == '4') {
            isMagic = false;
        }
    }

    if (isMagic) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}