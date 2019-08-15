fun main() {
    var (h, m) = readLine()!!.split(" ").map(String::toInt)
    m -= 45
    if(m < 0) {
        h--
        m += 60
    }
    if(h < 0) {
        h += 24
    }
    println("$h $m")
}