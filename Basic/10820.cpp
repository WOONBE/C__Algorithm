#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int a=0,b=0,c=0,d=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') a++;
            else if (s[i] >= 'A' && s[i] <= 'Z') b++;
            else if (s[i] >= '0' && s[i] <= '9') c++;
            else if (s[i] == ' ') d++;
        }
        cout << a << " " << b << " " << c << " " << d << '\n';
    }
    return 0;
}