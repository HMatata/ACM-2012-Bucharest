#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

long double a[3][128];
long double ABS(long double x)
{
	if (x < 0)
		return -x;
	return x;
}
int main()
{
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);

	do
	{
		int c, n, m;
		
		scanf("%d %d %d", &c, &n, &m);
		if (c == 0)
			return 0;

		if( m > c || !n )
		{
			printf("%.3LF\n",0);
			continue;
		}

		memset(a, 0, sizeof(a));

		long double var;
		int step1 = 0,step2 = 1,i;
		a[step1][1] = 1; n--;
		
		int good = 0;
		while( n-- )
		{
			if (!good)
			{
				memset( a[step2], 0, 128 * sizeof(long double) );

				a[step2][1] = a[step1][0] * 1; 

				for( i = 1; i <= c; ++ i )
				{
					var = a[step1][i];
					a[step2][ i-1 ] += var * i / c;
					a[step2][ i+1 ] += var * ( c-i ) / c;

				}

				/*for( i = 0; i <=c; ++i )
					cout << a[step2][i] << " ";
				cout << endl;*/
				
				long double diff = 0;
				for (i = 0; i <= c; ++i)
					diff+=ABS(a[step2][i]-a[3][i]);
				if (diff < 0.000000001)
					good = 1;
				else
					memcpy(a[3], a[step1], sizeof(long double) *128);
			}
			
			step1 = 1-step1;
			step2 = 1-step2;
		}
		/*	for( i = 0; i <=c; ++i )
				cout << a[step1][i] << " ";
			cout << endl;*/
		printf("%.3Lf\n", a[step1][m]);

	} while (1);
	return 0;
}