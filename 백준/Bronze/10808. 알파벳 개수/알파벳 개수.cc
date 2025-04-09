#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> Vec('z' - 'a' + 1, 0);

	string Word = "";
	cin >> Word;

	for (auto& W : Word)
	{
		Vec[W - 'a']++;
	}

	for (auto& V : Vec)
	{
		cout << V << " ";
	}

	return 0;
}