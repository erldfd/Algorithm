
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.rbegin(),X.rend());
    sort(Y.rbegin(),Y.rend());
    int xsize = X.size(), ysize = Y.size(), xidx = 0, yidx = 0;
    while(1){
        if(xidx == xsize || yidx == ysize)  break;
        if(X[xidx] == Y[yidx]){
            answer += X[xidx];
            xidx++;
            yidx++;

        }
        else if(X[xidx] < Y[yidx]){
            yidx++;
        }
        else{
            xidx++;
        }
    }
    if (answer.empty()) answer += "-1";
    if(answer[0] == '0'){
        answer.clear();
        answer += '0';
    }
    return answer;
}