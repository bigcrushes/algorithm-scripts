// Google Code Jam 2019 Qualifcation Round Foregone Solution answer
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        string s;
        cin>>s;
        string second_num = "";
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '4'){
                s[j] = s[j] -= 1;
                second_num += "1";
            } else {
                second_num += "0";
            }
        }
        
        int first_one;
        for(int j = 0; j < second_num.length(); j++){
            if(second_num[j] == '1'){
                first_one = j;
                break;
            }
        }
        second_num.erase(0, first_one);
        printf("Case #%d: ", i + 1);
        cout<<second_num<<" "<<s<<endl;
    }
}
