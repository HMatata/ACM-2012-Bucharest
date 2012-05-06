#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector < pair < int, int > > v(5010, pair < int ,int > (0, 0));
int dist (int a, int b , int c , int d, int m , int n)
{
	return a*d + c*n+ m*b-m*d-a*n-b*c > 0;
}
/*
class compare
{
private:
	vector < pair < int, int > > &v;
	int y1, y2;
public:
	compare( vector < pair < int, int > > &_v, int _x1, int _x2) : v(_v), y1(_x1),y2(_x2) {}
	bool operator() (const pair < int, int > &lhs, const pair < int, int > &rhs) const
	{
		return dist(lhs.first, y1, 
	}

}*/
int ans[5010];
int main()
{
	freopen("J.in","r",stdin);
	freopen("J.out","w",stdout);
	int first = 1;
	while (1)
	{
	
		int x1, x2, y1, y2, n, m;
		memset(ans, 0, sizeof(ans));
		scanf("%d %d %d %d %d %d\n", &n, &m , &x1, &y1, &x2, &y2);
		if (n == 0)
			return 0;
		if (!first)
			printf("\n");
		first = 0;
		v.resize(n+2);
		v[0].first = x1-1;
		v[0].second = x1-1;

		for (int i = 1; i <= n; ++ i)
			scanf("%d %d", &v[i].first, &v[i].second);
		v[n+1].first = x2+1;
		v[n+1].second = x2+1;
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			int a = 0;
			int b = n+1;
			while (a+1 <b)
			{
				int m = (a+b)/2;
				if (!dist(v[m].first,y1, v[m].second,y2, x, y))
					b = m;
				else
					a = m;
			}
			ans[a]++;

		}
		for (int i = 0; i <=n; ++i)
			printf("%d: %d\n", i, ans[i]);
		
	}
	return 0;
}