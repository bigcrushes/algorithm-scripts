// Google Code Jam 2021 Qualification
#include <bits/stdc++.h>

using namespace std;

void reverse(int start, int end, int A[]){
    int temp[109];
    for(int i = start; i <= end; i++){
        temp[i] = A[i];
    }
    for(int i = 0; i < end - start + 1; i++){
        A[start + i] = temp[end - i];
    }
}

int main()
{
   int T;
   cin>>T;
   for(int i = 1; i <= T; i++){
       int iterations = 0, N, seq[109], sorted_seq[109];
       cin>>N;
       for(int j = 1; j <= N; j++){
           cin>>seq[j];
           sorted_seq[j] = seq[j];
       }
       sort(sorted_seq + 1, sorted_seq + N + 1);
       for(int j = 1; j < N; j++){
           for(int k = j; k <= N; k++){
               if(seq[k] == sorted_seq[j]){
                   iterations += (k - j + 1);
                 //  printf("%d and %d reversing\n", k, j);
                   reverse(j, k, seq);
               }
           }
       }
       printf("Case #%d: %d\n", i, iterations);
   }
}
