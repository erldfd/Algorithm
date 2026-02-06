#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

// 왼쪽에서 0만날때까지 소수 검사
// 오른쪽에서 0 만날 때까지 소수 검사
// 전체가 소수인지 검사
// 0이 시작하면 쭉 찾고 0이 또 나오면 이제 소수 검사
// 0을 포함하면 안 됨.
// 걍 0 만날 때마다 소수 검사하면 끝인듯

unordered_set<int> PrimeCaches;

bool IsPrime(long long Num)
{
    if(Num < 2)
    {
        return false;
    }
    
    if(PrimeCaches.find(Num) != PrimeCaches.end())
    {
        return true;
    }
    
    for(long long i = 2; i*i <= Num; ++i)
    {
        if(Num % i == 0)
        {
            return false;
        }
    }
    
    PrimeCaches.insert(Num);
    return true;
}

string Convert(int Num, int k)
{
    if(k == 10)
    {
        return to_string(Num);
    }
    
    string Temp = "";
    while(Num > 0)
    {
        Temp.push_back(Num % k + '0');
        Num /= k;
    }
    
    reverse(Temp.begin(), Temp.end());
    return Temp;
}

int Check(const string& str)
{
    string Temp = "";
    int Count = 0;
    for(char c : str)
    {
        if(c == '0')
        {
            if(Temp.size() > 0 && IsPrime(stoll(Temp)))
            {
                Count++;
            }
            
            Temp = "";
        }
        else
        {
            Temp += c;
        }
    }
    
    if(Temp.size() > 0 && IsPrime(stoll(Temp)))
    {
        Count++;
    }
    
    return Count;
}

int solution(int n, int k) 
{
    PrimeCaches.insert(2);
    PrimeCaches.insert(3);
    
    return Check(Convert(n, k));;
}