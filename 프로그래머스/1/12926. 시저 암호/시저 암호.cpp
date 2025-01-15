#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(auto &a: s) {
        if(islower(a)) {
            if(!islower(a+=n%26))
                a-=26;
        } else if(isupper(a)) {
            if(!isupper(a+=n%26))
                a-=26;
        }
    }
    return s;
}