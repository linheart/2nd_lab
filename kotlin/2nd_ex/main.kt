fun main() {
    val n = init()
    val arr = mutableListOf<Int>()
    repeat(n) {
        arr.add(init())
    }
    val v = init()

    cmp(arr, v)
    println(countingSteps(arr, v))
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

fun cmp(arr: List<Int>, v: Int) {
  val max = arr.max() ?: err("Invalid input")
  if (v < max) {
    err("The volume of the watering can is not enough to water the flower")
  }
}

fun countingSteps(arr: List<Int>, v: Int): Int {
    var count = 0
    var tmp = v

    arr.forEachIndexed { i, value ->
        if (tmp < value) {
            tmp = v
            count += i * 2
        }
        count++
        tmp -= value
    }
    return count
}
