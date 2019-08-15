fun main() {
    val n = readLine()!!.toInt()
    val balls = mutableListOf<Pair<Int, Int>>()
    val foods = List(n+1) { mutableListOf<Int>() }
    repeat(n) {
        val (c, s) = readLine()!!.split(' ').map(String::toInt)
        balls.add(c to s)
        foods[c].add(s)
    }

    foods.forEach { it.sort() }
}