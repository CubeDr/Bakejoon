import kotlin.math.pow

fun hanoi(n: Int, from: Int, to: Int, extra: Int, result: StringBuilder) {
    if(n == 1) {
        result.append(from).append(" ").append(to).append("\n")
    } else {
        hanoi(n-1, from, extra, to, result)
        result.append(from).append(" ").append(to).append("\n")
        hanoi(n-1, extra, to, from, result)
    }
}

fun main() {
    val N = readLine()!!.toInt()
    println(2f.pow(N).toInt() - 1)
    val builder = StringBuilder()
    hanoi(N, 1, 3, 2, builder)
    println(builder.toString())
}