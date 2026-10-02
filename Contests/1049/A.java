import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            char[] ar = sc.next().toCharArray();
            int ans = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ar[i] - '0';
            }
            for (int i = n - 1; sum > 0; sum--, i--) {
                if (ar[i] == '0') {
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}
