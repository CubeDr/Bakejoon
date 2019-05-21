val array = List(6561) { CharArray(6561) { ' ' } }

fun rec(n: Int, x: Int, y: Int) {
    if(n == 1) array[y][x] = '*'
    else {
        val next = n/3
        // top
        rec(next, x, y)
        rec(next, x+next, y)
        rec(next, x+next*2, y)
        // left
        rec(next, x, y+next)
        // right
        rec(next, x + next*2, y + next)
        // bottom
        rec(next, x, y + next*2)
        rec(next, x+next, y + next*2)
        rec(next, x+next*2, y + next*2)
    }
}

fun main() {
    val n = readLine()!!.toInt()
    rec(n, 0, 0)
    array.subList(0, n).forEach { row ->
        println(row.joinToString(limit = n, separator = "").substring(0 until n))
    }
}