#include <iostream>
#include <string>
using namespace std;

int main() {
    string input_1, input_2;
    cin >> input_1 >> input_2;

    if (input_1.length() != input_2.length()) {
        cout << "Error: Strings must have the same number of digits." << endl;
        return 1;
    }

    string result = "";

    for (int i = 0; i < input_1.length(); i++) {
        if (input_1[i] != input_2[i]) {
            result += '1';
        } else {
            result += '0';
        }
    }
    cout << result << endl;
}