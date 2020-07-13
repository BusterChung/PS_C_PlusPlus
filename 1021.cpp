#include <cstdio>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector <int> numbers;

vector <int> my_lst;

int find_idx;

int cnt;



void print(vector <int> lst)
{
	for(int i=0;i<lst.size();i++)
	{
		cout<<lst[i]<<" ";
	}
	cout<<endl;
}

void print(int *arr, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	cin>>N >> M;
	fflush(stdin);

		
	for(int i=0;i<N;i++)
	{
		my_lst.push_back(i+1);
	}
	
	for(int i=0;i<M;i++)
	{
		int t;
		cin >> t;
		numbers.push_back(t);
	}
	fflush(stdin);
	
	print(my_lst);
	print(numbers);
	
	for(int i=0;i<numbers.size();i++)
	{
		int pos = numbers[i];
		if (pos == my_lst[0] || my_lst.size() == 1)
		{
			my_lst.erase(my_lst.begin());
		}
		else
		{
			find_idx = *find(my_lst.begin(), my_lst.end(), pos);
			if (find_idx <= int(my_lst.size() / 2))
			{
				rotate(my_lst.begin(), my_lst.begin()+find_idx, my_lst.end());
				cnt += find_idx;
			}
			else
			{
				rotate(my_lst.begin(), my_lst.begin()+my_lst.size(), my_lst.end());
				cnt += (my_lst.size() + find_idx);
			}
			my_lst.erase(my_lst.begin());
		}
	}
	
	cout << cnt;
	
	
	return 0;
}
