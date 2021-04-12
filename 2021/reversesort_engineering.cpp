// Reverse sort engineering Google Code Jam 2021 Qualification
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
   for(int i = 1; i<=T; i++){
       int x,y;
       cin>>x>>y;
       int array[109];
       for(int j = 1; j <= x; j++){
           array[j] = j;
       }
       if(y >= (x * (x + 1) / 2) || y < x - 1){
           printf("Case #%d: IMPOSSIBLE\n", i);
       } else {
           y -= (x - 1);
           int start = 1;
           for(int j = x - 1; j > 0; j--){
               if(y >= j){
                   start += 1;
                   reverse(floor(start / 2), floor(start / 2) + j, array);
                   y -= j;
                //   cout<<floor(start / 2)<<" "<<floor(start / 2) + j<<endl;
               }
           }
           printf("Case #%d: ", i);
           for(int j = 1; j < x; j++){
               printf("%d ", array[j]);
           }
           printf("%d\n", array[x]);
       }
   }
}
