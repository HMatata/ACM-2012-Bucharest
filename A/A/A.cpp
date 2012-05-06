#include <stdio.h>
#include <string.h>
int a[64];
int main()
{
	while (1)
	{
		int n, p;
		scanf("%d %d", &n, &p);
		if (n == 0)
			return 0;
		int m = 0, ip = p, i = 0;
		memset(a, 0, sizeof(a));
		while (1)
		{
			
			if (p > 0)
			{
				++a[i];
				--p;
				if (a[i] > m)
					m = a[i];

			}
			else
				p = a[i], a[i] = 0;
			if (m == ip)
				break;
			
			++i;
			if (i == n)
				i = 0;
		}
		printf("%d\n", i);
	}

	
}