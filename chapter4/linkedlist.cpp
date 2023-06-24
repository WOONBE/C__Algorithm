#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){ //이건 구현 못했음
    //addr은 넣고 싶은 주소
    dat[unused] = num; //원소 생성
    pre[unused] = addr; //앞주소를 지정
    nxt[unused] = nxt[addr]; // 다음 주소 지정
    if(nxt[addr] != -1) pre[nxt[addr]] = unused; //다음 원소 없을때빼고 다음 원소가 unused 가리키게 한다
    nxt[addr] = unused; //이전 원소가 unused 가리키게 한다
    unused++;

}

void erase(int addr){ //이건 구현했음
    nxt[pre[addr]] = nxt[addr]; //이전 위치 nxt를 삭제위치 nxt로, 밑에 if 안해줘도 됨(dummy로 인하여 항상 pre의 존재는 보장된다)
    if(nxt[addr]!=-1) pre[nxt[addr]] = pre[addr]; //다음 위치 pre를 삭제 위치 pre로

}

void traverse(){ //전체 출력
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}