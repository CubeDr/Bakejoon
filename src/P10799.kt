fun main() {
    var last = ' '
    var dup = 0
    var count = 0

    readLine()!!.forEach {
        if(it == '(') {
            dup++
        } else {
            dup--
            if(last == '(')
                count += dup
            else count++
        }
        last = it
    }

    println(count)
}