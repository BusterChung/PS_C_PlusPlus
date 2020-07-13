/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#define INF 987654321

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int test_case;
int T;

	
int N;
int my_map[101][101];		
int my_dist[101][101];
int answer = INF;
		
void bfs(int i, int j, int cost)
{
	if (i == j == N-1)
	{
		return;
	}
	else
	{
		cost += my_map[i][j];
		if (my_dist[i][j] > cost)
		{
			my_dist[i][j] = cost;
		}
		if (answer > cost)
		{
			answer = cost;
		}
		for(int k=0; k<4; k++)
		{
			int new_i = i+dy[i];
			int new_j = j+dx[i];
			bfs(new_i, new_j, cost);
		}
	}
}

int main(int argc, char** argv)
{
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cin >> my_map[i][j];
				my_dist[i][j] = INF;
			}
		}
		fflush(stdin);
		
		cout << T << ", "<< N<<endl;
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout << " " << my_map[i][j];
			}
			cout << endl;
		}
		
		
		bfs(0, 0, 0);
		
		cout << "#" << T <<" " <<answer<<endl;		
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
