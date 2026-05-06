#include <iostream>
#include <string>
#include <vector>

using namespace std;

string preProcess(const string& s) {
    if (s.empty()) return "^$";
    string ret = "^";
    for (char c : s) {
        ret += "#" + string(1, c);
    }
    ret += "#$";
    return ret;
}

string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    
    vector<int> P(n, 0); 
    int C = 0; 
    int R = 0; 
    
    for (int i = 1; i < n - 1; i++) {

        int i_mirror = 2 * C - i;
        
        if (R > i) {
            P[i] = min(R - i, P[i_mirror]);
        }
        
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
        
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string test1 = "babad";
    string test2 = "cbbd";
    string test3 = "a";
    string test4 = "racercar";
    
    cout << "=== Manacher's Algorithm ===" << endl;
    cout << "Longest palindrome in '" << test1 << "': " << longestPalindrome(test1) << endl;
    cout << "Longest palindrome in '" << test2 << "': " << longestPalindrome(test2) << endl;
    cout << "Longest palindrome in '" << test3 << "': " << longestPalindrome(test3) << endl;
    cout << "Longest palindrome in '" << test4 << "': " << longestPalindrome(test4) << endl;

    return 0;
}