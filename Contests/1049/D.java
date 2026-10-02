import java.util.PriorityQueue;
import java.util.Scanner;

public class D {
    static class Node {
        int l, r;
        boolean marked;

        Node(int l, int r, boolean marked) {
            this.l = l;
            this.r = r;
            this.marked = marked;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            PriorityQueue<Node> min = new PriorityQueue<>((a, b) -> a.l - b.l);
            PriorityQueue<Node> max = new PriorityQueue<>((a, b) -> b.r - a.r);
            int n = sc.nextInt();
            while (n-- > 0) {
                int l = sc.nextInt();
                int r = sc.nextInt();
                Node node = new Node(l, r, false);
                min.add(node);
                max.add(node);
            }
            long ans = 0;

            while (min.size() > 0 && max.size() > 0) {
                Node left = null;
                Node right = null;
                while (!min.isEmpty()) {
                    Node cur = min.poll();
                    if (!cur.marked) {
                        left = cur;
                        break;
                    }
                }
                if (left == null)
                    break;
                while (!max.isEmpty()) {
                    Node cur = max.poll();
                    if (!cur.marked && cur != left) {
                        right = cur;
                        break;
                    }
                }
                if (right == null) {
                    ans += left.r - left.l;
                    break;
                }

                ans += right.r - left.l;
                left.marked = true;
                right.marked = true;
            }

            System.out.println(ans);
        }
    }
}
