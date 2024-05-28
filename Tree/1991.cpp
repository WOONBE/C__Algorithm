#include <iostream>
#include <vector>

using namespace std;

pair<char,char> node[26];

int n;
char lft, rgt,p;

void preorder(char s){
    if(s == '.')
        return;
    cout << s;
    preorder(node[s-'A'].first);
    preorder(node[s-'A'].second);
}

void inorder(char s){
    if(s == '.')
        return;

    inorder(node[s-'A'].first);
    cout << s;
    inorder(node[s-'A'].second);

}

void postorder(char s){
    if(s == '.')
        return;

    postorder(node[s-'A'].first);
    postorder(node[s-'A'].second);
    cout << s;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p >> lft >> rgt;
        node[p-'A'].first = lft;
        node[p-'A'].second = rgt;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
}
