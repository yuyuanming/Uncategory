#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
using namespace std;

#define CL(A, x) memset((A), (x), sizeof(A))
#define FOR(i, n) for (typeof(n) i=0, _n=(n); i!=_n; ++i)
#define SZ(A) ((A).size())
#define PB push_back

typedef long long ll;
const int MaxNode = 30000000;
int node;

class MagicMolecule {
public:
	ll G[100];
	int val[100];
	int maxSum, n, M;
	
	void solve(ll code, int from, int has, int sum) {
		// cut the time roughly to 1.5sec CPU time
		if (++node > MaxNode) return;
		if ( has >= M ) {
			maxSum = max(maxSum, sum);
		}
		
		// count the number of 1 bit in long long var code
		int m = __builtin_popcountll(code);
		if ( has+m < M ) return;
		
		int nextsum = 0;
		for (int i=from; i<n; ++i) if (code & (1LL<<i)) 
			nextsum += val[i];
		if (nextsum + sum <= maxSum) return;
		
		ll pass = 0;
		for (int i=from; i<n; ++i) if (code & (1LL<<i)) {
			// bits will not choose anymore
			pass |= 1LL<<i;
			solve( (code^pass)&G[i], i+1, has+1, sum+val[i] );
		}
	}
	
	int maxMagicPower(vector <int> MP, vector <string> MB) {	
		n = SZ(MP);		
		// consider those with larger value first
		for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j)
			if (MP[i] < MP[j]) {
				swap(MP[i], MP[j]);
				swap(MB[i], MB[j]);
				for (int k=0; k<n; ++k) {
					swap(MB[k][i], MB[k][j]);
				}
			}
		
		FOR(i, n) val[i] = MP[i];
		
		FOR(i, n) {
			ll code = 0;
			FOR(j, n) 
				if (MB[i][j] == 'Y') code |= 1LL << j;
			G[i] = code;
		}
		
		node = 0;
		maxSum = -1;
		// pre-calculate the m, for faster compare
		M = 0; while ( 3*M < 2*n ) ++M;
		FOR(i, n) solve(G[i], i+1, 1, val[i]);
		return maxSum;
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

