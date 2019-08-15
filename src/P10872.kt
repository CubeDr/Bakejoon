fun main() {
    (1..readLine()!!.toInt()).fold(1) { acc, v -> acc * v }.let(::print)
}