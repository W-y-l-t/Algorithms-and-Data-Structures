/*
 * Time Complexity: O(N)
 *
 * Auxiliary Space: O(1)
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

    for (i in data.indices) {
        if (data[i] == key) {
            position = i
            break
        }
    }

    println("Target value is $key")
    println(when(position) {
        -1 -> "There is no target value in data"
        else -> "Target value position in data is $position"
    })
}
