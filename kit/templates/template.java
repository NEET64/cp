import java.util.*;
import java.io.*;

public class Template {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve();
        }
        out.flush();
    }

    static void solve() throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] tokens = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(tokens[i]);
        }

        int answer = 0;
        out.println(answer);
    }
}
