/*
* Time Complexity: O(log N)
 *
 * Auxiliary Space: O(1)
 *
 * !ONLY FOR SORTED DATA ARRAYS!
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

    data.sort()

    val key : Int = data[Random.nextInt(0, n)]
    var position : Int = -1

    var left : Int = 0
    var right : Int = n

    while (left + 1 < right) {
        val mid : Int = (left + right) / 2

        if (data[mid] == key) {
            position = mid
            break
        }

        if (data[mid] <= key) {
            left = mid
        } else {
            right = mid
        }
    }

    position = when (position) {
        -1 -> when (data[left]) {
            key -> left
            else -> -1
        }
        else -> position
    }

    println("Target value is $key")
    println("Target value position in data is $position")
}
