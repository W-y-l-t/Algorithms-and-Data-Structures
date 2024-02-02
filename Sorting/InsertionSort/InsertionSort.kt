/*
 * Time Complexity:
 * Worst-case: O(N^2)
 * Average-case: O(N^2)
 * Best-case: O(N)
 *
 * Auxiliary Space: O(1)
 *
 * !STABLE!
 */


import java.util.*
import kotlin.random.Random

fun insertionSort(data : MutableList<Int>, n : Int) : Unit {
    for (i in 1 until n) {
        val key : Int = data[i]
        var j : Int = i - 1

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j]

            j -= 1
        }

        data[j + 1] = key
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

    insertionSort(data, n)

    data.printList()
}
