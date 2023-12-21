#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

// Programmers 코딩테스트 LV.2: 단체사진 찍기

using namespace std;

string KAKAO = "ACFJMNRT";

bool Cond(char opr, int num, int diff) {
        if(opr == '=') 
            return num == diff;
        if(opr == '>') 
            return diff > num;
        if(opr == '<') 
            return diff < num;
}


int solution(int n, vector<string> data) {
    int answer = 0;
    vector<vector<char>> s;
    
    int Source, Target, diff, distance;
    
    do {
        bool check = true;
        for(string text : data) {
            Source = KAKAO.find(text[0]);
            Target = KAKAO.find(text[2]);
            diff = abs(Source - Target)-1;
            distance = text[4] -'0';
            
            if(Cond(text[3], distance, diff)) continue;
            check = false;
            break;
        }
        if(check) answer++;
   
    }while(next_permutation(KAKAO.begin(), KAKAO.end()));
    
    return answer;
}
