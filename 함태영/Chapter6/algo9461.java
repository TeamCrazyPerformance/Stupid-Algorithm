package com.company;

import java.util.Scanner;

public class algo9461 {
    public static void solv(){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        long[] P = new long[101];
        P[1] = P[2] = P[3] = 1;
        P[4] = P[5] = 2;
        P[6] = 3;
        for(int i=6; i<=100; i++) P[i] = P[i-1]+P[i-5];
        for(int i=0; i<T; i++){
            System.out.println(P[sc.nextInt()]);
        }
    }
}
