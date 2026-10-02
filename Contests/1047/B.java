import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            boolean two = n == 2;
            if (two) {
                if (sc.nextInt() == 1)
                    System.out.print(2 + " ");
                else
                    System.out.print(1 + " ");
                if (sc.nextInt() == 2)
                    System.out.print(1 + " ");
                else
                    System.out.print(2 + " ");
                System.out.println();
                continue;
            }

            for (int i = 0; i < n; i++) {
                int cur = sc.nextInt();
                int num = (n - cur);
                if (num == 0)
                    num = n;
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
