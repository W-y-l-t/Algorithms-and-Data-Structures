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

import java.util.*
import kotlin.random.Random

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun hoarePartition(data : MutableList<Int>, left : Int, right : Int) : Int {
    val pivot : Int = data[left]
    var i : Int = left - 1
    var j : Int = right + 1

    while (true) {
        do {
            i += 1;
        } while (data[i] < pivot)

        do {
            j -= 1;
        } while (data[j] > pivot)

        if (i >= j) {
            return j
        }

        Collections.swap(data, i, j)
    }
}

fun lomutoPartition(data : MutableList<Int>, left : Int, right : Int) : Int {
    val pivot : Int = data[right];
    var i : Int = left - 1;

    for (j in left..<right) {
        if (data[j] <= pivot) {
            i += 1;
            Collections.swap(data, i, j);
        }
    }
    Collections.swap(data, i + 1, right);

    return i + 1;
}

fun MutableList<Int>.quickSort(n : Int, range : IntRange) {
    if (range.first >= range.last) {
        return
    }

    val pivot : Int = lomutoPartition(this, range.first, range.last)

    this.quickSort(n, range.first..<pivot)
    this.quickSort(n, pivot + 1..range.last)
}

fun main() {
    val n : Int = Random.nextInt(1, 100000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(Int.MIN_VALUE, Int.MAX_VALUE) }

    data.quickSort(n, 0..<n)

    data.printList()
}
