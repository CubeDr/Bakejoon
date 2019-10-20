
fun nextCharacter(str: String, index: Int) = str.withIndex().indexOfFirst { (i, c) ->
    i > index && c != str[index]
}

tailrec fun countSegments(str: String, index: Int = 0, segments: Int = 0): Int =
    if(index == -1) segments
    else countSegments(str,
        nextCharacter(str, index),
        segments + 1)

fun main() {
    val str = readLine()!!
    val segments = countSegments(str)
    val answer = segments / 2
    println(answer)
}