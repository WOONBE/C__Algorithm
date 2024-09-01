//
// Created by 김헌우 on 2024/09/01.
//14568

#include <iostream>

using namespace std;

int num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> num;

    int ans = 0;
    for(int a = 0; a<num+1; a++){
        for(int b = 0; b<num+1; b++){
            for(int c = 0; c<num+1; c++){
                if(a+b+c == num){
                    if(a >= b+2){
                        if(a !=0 && b != 0 && c !=0){
                            if(c %2 == 0){
                                ans++;

                            }
                        }
                    }


                }

            }
        }

    }
    cout << ans;


}
