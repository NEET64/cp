import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C {
    static class Node {
        long a;
        long b;
        String s;

        Node(long a, long b, String s) {
            this.a = a;
            this.b = b;
            this.s = s;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int k = sc.nextInt();
            long x = sc.nextLong();

            long a = x;
            long b = (1L << (k + 1)) - x;

            StringBuilder sb = new StringBuilder();

            while (a != b) {
                if (a > b) {
                    a -= b;
                    b <<= 1;
                    sb.append("2 ");
                } else {
                    b -= a;
                    a <<= 1;
                    sb.append("1 ");
                }
            }
            System.out.println(sb.length() / 2);
            if (sb.length() == 0) {
                continue;
            }
            System.out.println(sb.reverse().toString().trim());
        }
    }
}
