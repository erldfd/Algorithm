#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Memory(46, -1);

int GetFibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}

	if (Memory[n] != -1)
	{
		return Memory[n];
	}

	Memory[n] = GetFibonacci(n - 1) + GetFibonacci(n - 2);

	return Memory[n];
}

int main()
{
	int N;
	cin >> N;

	cout << GetFibonacci(N);

	return 0;
}