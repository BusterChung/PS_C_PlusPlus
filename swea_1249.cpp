/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
