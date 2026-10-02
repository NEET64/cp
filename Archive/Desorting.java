import java.util.Scanner;

public class Desorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[] ar = new long[n];
            for (int i = 0; i < n; i++) {
                ar[i] = sc.nextLong();
            }
            long ans = Long.MAX_VALUE;
            long left = ar[0];
            for (int i = 1; i < n; i++) {
                ans = Math.min((ar[i] - left + 2) / 2, ans);
                left = Math.max(ar[i], left);
            }
            System.out.println(Math.max(0, ans));
        }
    }
}
