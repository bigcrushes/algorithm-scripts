// Google Code Jam Round 1C Robot Programming Strategy answer
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int T;
   cin>>T;
   for(int i = 0; i < T; i++){
       set<int> remainding;
       string robots[260];
       string answer = "";
       int x, impossible = 0;
       cin>>x;
       for(int j = 0; j < x; j++){
           cin>>robots[j];
           remainding.insert(j);
       }
       for(int j = 0 ; j < 256; j++){
           vector<int> to_remove;
           int P_checker=0,S_checker = 0, R_checker = 0;
           for(auto k : remainding){
               int index = j % robots[k].length();
               char letter = robots[k][index];
               if(letter == 'P'){
                   P_checker = 1;
               } else {
                   if(letter =='S'){
                       S_checker = 1;
                   } else {
                       R_checker = 1;
                   }
               }
           }
           if(P_checker == 1 && S_checker == 1 && R_checker == 1){
               impossible = 1;
           } else {
               if(P_checker + S_checker + R_checker == 2){
                   if(S_checker == 0){
                       answer += 'P';
                   } else {
                       if(P_checker == 0){
                           answer += 'R';
                       } else {
                           answer += 'S';
                       }
                   }
               } else {
                   if(P_checker == 1){
                       answer += 'S';
                   } else {
                       if(S_checker == 1){
                           answer += 'R';
                       } else {
                           answer += 'P';
                       }
                   }
               }
           }
           char last_alphabet = answer[answer.length() - 1];
           for(auto k : remainding){
               int index = j % robots[k].length();
               if(last_alphabet == 'P' && robots[k][index] == 'R'){
                   to_remove.push_back(k);
               }
               if(last_alphabet == 'R' && robots[k][index] == 'S'){
                   to_remove.push_back(k);
               }
               if(last_alphabet == 'S' && robots[k][index] == 'P'){
                   to_remove.push_back(k);
               }
           }
           for(int k = 0; k < to_remove.size(); k++){
               remainding.erase(to_remove[k]);
           }
           if(remainding.size() == 0){
               break;
           }
       }
       if(impossible == 1 || remainding.size() != 0){
       printf("Case #%d: IMPOSSIBLE\n", i + 1);
       } else {
           printf("Case #%d: ", i + 1);
           cout<<answer<<endl;
       }
   }
}
