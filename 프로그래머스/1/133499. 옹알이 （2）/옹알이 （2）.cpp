#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> BabblingWords;

bool IsPossibleToBabbling(const string& word)
{
    for(const auto& BabblingWord : BabblingWords)
    {
        if (BabblingWord == word)
        {
            return true;
        }
    }
    
    return false;
}

int solution(vector<string> babbling) 
{
    BabblingWords = {"aya", "ye", "woo", "ma"};
    
    int answer = 0;
    
    for(const auto& word : babbling)
    {
        string PartOfWord = "";
        string PrevWord = "";
        int answerCount = 0;
        
        for(int i = 0; i < word.size(); ++i)
        {
            PartOfWord += word[i];
            
            if(IsPossibleToBabbling(PartOfWord) && PartOfWord != PrevWord)
            {
                answerCount = 1;
                PrevWord = PartOfWord;
                PartOfWord = "";
            }
            
            if(i == word.size() - 1 && PartOfWord.size() > 0)
            {
                answerCount = 0;
            }
        }
        
        answer += answerCount;
    }
    
    
    return answer;
}