#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> line;
    string command;
    int x;

    cout << "Enter operations (type 'exit' to stop):\n";
    while (cin >> command && command != "exit") {
        if (command == "push_front") {
            cin >> x;
            line.push_front(x);
        } else if (command == "push_back") {
            cin >> x;
            line.push_back(x);
        } else if (command == "pop_front" && !line.empty()) {
            line.pop_front();
        } else if (command == "pop_back" && !line.empty()) {
            line.pop_back();
        }

        // Print contents
        for (int person : line) {
            cout << person << " ";
        }
        cout << endl;
    }
    return 0;
}