import java.util.ArrayList;
import java.util.Scanner;

public class algo10974 {
    static int N;
    static int[] visit;
    static int[] arr;
    static ArrayList<Integer> A = new ArrayList<Integer>();
    public static void solv(){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        visit = new int[N+1];
        arr = new int[N+1];
        permutations();
    }
    public static void permutations(){
        if(A.size()==N){
            for(int d : A) System.out.print(d+" ");
            System.out.println();
            return;
        }else{
            for(int i=1; i<=N; i++){
                if(visit[i]==1) continue;
                visit[i] = 1;
                A.add(i);
                permutations();
                visit[i] = 0;
                A.remove(A.size()-1);
            }
        }
    }
}
