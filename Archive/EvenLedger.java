import java.util.Scanner;

public class EvenLedger {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++) {
                ar[i] = sc.nextInt();
            }
            long sum = 0;
            for (int i = 2; i < n - 1; i += 2) {
                sum += Math.max(0, ar[i] - Math.min(ar[i - 1], ar[i + 1]));

            }
            sum += Math.max(0, ar[0] - ar[1]);
            if (n % 2 == 1) {
                sum += Math.max(0, ar[n - 1] - ar[n - 2]);
            }
            System.out.println(sum);
        }
    }
}
