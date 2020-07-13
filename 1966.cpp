#include <iostream>
#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int> > dq;
int tc, N, M, tmp, p, key, item;
pair<int, int> target_p, tmp_p;

int priority_print(int print_count)
{
	p = -1;
	for(int i=0; i<(int)dq.size();i++)
	{
		if(p<dq[i].second)
		{
			p = dq[i].second;
		}
	}
	
	key = dq[0].first;
	item = dq[0].second;
	if(p==item)
	{
		if(M==key)
			return print_count;
		else
		{
			dq.pop_front();
			priority_print(print_count+1);
		}
	}	
	else
	{
		tmp_p = dq.front();
		dq.pop_front();
		dq.push_back(tmp_p);
		return priority_print(print_count);
	}
}

int main()
{
	int tc = 0;
	cin >> tc; fflush(stdin);
	for(int test_c=0; test_c<tc; test_c++)
	{
		cin >> N >> M; fflush(stdin);
		for(int i=0;i<N;i++)
		{
			scanf("%1d", &tmp);
			if (i == M)
			{
				target_p.first = i;
				target_p.second = tmp;
			}
			dq.push_back(pair<int, int>(i, tmp));
		}
		
		for(int i=0;i<N;i++)
		{
			cout<<dq[i].first << " " << dq[i].second<<endl;
		}
		
		
		cout << priority_print(1);
		
	}
	

	
	return 0;
}
