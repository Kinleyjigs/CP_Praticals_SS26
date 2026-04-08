// Beautiful Matrix: find minimum moves to bring the cell with 1 to center

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
    vector<vector<int>> matrix(5, vector<int>(5)); 
    int oneRow, oneCol;

    // read the matrix and find the position of the value 1
    for (int i = 0; i < 5; ++i) { 
        for (int j = 0; j < 5; ++j) { 
            cin >> matrix[i][j]; 
            if (matrix[i][j] == 1) { 
                oneRow = i; 
                oneCol = j; 
            }
        }
    }

    int moves = abs(oneRow - 2) + abs(oneCol - 2); 
    cout << "It required " << moves << " moves" << endl; 

    return 0;
}