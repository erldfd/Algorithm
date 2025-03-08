#include <string>
#include <vector>

using namespace std;

vector<string> dictionary;  // 사전 역할을 할 벡터
string vowels = "AEIOU";

void generate(string current) {
    if (current.length() > 5) return;  // 길이가 5를 넘으면 중단
    
    dictionary.push_back(current);  // 생성한 단어 저장
    
    for (char c : vowels) {  
        generate(current + c);  // 다음 문자 추가하여 재귀 호출
    }
}

int solution(string word) {
    generate("");  // 빈 문자열부터 시작하여 모든 단어 생성
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == word) return i;  // 주어진 단어의 인덱스 반환
    }
    return -1;  // 이론상 실행되지 않음
}
