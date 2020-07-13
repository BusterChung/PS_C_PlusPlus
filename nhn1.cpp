#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

char input[200];
int ipv6[8];

int main() {
   cin >> input;
	
   for(int i=0; i<8; i++)
   {
      int n_ipv6 = 0;
		 
      for(int j=0; j<16; j++)
      {
	    if (input[i * 16 + j] == '0')
	    {
	    	continue;
		}
		
		int tmp = pow(2, (15 - j));
		
        n_ipv6 += tmp;
        
      }
      ipv6[i] = n_ipv6;
   }
	
   for(int i=0; i<8; i++)
   {
      if (i == 0)
			{
         cout << std::hex << ipv6[i];
			}
      else
			{
         cout << ":" << setw(4) << setfill('0') << std::hex << ipv6[i];
			}
   }
	
   cout << endl;
	
   return 0;
}
