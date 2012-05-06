#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp( const pair< int,int >& lhs, const pair< int, int >&rhs ) 
{
	/*
	if( lhs.first == rhs.first )
		return lhs.second > rhs.second;
		
	return lhs.first < rhs.first;
	*/
	return lhs.first+lhs.second < rhs.first+rhs.second;
}

int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);

	int N,M;
	int i;

	while( cin >> N >> M )
	{
		vector < int > S;
		vector < pair < int, int > > A;

		int var;
		for( i = 1; i <= N; ++i )
		{
			scanf("%d",&var);
			S.push_back(var);
		}

		sort( S.begin(), S.end() );

		int v1,v2, start = 1000, end = -1;
		for( i = 1; i <= M; ++i )
		{
			scanf("%d %d\n",&v1,&v2);
			A.push_back( make_pair(v1,v2) );

			if ( start > v1 )
				start = v1;
			if( end < v1+v2 )
				end = v1+v2;
		}

		sort( A.begin(), A.end(), cmp );
		vector < bool > killed (A.size(), 0);
		int ans = 0;
		int time = start, poz_s = 0, poz_a = 0;
		end = A[A.size()-1].first+A[A.size()-1].second+1;
		while( time <= end )
		{
			/*
			poz_s = S.size()-1;
			while( poz_a < A.size() && A[ poz_a ].first == time && poz_s > 0 )
			{
				while( S[poz_s] > ( A[ poz_a ].second - A[ poz_a ].first ) && poz_s >= 0 ) --poz_s;
				if( poz_s < 0 ) break;

				if( ( A[ poz_a ].second - A[ poz_a ].first ) <= S[ poz_s ] ) ++ans, --poz_s, ++poz_a;
				else break;
			}

			while( poz_a < A.size() && A[ poz_a ].first == time ) ++poz_a;
			++time;
			*/
			for (int i = S.size()-1 ; i >=0; --i)
			{
				for (int j = 0; j < A.size(); ++j)
					if (!killed[j] && A[j].first <= time && S[i] <= A[j].second - (time - A[j].first))
					{
						killed[j] = true;
						++ans;
						break;
					}

			}
			++time;
		}

		printf("%d\n",ans);

	}


	return 0;
}