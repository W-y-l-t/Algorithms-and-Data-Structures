/*
* Time Complexity: where N and M are the size of data[] and count[] respectively
 * Worst-case: O(N + M)
 * Average-case: O(N + M)
 * Best-case: O(N + M)
 *
 * Auxiliary Space: O(N + M), where N and M are the space taken by output[] and count[] respectively
 *
 * !STABLE!
 */

#include <iostream>
#include <cinttypes>

void CountingSort(int64_t data[], size_t n) {
    int64_t maximum = 0;

    for (size_t i = 0; i < n; ++i) {
        maximum = std::max(maximum, data[i]);
    }

    auto* count = static_cast<int64_t*>(calloc(maximum,
        sizeof (int64_t)));

    for (size_t i = 0; i < n; ++i) {
        count[data[i]] += 1;
    }
    for (size_t i = 1; i <= maximum; ++i) {
        count[i] += count[i - 1];
    }

    auto* output = new int64_t[n];

    auto index = static_cast<int64_t>(n);
    while (index --) {
        output[count[data[index]] - 1] = data[index];
        count[data[index]] -= 1;
    }

    for (size_t i = 0; i < n; ++i) {
        std::swap(data[i], output[i]);
    }

    delete[] count;
    delete[] output;
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

    CountingSort(data, n);
    Print(data, n);

    delete[] data;
}
