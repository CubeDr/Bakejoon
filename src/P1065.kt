fun isHan(n: Int): Boolean {
    val digitList = n.toString().map(Character::getNumericValue)
    val diff = List(digitList.size-1) { digitList[it+1] - digitList[it] }
    diff.find { it != diff[0] }?: return true
    return false
}

fun main() {
    val max = readLine()!!.toInt()
    var c = 0
    for(n in 1..max)
        if(isHan(n))
            c++
    print(c)
}