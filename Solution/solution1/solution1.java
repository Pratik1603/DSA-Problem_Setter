import java.util.*;

public class solution1 {
    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        long ans = 0;
        Map<Integer, Long> mp = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            ans += mp.getOrDefault(a[i], 0L) * (n - i + 1);
            mp.put(a[i], mp.getOrDefault(a[i], 0L) + i);
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            solve(sc);
        }
        sc.close();
    }
}
