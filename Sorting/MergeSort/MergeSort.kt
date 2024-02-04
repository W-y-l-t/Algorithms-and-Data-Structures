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

import kotlin.random.Random


fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun MutableList<Int>.merge(n : Int, begin : Int, middle : Int, end : Int) {
    var iter1 : Int = begin
    var iter2 : Int = middle + 1
    var iter3 : Int = begin

    val result : MutableList<Int> = MutableList<Int>(n) { 0 }

    while (iter1 <= middle && iter2 <= end) {
        if (this[iter1] < this[iter2]) {
            result[iter3] = this[iter1]
            iter1 += 1
            iter3 += 1
        } else {
            result[iter3] = this[iter2]
            iter2 += 1
            iter3 += 1
        }
    }

    while (iter1 <= middle) {
        result[iter3] = this[iter1]
        iter1 += 1
        iter3 += 1
    }

    while (iter2 <= end) {
        result[iter3] = this[iter2]
        iter2 += 1
        iter3 += 1
    }

    for (i in begin..end) {
        this[i] = result[i]
    }
}

fun MutableList<Int>.mergeSort(n : Int, range : IntRange) {
    if (range.first >= range.last) {
        return
    }

    val middle : Int = (range.first + range.last) / 2

    this.mergeSort(n, range.first..middle)
    this.mergeSort(n, middle + 1..range.last)

    this.merge(n, range.first, middle, range.last)
}

fun main() {
    val n : Int = Random.nextInt(1, 10000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(Int.MIN_VALUE, Int.MAX_VALUE) }

    data.mergeSort(n, 0..<n)

    data.printList()
}
