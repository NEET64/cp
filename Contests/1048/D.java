import java.util.Arrays;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int q = sc.nextInt();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++) {
                ar[i] = sc.nextInt();
            }
            int[] pref = new int[n];
            int cur = 0;
            for (int i = 2; i < n; i++) {
                if (ar[i] < ar[i - 1] && ar[i - 1] < ar[i - 2])
                    cur++;
                pref[i] = cur;
            }
            if (n > 2 && pref[2] == 1)
                pref[1] = 1;

            // System.out.println(Arrays.toString(pref));

            for (int i = 0; i < q; i++) {
                int l = sc.nextInt();
                int r = sc.nextInt();

                if (pref[r - 1] - pref[l - 1] == 0)
                    System.out.println("Yes");
                else
                    System.out.println("No");
            }
        }
    }
}
