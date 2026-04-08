// Beautiful Year: find the next year after input that has 4 distinct digits
#include <iostream> 
#include <set>      

using namespace std; 

// return true if year has 4 distinct digits 
bool hasDistinctDigits(int year) {
    set<int> digits; 
    while (year > 0) { 
        digits.insert(year % 10); 
        year /= 10;
    }
    return digits.size() == 4; 
}

int main() {
    int y;
    cin >> y;

    for (int nextYear = y + 1; nextYear < 10000; ++nextYear) {
        if (hasDistinctDigits(nextYear)) {
            cout << "The next beautiful year is: " << nextYear << endl;
            break;
        }
    }

    return 0;
}