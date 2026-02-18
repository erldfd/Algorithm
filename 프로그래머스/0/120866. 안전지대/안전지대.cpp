#include <string>
#include <vector>

using namespace std;

// 12 1 3 5 6 7 9 11
int Dx[] {-1, -1, 0, 1, 1, 1, 0, -1};
int Dy[] {0, 1, 1, 1, 0, -1, -1, -1};

int solution(vector<vector<int>> board) 
{
    const int Size = board.size();
    int answer = Size * Size;

    for(int i = 0; i < Size; ++i)
    {
        for(int j = 0; j < Size; ++j)
        {
            if(board[i][j] == 0 || board[i][j] == 2)
            {
                continue;
            }

            answer--;
            board[i][j] = 2;
            
            for(int k = 0; k < 8; ++k)
            {
                int X = i + Dx[k];
                int Y = j + Dy[k];
                
                if(X >= Size || Y >= Size || X < 0 || Y < 0)
                {
                    continue;
                }
                
                if(board[X][Y] == 0)
                {
                    board[X][Y] = 2;
                    answer--;
                }
            }
        }
    }
    
    return answer;
}