fun main() {
    val (a, b) = readLine()!!.split(" ").map(String::toInt)
    when {
        a > b -> print(">")
        a < b -> print("<")
        else -> print("==")
    }
}