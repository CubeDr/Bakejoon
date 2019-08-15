fun main() {
    val number = readLine()!!.toInt()
    val mulStr = readLine()!!
    mulStr.reversed()
        .map(Character::getNumericValue)
        .map{ number * it }
        .forEach(::println)
    println(number * mulStr.toInt())
}