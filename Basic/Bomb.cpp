#include <iostream>

#define MAX_NUM 100

using namespace std;

int n, m, end_of_array, end_of_temp;
int numbers[MAX_NUM];
int temp[MAX_NUM];

// 주어진 시작점에 대하여
// 부분 수열의 끝 위치를 반환합니다.
int GetEndIdxOfExplosion(int start_idx, int curr_num) {
    int end_idx = start_idx + 1;
    while(end_idx < end_of_array) {
        if(numbers[end_idx] == curr_num)
            end_idx++;
        else{
            break;
        }
    }

    return end_idx - 1;
}

// 터져야 할 폭탄들에 대해 터졌다는 의미로 0을 채워줍니다.
void FillZero(int start_idx, int end_idx) {
    for(int i = start_idx; i <= end_idx; i++) {
        numbers[i] = 0;
    }
}

// Arr에서 폭탄이 터진 이후의 결과를 Temp에 임시로 저장합니다.
void MoveToTemp() {
    end_of_temp = 0;
    for(int i = 0; i < end_of_array; i++) {
        if(numbers[i] != 0) {
            temp[end_of_temp++] = numbers[i];
        }
    }
}

// Temp배열을 그대로 Copy하여 Arr에 저장합니다.
void Copy() {
    end_of_array = end_of_temp;
    for(int i = 0; i < end_of_array; i++) {
        numbers[i] = temp[i];
    }
}

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    end_of_array = n;

    bool did_explode = true; // 최초 진입을 위해 true로 설정
    while(did_explode) {
        did_explode = false;
        for(int curr_idx = 0; curr_idx < end_of_array; curr_idx++) {
            // 각 위치마다 그 뒤로 폭탄이 m개 이상 있는지 확인합니다.

            // 이미 터지기로 예정되어있는 폭탄은 패스합니다.
            if(numbers[curr_idx] == 0) {
                continue;
            }
            // curr_idx로부터 연속하여 같은 숫자를 갖는 폭탄 중
            // 가장 마지막 위치를 찾아 반환합니다.
            int end_idx = GetEndIdxOfExplosion(curr_idx, numbers[curr_idx]);

            if(end_idx - curr_idx + 1 >=  m) {
                // 연속한 숫자의 개수가 m개 이상인 경우 폭탄이 터졌음을 기록해줍니다.
                FillZero(curr_idx, end_idx);
                did_explode = true;
            }
        }

        // Arr에서 폭탄이 터진 이후의 결과를 Temp에 임시로 저장합니다.
        MoveToTemp();
        // Temp배열을 그대로 Copy하여 Arr에 저장합니다.
        Copy();
    }

    cout << end_of_array << endl;
    for(int i = 0; i < end_of_array; i++)
        cout << numbers[i] << endl;

    return 0;
}
