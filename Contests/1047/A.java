import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int k = sc.nextInt();
            int n = sc.nextInt();

            while (k-- > 0) {
                n *= 2;
            }

            System.out.println(n);
        }
    }

}