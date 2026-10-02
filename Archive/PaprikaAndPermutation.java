import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class PaprikaAndPermutation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            boolean[] track = new boolean[n + 1];
            for (int i = 0; i < n; i++) {
                int cur = sc.nextInt();
                if (cur <= n && !track[cur])
                    track[cur] = true;
                else
                    pq.add(cur);
            }
            int ans = 0;
            boolean fail = false;
            for (int i = 1; i < track.length; i++) {
                if (!track[i]) {
                    int top = pq.poll();
                    if (top <= 2 * i) {
                        fail = true;
                        break;
                    }
                    ans++;
                }
            }
            if (fail)
                System.out.println(-1);
            else
                System.out.println(ans);
        }
    }
}
