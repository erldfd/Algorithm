#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int PeopleCount = 0;
	cin >> PeopleCount;
	int PeopleSquare = PeopleCount * PeopleCount;
	vector<int> AbilityTable(PeopleSquare, 0);
	for (int i = 0; i < PeopleSquare; ++i)
	{
		cin >> AbilityTable[i];
	}

	vector<bool> Combination;
	Combination.reserve(PeopleCount);

	int HalfPeople = PeopleCount / 2;

	for (int i = 0; i < HalfPeople; ++i)
	{
		Combination.push_back(false);
	}

	for (int i = 0; i < HalfPeople; ++i)
	{
		Combination.push_back(true);
	}

	int MinPowerGap = 2'000'000'000;

	do
	{
		int StartTeamPower = 0;
		int LinkTeamPower = 0;
		vector<int> StartTeamMembers;
		vector<int> LinkTeamMembers;

		for (int i = 0; i < PeopleCount; ++i)
		{
			if (Combination[i])
			{
				StartTeamMembers.push_back(i);
			}
			else
			{
				LinkTeamMembers.push_back(i);
			}
		}

		vector<bool> TeamCombination;

		for (int i = 0; i < 2; ++i)
		{
			TeamCombination.push_back(true);
		}

		for (int i = 0; i < HalfPeople - 2; ++i)
		{
			TeamCombination.push_back(false);
		}

		do
		{
			int i = -1;
			int j = -1;

			for (int a = 0; a < HalfPeople; ++a)
			{
				if (TeamCombination[a])
				{
					if (i == -1)
					{
						i = a;
					}
					else
					{
						j = a;
						break;
					}
				}
			}

			StartTeamPower += AbilityTable[StartTeamMembers[i] * PeopleCount + StartTeamMembers[j]];
			StartTeamPower += AbilityTable[StartTeamMembers[j] * PeopleCount + StartTeamMembers[i]];
			LinkTeamPower += AbilityTable[LinkTeamMembers[i] * PeopleCount + LinkTeamMembers[j]];
			LinkTeamPower += AbilityTable[LinkTeamMembers[j] * PeopleCount + LinkTeamMembers[i]];

		} while (prev_permutation(TeamCombination.begin(), TeamCombination.end()));

		MinPowerGap = min(MinPowerGap, abs(StartTeamPower - LinkTeamPower));

	} while (next_permutation(Combination.begin(), Combination.end()));

	cout << MinPowerGap;

	return 0;
}