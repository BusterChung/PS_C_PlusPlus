#include <iostream>
#include <queue>

using namespace std;

int N, G, M;

int gas_stations[10000];
int gas_supplies[10000];


int main() {

	cin >> N >> G >> M; fflush(stdin);
	
	for(int i=0; i<M; i++)
	{
		cin >> gas_stations[i];
	}
	fflush(stdin);
	for(int i=0; i<M; i++)
	{
		cin >> gas_supplies[i];
	}
	fflush(stdin);
	
	int answer = 0;
	int idx = 0;
	priority_queue <int, vector<int>, less<int> > pq;
	
	while (G < N)
	{
		for(int i=idx; i<M; i++)
		{
			// cout <<"i " << i <<endl;
			
			if (gas_stations[i] <= G)
			{
				// cout << "1 " << gas_stations[i] << " " << G << endl;
				pq.push(gas_supplies[idx]);
				idx = i + 1;
			}
			else
			{
				// cout << " else" << endl;
				break;
			}
		}

		
		if(pq.size())
		{
			G += pq.top();
			pq.pop();
			answer ++;
		}
		else
		{
			answer = -1;
			break;
		}
	
	}
	
	cout << answer;
	
	return 0;
}
