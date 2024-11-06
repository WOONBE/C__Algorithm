#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    First

    long long num;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        long long x,y;
        long long move,max = 0;
        cin >>x>>y;
        while(max*max <= y-x)
            max++;
        max--;
        move = 2*max -1; //10 = 1 2 3 2 1 1 : 6
        long long rem = y-x - max*max;
        rem = (long long)ceil((double)rem / (double)max);
        move += rem;
        cout << move << "\n";
    }

}