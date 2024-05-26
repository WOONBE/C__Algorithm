#include <iostream>
#include <string>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    int b;

    int result = 0;
    cin >> n >> b;

    for(int i=0; i<n.size(); i++){
        if('0'<=n[i] && n[i] <='9'){
            result = result * b + (n[i] - '0');
        }
        else{
            result = result * b + (n[i] - 'A' + 10);
        }
    }
    cout << result;
    return 0;


}
