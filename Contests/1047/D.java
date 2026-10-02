import java.util.HashMap;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = 1;
            HashMap<Integer, int[]> map = new HashMap<>();
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                if (!map.containsKey(a)) {
                    map.put(a, new int[] { a, k++ });
                }

                int[] cur = map.get(a);
                cur[0]--;
                ans[i] = cur[1];

                if (cur[0] == 0) {
                    cur[0] = a;
                    cur[1] = k++;
                }
            }

            boolean fail = false;
            for (int i : map.keySet()) {
                int[] cur = map.get(i);
                if (cur[0] != i) {
                    fail = true;
                    break;
                }
            }

            if (fail) {
                System.out.println(-1);
                continue;
            }

            for (int i = 0; i < ans.length; i++) {
                System.out.print(ans[i] + " ");
            }

            System.out.println();
        }
    }
}
