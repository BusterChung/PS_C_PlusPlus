#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int N, M;

char s[100][100];


int cnt_w, cnt_b;

int my_min(int a, int b, int c)
{
	int t = min(a, b);
	
	return min(t, c);	
}

int main()
{
    cin >> N >> M;
    
	int result = N*M;
    
	fflush(stdin);
    
    for(int i=0; i < N; i++)
    {
		for(int j=0; j<M; j++)
		{
			scanf("%c", &s[i][j]);
		}
		fflush(stdin);
	}
	
	fflush(stdin);
	
	/*
	for(int i=0; i < N; i++)
    {
		for(int j=0; j<M; j++)
		{
			printf("%c ", s[i][j]);
		}
		cout << "endl" << endl;
	}	
	*/
	
	for(int i=0;i<N-8+1;i++)
	{
		for(int j=0;j<M-8+1;j++)
		{
			printf("%d %d\n", i, j);
			cnt_w = 0;
			cnt_b = 0;
			for(int r=0;r<8;r++)
			{
				for(int c=0;c<8;c++)
				{
					if ((r+c) % 2)
					{
						if (s[i+r][j+c] == 'B')
						{
							cnt_w += 1;
						}
						else
						{
							cnt_b += 1;
						}
					}
					else
					{
						if (s[i+r][j+c] == 'W')
						{
							cnt_w += 1;
						}
						else
						{
							cnt_b += 1;
						}
					}
				}
			}
			result = my_min(result, cnt_w, cnt_b);
			// printf("%d %d %d\n", result, cnt_w, cnt_b);
		}
	}
	
	cout << result;
	
    return 0;
}
