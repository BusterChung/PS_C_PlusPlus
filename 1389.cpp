#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;


int main()
{
	cin >> N>>M;
	fflush(stdin);
	int rship[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==j)
			{
				rship[i][j] = 0;
			}
			else
			{
				rship[i][j] = N*N;
			}
		}
	}
	for(int i=0; i<M; i++)
	{
		cin >> a >> b;
		rship[a-1][b-1] = rship[b-1][a-1] = 1;
		
		fflush(stdin);
	}
	/*
	for(int i=0; i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << rship[i][j] << " ";
		}
		cout << endl;
	}*/
	
	for(int k=0; k<N;k++)
	{
		for(int i=0; i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i != j)
				{
					rship[i][j] = min(rship[i][j], rship[i][k] + rship[k][j]);
				}
			}
		}
	}
	
	/*for(int i=0; i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << rship[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int kv = N*N;
	int answer = 0;
	
	for(int i=0;i<N;i++)
	{
		int tmp = 0;
		for(int j=0;j<N;j++)
		{
			tmp += rship[i][j];
		}
		if(kv > tmp)
		{
			kv = tmp;
			answer = i;
		}
	}
	
	cout << ++answer;
	
	return 0;
}
