fun main() {
    val n = readLine()!!.toInt()
    val cars = readLine()!!.split(' ').map(String::toInt)
    println(cars.count { it == n })
}