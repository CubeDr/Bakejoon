fun main() {
    val n = readLine()!!.toInt()
    val list = readLine()!!
        .split(" ")
        .map(String::toInt)
    val max = list.max()!!
    println(list.map { it * 100.0 / max }.sum() / n)
}