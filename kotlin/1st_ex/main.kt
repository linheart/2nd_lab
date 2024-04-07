import kotlin.math.ceil

fun main() {
    val S = init()
    val N = init()
    val M = init()

    println(func(S, N, M))
}

fun err(exc: String): Nothing {
    throw Exception(exc)
}

fun init(): Int {
    val valStr = readLine() ?: err("Invalid input")
    val value = valStr.toInt()
    if (value <= 0) err("Invalid input")
    return value
}

fun func(S: Int, N: Int, M: Int): Int {
    if (S * M > (S - S / 7) * N) {
        return -1
    }
    return ceil(S * M.toDouble() / N).toInt()
}
