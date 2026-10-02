import java.util.*;

public class E {
    static int findMex(int[] freq) {
        int mex = 0;
        while (freq[mex] > 0)
            mex++;
        return mex;
    }

    static int[] mexify(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];
        int[] freq = new int[n + 2];
        for (int x : arr)
            freq[x]++;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]--;
            result[i] = findMex(freq);
            freq[arr[i]]++;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            int[] ar = new int[n];
            for (int i = 0; i < n; i++)
                ar[i] = sc.nextInt();

            Map<String, Integer> seen = new HashMap<>();
            List<int[]> states = new ArrayList<>();
            seen.put(Arrays.toString(ar), 0);
            states.add(ar);

            int cycleStart = -1, cycleLen = -1;
            for (int step = 1; step <= k; step++) {
                ar = mexify(ar);
                String key = Arrays.toString(ar);
                if (seen.containsKey(key)) {
                    cycleStart = seen.get(key);
                    cycleLen = step - cycleStart;
                    break;
                }
                seen.put(key, step);
                states.add(ar);
            }

            if (cycleLen != -1) {
                long remaining = (k - cycleStart) % cycleLen;
                ar = states.get((int) (cycleStart + remaining));
            }

            long sum = 0;
            for (int x : ar)
                sum += x;
            System.out.println(sum);
        }
    }
}
