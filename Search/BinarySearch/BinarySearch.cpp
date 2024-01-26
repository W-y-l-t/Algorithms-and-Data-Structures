/*
* Time Complexity: O(log N)
 *
 * Auxiliary Space: O(1)
 *
 * !ONLY FOR SORTED DATA ARRAYS!
 */

#include <iostream>
#include <cinttypes>

int main() {
    size_t n;
    std::cin >> n;

    auto* data = new int64_t[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    int64_t find_value;
    std::cin >> find_value;

    size_t value_index = -1;
    size_t left = 0;
    size_t right = n;
    while (left + 1 < right) {
        size_t mid = (left + right) / 2;

        if (data[mid] == find_value) {
            value_index = mid;
            break;
        }

        if (data[mid] <= value_index) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << value_index << std::endl;

    delete[] data;
}
