fun main() {
    val year = readLine()!!.toInt()
    when {
        year % 400 == 0 -> print(1)
        year % 100 == 0 -> print(0)
        year % 4 == 0 -> print(1)
        else -> print(0)
    }
}