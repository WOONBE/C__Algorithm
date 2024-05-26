#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,b;
    string result;
    cin >> n >> b;

    while(n>0){
        int tmp = n %b;
        if(0<=tmp && tmp<=9)
            result += (tmp+'0');
        else{
            result += (tmp-10 +'A');

        }
        n/=b;
    }
    for(int i=result.length()-1; i>=0; i--){
        cout << result[i];
    }
    return 0;
}
