#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, t;
vector <int> prev_line, cur_line;

int main()
{
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		if (cur_line.size())
		{
			cur_line.clear();
		}
		
		for(int j=0; j<i+1; j++)
		{
			scanf("%1d", &t);
			if (prev_line.size())
			{
				if (j==0)
				{
					t = t+prev_line[0];
				}
				else if (j == i)
				{
					t = t+prev_line[j-1];
				}
				else
				{
					t = t + max(prev_line[j-1], prev_line[j]);
				}
			}			
			cur_line.push_back(t);		
		}
		prev_line = cur_line;
		for(int j=0; j<cur_line.size();j++)
		{
			cout << cur_line[j] <<" ";
		}
		cout <<endl;
	}
	//cout << "1" <<endl;
	int answer = -1;
	for(int i=0;i<cur_line.size();i++)
	{
		//cout << cur_line[i] << " ";
		if (answer < cur_line[i])
			answer = cur_line[i];
	}
	cout<<answer;
	
	return 0;
}
