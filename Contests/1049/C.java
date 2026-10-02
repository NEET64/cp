import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[] ar = new long[n];
            long sumE = 0;
            long sumO = 0;
            for (int i = 0; i < n; i++) {
                ar[i] = sc.nextLong();
                if (i % 2 == 0) {
                    sumE += ar[i];
                } else {
                    sumO += ar[i];
                }
            }
            if (n == 1) {
                System.out.println(ar[0]);
                continue;
            }

            long cost = (n % 2 == 0) ? n - 2 : n - 1;
            long ans = sumE - sumO;

            long maxop = Long.MIN_VALUE;
            long maxom = Long.MIN_VALUE;
            long minep = Long.MAX_VALUE;
            long minem = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    minep = Math.min(minep, ar[i] * 2 + i);
                    minem = Math.min(minem, ar[i] * 2 - i);
                } else {
                    maxop = Math.max(maxop, ar[i] * 2 + i);
                    maxom = Math.max(maxom, ar[i] * 2 - i);
                }
            }

            // System.out.println(minep);
            System.out.println(ans + Math.max(cost, Math.max(maxop - minep, maxom - minem)));
        }
    }
}
