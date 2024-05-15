#include <iostream>
#include <string>

using namespace std;

string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,s)){
        int s_len = s.size();

        cout << s_len << "\n";
    }
    return 0;

}
