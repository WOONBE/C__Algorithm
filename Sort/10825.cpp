#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;
int n;
string name;
int score1,score2,score3;

struct Student{
    string student_name;
    int kor_score;
    int eng_score;
    int math_score;
};

bool compare(Student s1, Student s2){
    if(s1.kor_score == s2.kor_score){
        if(s1.eng_score == s2.eng_score){
            if(s1.math_score == s2.math_score){
                return s1.student_name < s2.student_name;
            }
            return s1.math_score > s2.math_score;
        }
        return s1.eng_score < s2.eng_score;
    }
    return s1.kor_score > s2.kor_score;
}

vector<Student> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name >> score1 >> score2 >> score3;
        v.push_back({name,score1,score2,score3});
    }
    sort(v.begin(),v.end(), compare);


    for(int i=0; i<n; i++){
        cout << v[i].student_name << "\n";
    }
}
