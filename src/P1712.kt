fun main() {
    val (A, B, C) = readLine()!!.split(" ").map(String::toLong)
    if(C <= B) {
        print(-1)
        return
    }
    print(A / (C - B) + 1)
}