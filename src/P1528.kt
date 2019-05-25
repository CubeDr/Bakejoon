val n = readLine()!!.toInt()
val gmns = mutableListOf<Int>()
val mem = Array(n+1) { 0 to 0 }

fun buildGmns(prev: Int = 0) {
    if(prev * 10 + 4 > n) return
    gmns.add(prev * 10 + 4)
    buildGmns(prev * 10 + 4)

    if(prev * 10 + 7 > n) return
    gmns.add(prev * 10 + 7)
    buildGmns(prev * 10 + 7)
}

fun sort() {
    gmns.sortWith(Comparator(fun(o1, o2): Int {
        val s1 = o1.first7()
        val s2 = o2.first7()
        if(s1 != s2) return s1 - s2
        return o1 - o2
    }))

    mutableListOf<String>().toTypedArray()
}

fun buildMem() {
    gmns.forEach { gmn ->
        mem[gmn] = 0 to 1
        for(i in 0..n-gmn) {
            if(mem[i].second != 0) {
                val n = i + gmn
                val c = mem[i].second + 1
                if(mem[n].second == 0 || mem[n].second >= c)
                    mem[n] = i to c
            }
        }
    }
}

fun track(): IntArray {
    val result = mutableListOf<Int>()

    var cur = n
    while(cur > 0) {
        result.add(cur - mem[cur].first)
        cur = mem[cur].first
    }

    return result.toIntArray()
}

fun main() {
    buildGmns()
    sort()
    gmns.reverse()
    buildMem()

    if(mem[n].second == 0) print(-1)
    else track().forEach { print("$it ") }
}

private fun Int.first7(): Int = this.toString().indexOf('7')