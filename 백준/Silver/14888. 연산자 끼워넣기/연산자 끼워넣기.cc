#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int NumCount = 0;
	cin >> NumCount;

	vector<int> Numbers(NumCount, 0);
	for (int i = 0; i < NumCount; ++i)
	{
		cin >> Numbers[i];
	}

	int PlusCount = 0;
	int SubtractCount = 0;
	int MultiplyCount = 0;
	int DivideCount = 0;

	cin >> PlusCount;
	cin >> SubtractCount;
	cin >> MultiplyCount;
	cin >> DivideCount;

	// 0 , 1, 2, 3 + - * /
	vector<int> Operators;
	for (int i = 0; i < PlusCount; ++i)
	{
		Operators.push_back(0);
	}

	for (int i = 0; i < SubtractCount; ++i)
	{
		Operators.push_back(1);
	}

	for (int i = 0; i < MultiplyCount; ++i)
	{
		Operators.push_back(2);
	}

	for (int i = 0; i < DivideCount; ++i)
	{
		Operators.push_back(3);
	}


	int MaxValue = -1'000'000'000;
	int MinValue = 1'000'000'000;

	do
	{
		int Value = Numbers[0];

		for (int i = 0; i < NumCount - 1; ++i)
		{
			if (Operators[i] == 0)
			{
				Value += Numbers[i + 1];
			}
			else if (Operators[i] == 1)
			{
				Value -= Numbers[i + 1];
			}
			else if (Operators[i] == 2)
			{
				Value *= Numbers[i + 1];
			}
			else
			{
				if (Value < 0)
				{
					Value = -(-Value / Numbers[i + 1]);
				}
				else
				{
					Value /= Numbers[i + 1];
				}
			}
		}

		MinValue = min(Value, MinValue);
		MaxValue = max(Value, MaxValue);

	} while (next_permutation(Operators.begin(), Operators.end()));

	cout << MaxValue << endl;
	cout << MinValue << endl;

	return 0;
}