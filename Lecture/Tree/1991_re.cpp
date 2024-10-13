#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<pair<char,char>> v;
int N;

void preOrder(char s){
    if(s == '.') return;

    cout << s;
    preOrder(v[s-'A'].first);
    preOrder(v[s-'A'].second);




}

void inOrder(char s){
    if(s == '.') return;

    inOrder(v[s-'A'].first);
    cout << s;
    inOrder(v[s-'A'].second);


}

void postOrder(char s){
    if(s == '.') return;

    postOrder(v[s-'A'].first);
    postOrder(v[s-'A'].second);
    cout << s;


}
int main(){
    First

    cin >> N;
    v.resize(N);

    char val,l_val,r_val;

    for(int i=0; i<N; i++){
        cin >> val >> l_val >> r_val;
        v[val-'A'].first = l_val;
        v[val-'A'].second = r_val;
    }

//    for(auto i : v){
//        cout << i.first << ' ' << i.second << "\n";
//    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout <<"\n";



}