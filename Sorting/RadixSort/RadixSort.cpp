/*
* Time Complexity: O((N + B) * D),
 * where D is the number of digits,
 * N is the number of elements,
 * and B is the base of the number system being used
 *
 * Auxiliary Space: O(N + B),
 * where n is the number of elements and b is the base of the number system
 *
 * !STABLE!
 */

#include <iostream>
#include <cinttypes>

void CountingSort(int64_t data[], size_t n, size_t digit) {
    auto* output = new int64_t[n];
    auto* count = new int64_t[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (size_t i = 0; i < n; ++i) {
        count[(data[i] / digit) % 10] += 1;
    }

    for (size_t i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int64_t i = n - 1; i >= 0; --i) {
        output[count[(data[i] / digit) % 10] - 1] = data[i];
        count[(data[i] / digit) % 10] -= 1;
    }

    for (size_t i = 0; i < n; ++i) {
        data[i] = output[i];
    }

    delete[] output;
    delete[] count;
}

void RadixSort(int64_t data[], size_t n) {
    int64_t maximum = INT64_MIN;
    for (size_t i = 0; i < n; ++i) {
        maximum = std::max(maximum, data[i]);
    }

    for (size_t digit = 1; maximum / digit > 0; digit *= 10) {
        CountingSort(data, n, digit);
    }
}

void Print(int64_t data[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    size_t n;
    std::cin >> n;

    auto* data = new int64_t[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    RadixSort(data, n);
    Print(data, n);

    delete[] data;
}
