import java.util.Scanner;

public class algo9663 {
    static int[] col;
    static int[] diag1;
    static int[] diag2;
    static int count = 0;
    static int N;
    public static void solv(){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        col = new int[N];
        diag1 = new int[N*2];
        diag2 = new int[N*2];
        backtracking(0);
        System.out.println(count);
    }
    public static void backtracking(int y){
        if(y==N){
            count++;
            return;
        }
        else{
            for(int i=0; i<N; i++){
                if(col[i]==1 || diag1[i+y]==1 || diag2[i-y+N-1]==1) continue;
                col[i] = diag1[i+y] = diag2[i-y+N-1] = 1;
                backtracking(y+1);
                col[i] = diag1[i+y] = diag2[i-y+N-1] = 0;
            }
        }
    }
}
