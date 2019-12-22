import java.util.ArrayList;
import java.util.Scanner;

public class algo1182 {
    static int cnt = 0;
    static  int S = 0;
    static int[] List;
    static ArrayList<Integer> A = new ArrayList<Integer>();
    public static void solv(){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        S = sc.nextInt();
        List = new int[N];
        for(int i=0 ;i<N; i++){
            List[i] = sc.nextInt();
        }
        seq(0, false);
        System.out.println(cnt);
    }
    public static void seq(int n, boolean isAdd){
        int sum = 0;
        for(int d : A){
            sum += d;
        }
        if(sum == S && A.size() > 0 && isAdd){
            cnt++;
        }
        if(n >= List.length) return;
        else {
            A.add(List[n]);
            seq(n + 1, true);
            A.remove(A.size() - 1);
            seq(n + 1, false);
        }
    }
}
