#include <iostream>

using namespace std;

int N, K, L;
int answer;

int main()
{
	cin >> N >> K >> L;
	
	// printf("%d %d %d", N, K, L);
	
	while(1)
	{
		if(K==L)
		{
			break;
		}
		K = (int)((K+1)/2);
		L = (int)((L+1)/2);		
		answer++;
	}
	
	cout << answer;
	
	return 0;
}
