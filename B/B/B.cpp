#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

#define NMAX 64

int A[NMAX][NMAX];

int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int N,M;

void df( int c, int l )
{
	
	int nc,nl;
	for( int i = 0; i < 8; ++i )
	{
		nc = c + dx[i];
		nl = l + dy[i];

		//printf("%d %d %d %d\n",c,l,nc,nl);

		if( nc < 1 || nc > N || nl < 1 || nl > M )
			continue;

		if( A[nc][nl] )
		{
			
			A[nc][nl] = 0;
			df( nc,nl );
			
		}
	}
}


int main()
{

	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);

	int i,j;
	
	while( cin >> M >> N )
	{
		if( !N && !M )
			return 0;

		memset( A, 0, sizeof(A) );
		
		for( i = 1; i <= N; ++i )
			for( j = 1; j <= M; ++j )
				scanf("%d",&A[i][j]);

		int ans = 0;
		for( i = 1; i <= N; ++i )
			for( j = 1; j <= M; ++j )
				if( A[i][j] )
				{
					++ans;
					A[i][j] = 0;
					df( i,j );
					
				}

		printf("%d\n",ans);
	}

	return 0;
}