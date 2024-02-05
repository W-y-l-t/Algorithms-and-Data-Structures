/*
 * Time Complexity: O(N * M),
 * where N - size of the first string,
 * M - size of the second string
 *
 * Auxiliary Space: O(N * M)
 * where N - size of the first string,
 * M - size of the second string
 */

import kotlin.random.Random

var lcs : String = ""

fun buildLCS(i : Int,
             j : Int,
             firstString : String,
             path : MutableList<MutableList<Pair<Int, Int>>>) {

    if (i <= 0 || j <= 0) {
        return
    }

    val (x, y) = path[i][j]
    buildLCS(x, y, firstString, path)

    if (x == i - 1 && y == j - 1) {
        lcs += firstString[x]
    }
}

fun getLCS(n : Int, m : Int, firstString : String, secondString : String) {
    val dp : MutableList<MutableList<Int>> =
        MutableList<MutableList<Int>>(n + 1) {
            MutableList<Int>(m + 1) { 0 }
        }
    val path : MutableList<MutableList<Pair<Int, Int>>> =
        MutableList<MutableList<Pair<Int, Int>>>(n + 1) {
            MutableList<Pair<Int, Int>>(m + 1) { Pair(-1, -1) }
        }

    for (i in 1..n) {
        for (j in 1..m) {
            if (firstString[i - 1] == secondString[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1
                path[i][j] = Pair(i - 1, j - 1)
            } else if (dp[i - 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j]
                path[i][j] = Pair(i - 1, j)
            } else {
                dp[i][j] = dp[i][j - 1]
                path[i][j] = Pair(i, j - 1)
            }
        }
    }

    buildLCS(n, m, firstString, path)
}

fun main() {
    val n : Int = Random.nextInt(1, 1000)
    val m : Int = Random.nextInt(1, 1000)
    val firstString : String =
        (List<Char>(n) { Random.nextInt(32, 128).toChar() }).joinToString("")
    val secondString : String =
        (List<Char>(m) { Random.nextInt(32, 128).toChar() }).joinToString("")

    getLCS(n, m, firstString, secondString)

    println("First string is : $firstString")
    println("Second string is : $secondString")
    println("Longest common subsequence is : $lcs")
}
