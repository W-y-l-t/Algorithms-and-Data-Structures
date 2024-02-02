/*
 * Time Complexity: where N and M are the size of data[] and count[] respectively
 * Worst-case: O(N + M)
 * Average-case: O(N + M)
 * Best-case: O(N + M)
 *
 * Auxiliary Space: O(N + M), where N and M are the space taken by output[] and count[] respectively
 *
 * !STABLE!
 */


import kotlin.random.Random

fun countingSort(data : MutableList<Int>, n : Int) : Unit {
    val maximum = data.max()

    val count : MutableList<Int> = MutableList(maximum + 1) { 0 }

    for (i in 0 until n) {
        count[data[i]] += 1
    }
    for (i in 1..maximum) {
        count[i] += count[i - 1]
    }

    val output : MutableList<Int> = MutableList(n) { 0 }

    for (i in n - 1 downTo 0) {
        output[count[data[i]] - 1] = data[i]
        count[data[i]] -= 1
    }

    data.forEachIndexed { index, _ -> data[index] = output[index]}
}

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun main() {
    val n : Int = Random.nextInt(1, 1000000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(1, 10000000) }

    countingSort(data, n)

    data.printList()
}
