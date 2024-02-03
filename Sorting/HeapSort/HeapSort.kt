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


import java.util.*
import kotlin.random.Random

fun siftDown(data : MutableList<Int>, n : Int, root : Int) {
    var largest : Int = root;
    val left_child : Int = 2 * root + 1;
    val right_child : Int = 2 * root + 2;

    if (left_child < n && data[left_child] > data[largest]) {
        largest = left_child;
    }
    if (right_child < n && data[right_child] > data[largest]) {
        largest = right_child;
    }

    if (largest != root) {
        Collections.swap(data, root, largest);

        siftDown(data, n, largest);
    }
}

fun heapSort(data : MutableList<Int>, n : Int) : Unit {
    // Build Heap
    for (i in n / 2 - 1 downTo 0) {
        siftDown(data, n, i)
    }

    for (i in n - 1 downTo 1) {
        Collections.swap(data, 0, i)

        siftDown(data, i, 0)
    }
}

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun main() {
    val n : Int = Random.nextInt(1, 5000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(Int.MIN_VALUE, Int.MAX_VALUE) }

    heapSort(data, n)

    data.printList()
}
