#include <iostream>

using namespace std;

int M, answer=1;

int main()
{
	cin >> M;
	fflush(stdin);	
	
	for(int i=0;i<M;i++)
	{
		int a = 0, b = 0;
		
		cin >> a >> b;
		fflush(stdin);
		
		if(a==answer)
		{
			answer = b;
		}
		else if(b==answer)
		{
			answer = a;
		}
	}
	
	cout << answer;
	
	return 0;
}
