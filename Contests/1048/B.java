import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++)
                ar[i] = sc.nextInt();
            Arrays.sort(ar);
            long ans = 0;
            for (int i = n - 1; i >= 0 && k > 0; i--) {
                ans += (long) ar[i] * (k--);
            }
            System.out.println(ans);
        }
    }
}