fun err(exc: String): Nothing {
    throw Exception(exc)
}

fun init(): Int = readLine()?.toIntOrNull() ?: err("Invalid input")

fun countingDup(n: Int): Int {
    var count = 0
    var a = init()
		var b = a
    for (i in 1 until n) {
        a = init()
        if (a == b) {
            count++
        }
        b = a
    }
    return count
}

fun main() {
    val n = init()
    if (n <= 0) {
        err("Invalid input")
    }

    println(countingDup(n))
}
