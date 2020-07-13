#include <iostream>

using namespace std;

int main()
{
	int answer = -1;
	int num = 0;
	int a =0, b = 0;
	
	for(int i=0; i<4; i++)
	{
		cin >> b >> a;
		fflush(stdin);
		
		num -= b;		
		if (num>answer)
		{
			answer = num;
		}
		
		num += a;		
		if (num>answer)
		{
			answer = num;
		}
	}
	
	cout << answer;
	
	return 0;
}
