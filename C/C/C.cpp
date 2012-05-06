#include <stdio.h>
#include <string.h>

int a[10009];
int main()
{
	int test;
	freopen("C.in", "r", stdin);
	freopen("C.out","w", stdout);
	scanf("%d", &test);
	while (test--)
	{
			int n;
			scanf("%d ", &n);
			memset(a, 0, sizeof(a));
			int m  = -1;
			for (int i = 0; i <n ; ++ i)
			{
				int t;
				scanf("%d", &t);
				++a[t];
				if (a[t] > m)
					m = a[t];

			}
			printf("%d\n", m);
	}
	return 0;
}