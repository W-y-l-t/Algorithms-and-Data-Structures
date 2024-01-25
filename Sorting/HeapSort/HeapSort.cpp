/*
* Time Complexity:
 * Worst-case: O(N log N)
 * Average-case: O(N log N)
 * Best-case: O(N log N)
 *
 * Auxiliary Space: O(log N), due to the recursive call stack.
 *
 * !UNSTABLE!
 */

#include <iostream>
#include <cinttypes>

void SiftDown(int64_t data[], size_t n, int64_t root) {
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    if (left_child < n && data[left_child] > data[largest]) {
        largest = left_child;
    }
    if (right_child < n && data[right_child] > data[largest]) {
        largest = right_child;
    }

    if (largest != root) {
        std::swap(data[root], data[largest]);

        SiftDown(data, n, largest);
    }
}

void HeapSort(int64_t data[], size_t n) {
    // Build Heap
    for (int64_t i = n / 2 - 1; i >= 0; --i) {
        SiftDown(data, n, i);
    }

    for (int64_t i = n - 1; i > 0; --i) {
        std::swap(data[0], data[i]);

        SiftDown(data, i, 0);
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

    HeapSort(data, n);
    Print(data, n);

    delete[] data;
}
