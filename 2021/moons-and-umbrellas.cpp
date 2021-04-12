// Moons and Umbrellas Google Code jam 2021 Qualification (with extra credit)
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int T;
   cin>>T;
   for(int i = 1; i <= T; i++){
       int x,y;
       int cost[2][1009]; //0 is C, 1 is J
       string art;
       cin>>x>>y>>art;
       for(int j = 0; j < 2; j++){
           for(int k = 0; k < art.length(); k++){
               cost[j][k] = 100009;
           }
       }
       if(art[0] == 'J'){
           cost[1][0] = 0;
       } else {
           if(art[0] == 'C'){
               cost[0][0] = 0;
           } else {
               cost[0][0] = 0;
               cost[1][0] = 0;
           }

       }
       for(int j = 1; j < art.length(); j++){
           if(art[j] == 'J'){
               cost[1][j] = min(cost[0][j-1] + x, cost[1][j-1]);
           }
           if(art[j] == 'C'){
               cost[0][j] = min(cost[0][j-1], cost[1][j-1] + y);
           }
           if(art[j] == '?'){
               cost[1][j] = min(cost[0][j-1] + x, cost[1][j-1]);
               cost[0][j] = min(cost[0][j-1], cost[1][j-1] + y);
           }
       }
       printf("Case #%d: %d\n", i, min(cost[0][art.length() - 1], cost[1][art.length() - 1]));
   }
}
