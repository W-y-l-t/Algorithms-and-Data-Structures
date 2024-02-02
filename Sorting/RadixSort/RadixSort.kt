/*
 * Time Complexity: O((N + B) * D),
 * where D is the number of digits,
 * N is the number of elements,
 * and B is the base of the number system being used
 *
 * Auxiliary Space: O(N + B),
 * where n is the number of elements and b is the base of the number system
 *
 * !STABLE!
 */


import kotlin.random.Random

fun countingSort(data : MutableList<Int>, n : Int, digit : Int) : Unit {
    val count : MutableList<Int> = MutableList(10) { 0 }

    for (i in 0 until n) {
        count[(data[i] / digit) % 10] += 1
    }
    for (i in 1..9) {
        count[i] += count[i - 1]
    }

    val output : MutableList<Int> = MutableList(n) { 0 }

    for (i in n - 1 downTo 0) {
        output[count[(data[i] / digit) % 10] - 1] = data[i]
        count[(data[i] / digit) % 10] -= 1
    }

    data.forEachIndexed { index, _ -> data[index] = output[index]}
}

fun radixSort(data : MutableList<Int>, n : Int) : Unit {
    val maximum = data.max()

    var digit : Int = 1
    while (maximum / digit > 0) {
        countingSort(data, n, digit)

        digit *= 10
    }
}

fun<T> Collection<T>.printList() {
    this.forEach {
        print("$it ")
    }
}

fun main() {
    val n : Int = Random.nextInt(1, 1000000)
    val data : MutableList<Int> = MutableList(n) { Random.nextInt(1, 10000000) }

    radixSort(data, n)

    data.printList()
}
