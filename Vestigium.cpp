// Google Code Jam 2020 Qualification Round Vestigium 
#include<bits/stdc++.h>
using namespace std;
int T;

int main(){
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
    	int N;
    	scanf("%d", &N);
        int row = 0;
        int column = 0;
        int grid[109][109];
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N;k++){
                scanf("%d", &grid[j][k]);  
            }
        }
        for(int j = 0; j < N; j++){
        	int num_in_row[200];
        	for(int temp = 1; temp < N+1; temp++){
        		num_in_row[temp] = 0;
        	}
            for(int k = 0; k < N; k++){
                int number = grid[j][k];
                if(num_in_row[number] != 0){
                    row+=1;
                    break;
                } else {
                    num_in_row[number] += 1;
                }
            }
        }
        for(int j = 0; j < N; j++){
        	int num_in_column[200];
        	for(int temp = 1; temp < N+1; temp++){
        		num_in_column[temp] = 0;
        	}
            for(int k = 0; k < N; k++){
                int number = grid[k][j];
                if(num_in_column[number] != 0){
                    column+=1;
                    break;
                } else {
                    num_in_column[number] += 1;
                }
            }
        }
        int trace = 0;
        for(int j = 0; j < N; j++){
        	trace+=grid[j][j];
        }
        printf("Case #%d: %d %d %d\n", i+1, trace, row, column);
    }
}
