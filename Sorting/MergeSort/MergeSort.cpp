/*
* Time Complexity:
 * Worst-case: O(N log N)
 * Average-case: O(N log N)
 * Best-case: O(N log N)
 *
 * Auxiliary Space: O(log N + N)
 *
 * !STABLE!
 */

#include <iostream>
#include <cinttypes>

void Merge(int64_t data[], size_t n, size_t begin, size_t middle, size_t end) {
    size_t iter1 = begin;
    size_t iter2 = middle + 1;
    size_t iter3 = begin;

    auto* result = new int64_t[n];

    while (iter1 <= middle && iter2 <= end) {
        if (data[iter1] < data[iter2]) {
            result[iter3] = data[iter1];
            iter1 += 1;
            iter3 += 1;
        } else {
            result[iter3] = data[iter2];
            iter2 += 1;
            iter3 += 1;
        }
    }

    while (iter1 <= middle) {
        result[iter3] = data[iter1];
        iter1 += 1;
        iter3 += 1;
    }

    while (iter2 <= end) {
        result[iter3] = data[iter2];
        iter2 += 1;
        iter3 += 1;
    }

    for (size_t i = begin; i <= end; ++i) {
        data[i] = result[i];
    }

    delete[] result;
}

void MergeSort(int64_t data[], size_t n, size_t begin, size_t end) {
    if (begin >= end) {
        return;
    }

    size_t middle = (begin + end) / 2;

    MergeSort(data, n, begin, middle);
    MergeSort(data, n, middle + 1, end);

    Merge(data, n, begin, middle, end);
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

    MergeSort(data, n, 0, n - 1);
    Print(data, n);

    delete[] data;
}
