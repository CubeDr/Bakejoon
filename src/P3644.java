import java.math.BigInteger;
import java.util.Scanner;

public class P3644 {
    private static BigInteger[] mem = new BigInteger[10001];

    private static BigInteger solve(int n) {
        if(mem[n] != null) return mem[n];

        return BigInteger.ONE;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
            System.out.println(solve(in.nextInt()).toString());
    }
}
