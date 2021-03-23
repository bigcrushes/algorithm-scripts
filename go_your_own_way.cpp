// Google Code Jam 2019 Qualification Round You Can Go Your Own Way solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int x;
        cin>>x;
        string s;
        cin>>s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'E'){
                s[j] = 'S';
            } else {
                s[j] = 'E';
            }
        }
        printf("Case #%d: ", i+1);
        cout<<s<<endl;
    }
}
