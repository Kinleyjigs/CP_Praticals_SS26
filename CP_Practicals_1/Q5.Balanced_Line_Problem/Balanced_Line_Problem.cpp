#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int operationsCount;
    deque<int> line;

    // 1. Ask how many actions we are going to perform
    cout << "Enter the number of operations: ";
    cin >> operationsCount;

    cout << "Enter the operations (e.g., 'push_front', 'pop_back', 'pop_front', 'push_back'):" << endl;

    // 2. Loop through each operation
    for (int i = 0; i < operationsCount; i++) {
        string action;
        cin >> action;

        // 3. Figure out what the user wants to do and do it
        if (action == "push_front") {
            int person;
            cin >> person;
            line.push_front(person);
        } 
        else if (action == "push_back") {
            int person;
            cin >> person;
            line.push_back(person);
        } 
        else if (action == "pop_front") {
            if (!line.empty()) {
                line.pop_front();
            }
        } 
        else if (action == "pop_back") {
            if (!line.empty()) {
                line.pop_back();
            }
        }

        // 4. Print the line after the action is done
        cout << "Current line: ";
        if (line.empty()) {
            cout << "Empty";
        } else {
            // This is a quick way to look at every person currently in the line
            for (int person : line) {
                cout << person << " ";
            }
        }
        cout << endl;
    }

    return 0;
}