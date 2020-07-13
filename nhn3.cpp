#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1,0} };

char input[1000][1000];
bool visited[1000][1000] = { false, };

vector <int> all_islands;
vector <int> island;

int contient;

int s_island;
int b_island;
double avg_island;
double mid_island;
   
int landSearch(int x, int y) {
	
   if (visited[x][y]) 
   {
   	return 0;
   }
   
   visited[x][y] = true;

   int land_num = 0;
   
   for(int i=0; i<4; i++)
   {
      int r = x + dir[i][0];
      int c = y + dir[i][1];

      if (r < 0 || c < 0 || r >= N || c >= N)
      {
	  	continue;
	  }

      if (input[r][c] == 'L' && visited[r][c] == false)
      {
      	land_num += landSearch(r, c);
	  }
   }

   return land_num + 1;
}

int main() {
	
   cin >> N; fflush(stdin);
   
   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
	  {
         cin >> input[i][j];
      }
   }
   fflush(stdin);

   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
	  {
         if (input[i][j] == 'L' && visited[i][j] == false)
		 {
            int l_num = landSearch(i, j);
            
            if (l_num != 0)
			{
               if (contient < l_num)
			   {
                  contient = l_num;
               }
               
               all_islands.push_back(l_num);
            }
         }

      }
   }

   int all_size = all_islands.size();
   
   for(int i=0; i<all_islands.size(); i++)
   {
      if (all_islands[i] != contient)
	  {
         island.push_back(all_islands[i]);
      }
   }

   int i_size = island.size();

   if (i_size == 0)
   {
      printf("%d %d %.2f %.0f\n", b_island, s_island, avg_island, mid_island);
   }
   else
   {
      int islandSum = 0;
      
      sort(island.begin(), island.end());
      
      for(int i=0; i<i_size; i++)
	  {
         islandSum += island[i];
      }

      s_island = island[0];
      b_island = island[i_size - 1];
      
      avg_island = (double) islandSum / i_size;
      
      if (i_size % 2 == 0)
	  {
         mid_island = (island[(int)(i_size / 2)] + island[(int)(i_size / 2) - 1]) / 2;
      }
      else
	  {
         mid_island = island[(int)i_size / 2];
      }

      if (mid_island - (int)mid_island == 0)
	  {
         printf("%d %d %.2f %.0f\n", b_island, s_island, avg_island, mid_island);
      }
      else
	  {
         printf("%d %d %.2f %.2f\n", b_island, s_island, avg_island, mid_island);
      }
   }

   return 0;
}
