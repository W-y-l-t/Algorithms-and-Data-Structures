/*
 * Time Complexity: O(2 * log_3 N)
 *
 * Auxiliary Space: O(1)
 *
 * !ONLY FOR UNI MODAL FUNCTIONS / SORTED DATA ARRAYS!
 */

import kotlin.random.Random

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun main() {
    val n : Int = Random.nextInt(1, 100000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(Int.MIN_VALUE, Int.MAX_VALUE) }

    val key : Int = data[Random.nextInt(0, n)]
    var position : Int = -1

    var left : Int = 0
    var right : Int = n
    while (left <= right) {
        val mid1 : Int = left + (right - left) / 3
        val mid2 : Int = right - (right - left) / 3

        if (data[mid1] == key) {
            position = mid1
        }
        if (data[mid2] == key) {
            position = mid2
        }

        if (data[mid1] > key) {
            right = mid1 - 1
        } else if (data[mid2] < key) {
            left = mid2 + 1
        } else {
            left = mid1 + 1
            right = mid2 - 1
        }
    }

    println("Target value is $key")
    println(when(position) {
        -1 -> "There is no target value in data"
        else -> "Target value position in data is $position"
    })
}
