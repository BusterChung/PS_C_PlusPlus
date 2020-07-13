#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, D, H;

int days[100];
int visited[100];

int main() {
   
   cin >> N >> M >> D; fflush(stdin);
   
   for(int i=0; i<M; i++)
   {
      cin >> H;
      days[H] = 1;
      visited[H] = 0;
   }
   fflush(stdin);
   
   queue<int> q;
	
   for(int i=0; i<H; i++)
   {
		if (days[i] == 0)
		{
			q.push(i);
			visited[i] = 1;
		}
   }
   
   int tmp;
	
   while(q.size())
   {
      tmp = q.front();
      q.pop();
      
      for(int i=tmp+1; i<=tmp+D; i++)
      {
         if (i > N)
         {
            break;
         }
         
         if (visited[i] == 0 || visited[i] > visited[tmp] + 1)
		 {
            if (days[i] == 0)
			{
               q.push(i);
               visited[i] = visited[tmp] + 1;
            }
         }
      }   
   }
   
   int mini = 200;
   
   for(int i=N-1;i>N-D+1;i--)
   {
      if (visited[i] == 0)
      {
	  	continue;
	  }
      if (visited[i] < mini)
      {
	  	mini = visited[i];
	  }
   }
   
   if (mini == 200)
   {	
   		mini = -1;   
   }
   cout << mini << endl;
   
   return 0;
}
