/*
* Time Complexity: O(2 * log_3 N)
 *
 * Auxiliary Space: O(1)
 *
 * !ONLY FOR UNIMODAL FUNCTIONS / SORTED DATA ARRAYS!
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
    while (left <= right) {
        size_t mid1 = left + (right - left) / 3;
        size_t mid2 = right - (right - left) / 3;

        if (data[mid1] == find_value) {
            value_index = mid1;
        }
        if (data[mid2] == find_value) {
            value_index = mid2;
        }

        if (data[mid1] > find_value) {
            right = mid1 - 1;
        } else if (data[mid2] < find_value) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    std::cout << value_index << std::endl;

    delete[] data;
}
