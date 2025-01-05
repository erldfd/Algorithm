using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long neededMoney = 0;
    
    for(int i = 0; i < count; ++i)
    {
        neededMoney += (i+1) * price;
    }
    
    answer = neededMoney - money;
    
    if(answer < 0)
    {
        answer = 0;
    }

    return answer;
}