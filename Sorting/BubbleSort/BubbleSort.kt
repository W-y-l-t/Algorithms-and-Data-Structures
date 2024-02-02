/*
 * Time complexity :
 * - Worst case : O(N^2)
 * - Average Case : O(N^2)
 * - Best Case : O(N^2)
 *
 * Auxiliary Space: : O(1)
 *
 * !STABLE!
 */

import java.util.Collections
import kotlin.random.Random

fun bubbleSort(data : List<Int>, n : Int) : Unit {
    for (i in 0 until n) {
        for (j in 0 until n - i - 1) {
            if (data[j] > data[j + 1]) {
                Collections.swap(data, j, j + 1)
            }
        }
    }
}

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun main() {
    val n : Int = Random.nextInt(1, 5000)
    val data : List<Int> = List(n) { Random.nextInt(Int.MIN_VALUE, Int.MAX_VALUE) }

    bubbleSort(data, n)

    data.printList()
}
