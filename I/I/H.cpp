#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
char a[1024][9];
char cost[1024];
int solve ( vector < int > v, int depth)
{
	if (depth > 7 || v.empty())
			return 0;
	vector < int > t[10];
	for (vector < int >::iterator it = v.begin(); it!=v.end(); ++ it)
		t[a[*it][depth]].push_back(*it);
		
}
int main()
{
	int test;
	scanf("%d", &test);	
	while (test --)
	{
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		vector < int > v;
		for (int i = 0; i < n; ++ i)
		{
				scanf("%s %d", a[i], &cost[i]);
				int l = strlen(a[i]);
				for (int j = 0; j < l; ++j)
					a[i][j] = a[i][j]-'0';
				v.push_back(i);
		}
		printf("%d\n", solve(v, 0));
	}
}