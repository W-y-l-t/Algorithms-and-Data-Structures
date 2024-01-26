/*
* Time Complexity:
 * Worst-case: O(N^2)
 * Average-case: O(N log N)
 * Best-case: O(N log N)
 *
 * Auxiliary Space:
 * Worst-case: O(N)
 * Average-case: O(log N)
 * Best-case: O(log N)
 *
 * !UNSTABLE!
 */

#include <iostream>
#include <cinttypes>

size_t HoarePartition(int64_t data[], size_t left, size_t right) {
    auto pivot = data[left];
    size_t i = left - 1, j = right + 1;

    while (true) {
        do {
            i += 1;
        } while (data[i] < pivot);

        do {
            j -= 1;
        } while (data[j] > pivot);

        if (i >= j) {
            return j;
        }

        std::swap(data[i], data[j]);
    }
}

size_t LomutoPartition(int64_t data[], size_t left, size_t right) {
    auto pivot = data[right];
    size_t i = left - 1;

    for (size_t j = left; j <= right - 1; ++j) {
        if (data[j] <= pivot) {
            i += 1;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);

    return i + 1;
}

void QuickSort(int64_t data[], size_t n, size_t begin, size_t end) {
    if (begin >= end) {
        return;
    }

    size_t partial = HoarePartition(data, begin, end);

    QuickSort(data, n, begin, partial);
    QuickSort(data, n, partial + 1, end);

    /*
     * size_t partial = LomutoPartition();
     * QuickSort(data, n, begin, partial - 1);
     * QuickSort(data, n, partial + 1, end);
     */
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

    QuickSort(data, n, 0, n - 1);
    Print(data, n);

    delete[] data;
}
