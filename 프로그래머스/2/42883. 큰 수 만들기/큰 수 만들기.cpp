#include <string>
using namespace std;

string solution(string number, int k) {
    string result = ""; // 스택 역할
    int toRemove = k;
    for (int i = 0; i < (int)number.length(); ++i) {
        char c = number[i];
        // 스택의 마지막보다 현재 문자가 크고, 아직 지울 수 있으면 pop
        while (!result.empty() && toRemove > 0 && result.back() < c) {
            result.pop_back();
            --toRemove;
        }
        result.push_back(c);
    }
    // 아직 지워야 할 게 있으면 뒤에서부터 제거
    if (toRemove > 0) {
        result.erase(result.end() - toRemove, result.end());
    }
    // 필요한 길이만 남기기 (안전장치)
    int keepLen = (int)number.length() - k;
    if ((int)result.length() > keepLen) {
        result = result.substr(0, keepLen);
    }
    return result;
}
