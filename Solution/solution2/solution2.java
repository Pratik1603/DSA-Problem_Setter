import java.util.Scanner;

public class solution2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String S = scanner.next();
        String T = scanner.next();
        
        int[] cnt = new int[2];
        int[] A = new int[514514];
        char[] buf = new char[514514];
        
        for (char c : S.toCharArray()) {
            cnt[c - '0']++;
        }
        
        A[0] = -1;
        int j = -1;
        for (int i = 0; i < T.length(); i++) {
            while (j >= 0 && T.charAt(i) != T.charAt(j)) {
                j = A[j];
            }
            j++;
            A[i + 1] = j;
        }
        
        int M = T.length();
        int k = M - A[M];
        StringBuilder ans = new StringBuilder();
        
        while (true) {
            boolean fail = false;
            for (int i = 0; i < k; i++) {
                char c = T.charAt(i);
                if (cnt[c - '0'] == 0) {
                    fail = true;
                    break;
                }
                cnt[c - '0']--;
                ans.append(c);
            }
            
            if (fail) {
                for (int i = 0; i < 2; i++) {
                    for (int l = 0; l < cnt[i]; l++) {
                        ans.append((char) ('0' + i));
                    }
                }
                break;
            }
        }
        
        System.out.println(ans.toString());
    }
}
