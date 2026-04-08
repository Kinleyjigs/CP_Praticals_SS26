// lucky digits are 4 and 7 
// A nearly lucky number is a number that contains 4 or 7 digits and 
// the count of these digits is either 4 or 7.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string n;
    cout << "enter a number: ";
    cin >> n;
    
    // this is to validate that input contains only digits
    for (char c : n) {
        if (!isdigit(c)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    // check if length is 4 or 7
    if (n.length() != 4 && n.length() != 7) {
        cout << "NO" << endl;
        return 0;
    }
    
    int count = 0;
    for (size_t i = 0; i < n.length(); i++) { 
        if (n[i] == '4' || n[i] == '7') {
            count++;
        }
    }
    if (count == 4 || count == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}