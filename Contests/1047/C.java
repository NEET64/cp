import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            boolean aisEven = a % 2 == 0;
            boolean bisEven = b % 2 == 0;

            if (aisEven && bisEven) {
                System.out.println(a * b / 2 + 2);
            } else if (!aisEven && !bisEven) {
                System.out.println(a * b + 1);
            } else if (!aisEven && b % 4 == 0) {
                System.out.println(a * b / 2 + 2);
            } else
                System.out.println(-1);
        }
    }
}
