import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    static BigInteger makeOperations(int n) {
        BigInteger f = new BigInteger("1");
        for(int i = 2; i <= n; i++) {
            f = f.multiply(BigInteger.valueOf(i));
            f = f.mod(BigInteger.valueOf(1000000007));
        }

        f = f.multiply(BigInteger.valueOf(n));
        f = f.multiply(BigInteger.valueOf(n - 1));
        f = f.mod(BigInteger.valueOf(1000000007));
        return f;
    }
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = 0;
        try {
            n = Integer.parseInt(bf.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        int m = 0;

        for(int i = 0; i < n; i++) {
            try {
                m = Integer.parseInt(bf.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            System.out.println(makeOperations(m));
        }
    }
}