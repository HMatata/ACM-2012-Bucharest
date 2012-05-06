#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
int main()
{
	freopen("i.in","r",stdin);
	freopen("i.out","w",stdout);
	int test;
	scanf("%d", &test);
	while (test --)
	{
		int n;
		scanf("%d", &n);
		vector < pair < int, int > > v(n);
		map < pair < int , int > , pair < int, int > > m[2];
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &v[i].first, &v[i].second);
		sort(v.begin(), v.end());
		int ans = 0;
		int prev = v[0].first;
		int cnt = 0;
		int good = 1;
		for (int i = 0; i < n; ++ i)
		{
			if (prev == v[i].first)
			{
				++cnt;
				if (cnt%2 == 0)
				{
					ans+=v[i].second -v[i-1].second;
					m[0][v[i]] = v[i-1];
					m[0][v[i-1]] = v[i];
				}
			}
			else
			{
				if (cnt%2!=0)
				{
					good = 0;
					break;
				}
				cnt = 1;
				prev = v[i].first;
			
			}
		}
		
		for (int i = 0; i < n; ++ i)
			v[i] = make_pair(v[i].second, v[i].first);
		
		sort(v.begin(), v.end());

		prev = v[0].first;
		cnt = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (prev == v[i].first)
			{
				++cnt;
				if (cnt%2 == 0)
				{
					ans+=v[i].second -v[i-1].second;
					m[1][v[i]] = v[i-1];
					m[1][v[i-1]] = v[i];
				}
			}
			else
			{
				if (cnt%2!=0)
				{
					good = 0;
					break;
				}
				cnt = 1;
				prev = v[i].first;
			
			}
		}
		if (!good)
		{
			printf("-1\n");
			continue;
		}
		int ans2 = 0;
		int ix, iy;
		pair < int, int > d;
		d.first = ix =  v[0].second;
		d.second = iy = v[0].first;
		int cd = 1;
		do{
			cd = 1-cd;

			ans2+=abs(d[cd] - m[cd][d[cd]]);
			d[cd] = m[cd][d[cd]];
		}while (d.first != ix && d.second!=iy);
		if (ans2 != ans)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}