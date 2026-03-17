#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    // Step 1: Sort the vector
    std::sort(nums.begin(), nums.end());

    // Step 2: Print only unique elements
    for (int i = 0; i < N; ++i) {
        // Only print if it's the first element OR different from the previous one
        if (i == 0 || nums[i] != nums[i - 1]) {
            std::cout << nums[i] << " ";
        }
    }

    return 0;
}