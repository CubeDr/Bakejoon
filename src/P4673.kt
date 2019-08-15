fun d(n: Int) = n + n.toString().map(Character::getNumericValue).sum()

fun main() {
    val check = MutableList(10001) { false }
    for(i in 1..10000) {
        if(check[i]) continue
        var j = d(i)
        while(j <= 10000 && !check[j]) {
            check[j] = true
            j = d(j)
        }
    }
    for(i in 1..10000) {
        if(!check[i])
            println(i)
    }
}