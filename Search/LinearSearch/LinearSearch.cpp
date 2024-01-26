/*
* Time Complexity: O(N)
 *
 * Auxiliary Space: O(1)
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
    for (size_t i = 0; i < n; ++i) {
        if (data[i] == find_value) {
            value_index = i;
            break;
        }
    }

    std::cout << value_index << std::endl;

    delete[] data;
}
