fun main() {
    val lines = generateSequence(::readLine).toList()
    val maxLength = lines.maxBy { it.length }!!.length
    for(i in 0 until maxLength)
        lines.filter { it.length > i }.forEach { print(it[i]) }
}