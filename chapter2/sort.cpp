//
// Created by 김헌우 on 2023/06/30.
//

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[4];
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    sort(arr, arr+3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }

}
#include <bits/stdc++.h>
using namespace std;

int main1(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin >> year;

    if(year % 4 == 0){
        // 4의 배수이면서 400의 배수
        if(year % 400 == 0)  cout << 1;
            // 4의 배수이면서 100의 배수
        else if(year % 100 == 0)  cout << 0;
            // 4의 배수이면서 100, 400의 배수가 아닌 수
        else  cout << 1;
    }
        // 4의 배수가 아닌 수
    else  cout << 0;
}