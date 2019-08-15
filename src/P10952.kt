fun main() {
    while(true) {
        val (a, b) = (readLine()?:break).split(" ").map(String::toInt)
        println(a + b)
    }
}