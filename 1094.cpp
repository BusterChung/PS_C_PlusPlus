#include <iostream>

using namespace std;

int X, answer, m, n;

int main()
{
	cin >> X;
	
	while (X>1)
	{
		m = (int)(X/2);
		n = X%2;
		if(n==1)
		{
			answer++;
		}
		X = m;
	}
	
	cout << ++answer;
		
	return 0;
}
