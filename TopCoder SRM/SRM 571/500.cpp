#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

#define REP(i, n) for (int i(0), _n(n); i!=_n; ++i)
#define CL(v, x) memset(v, x, sizeof(v))
#define SZ(v) (int)(v).size()

class MagicMolecule {
public:
	int edges;
	int A[1300], B[1300];
	vector<int> power;
	int N, m, maxSum;
	bool used[60];
	
	// change it into vertex cover
	void solve(int p, int k) {
		if (p == edges) {
			int sum = 0;
			REP(i, N) if (used[i]) sum += power[i];
			maxSum = max(maxSum, sum);
			return;
		}
		int u = A[p], v = B[p];
		if (!used[u] || !used[v]) 
			solve(p+1, k);
		else if (k > 0) {
			used[u] = 0;
			solve(p+1, k-1);
			used[u] = 1;
			
			used[v] = 0;
			solve(p+1, k-1);
			used[v] = 1;
		}
	}
	
	int maxMagicPower(vector <int> MP, vector <string> MB) {
		power = MP;
		N = SZ(MP); edges = 0;
		REP(i, N) for (int j=i+1; j<N; ++j) 
		if (MB[i][j] == 'N') {
			A[edges] = i;
			B[edges] = j;
			++edges;
		}
		m = 0;
		while (3*m<2*N) ++m;
		
		maxSum = -1; 
		CL(used, 1);
		solve(0, N-m);
		return maxSum;
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
