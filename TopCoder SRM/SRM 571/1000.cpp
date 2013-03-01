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
using namespace std;

#define CL(A, x) memset((A), (x), sizeof(A))
#define FOR(i, n) for (typeof(n) i=0, _n=(n); i!=_n; ++i)
#define SZ(A) ((A).size())
#define PB push_back

typedef long long ll;

class CandyOnDisk {
public:
	bool visited[60], used[60][60], valid[60];
	double low[60], high[60], dist[60][60];
	int n;
	
	bool insect(double l, double r, double p, double q) {
		if ((q < l) || (r < p)) return false;
		return true;
	}
	
	string ableToAchieve(vector <int> x, vector <int> y, vector <int> r, int sx, int sy, int tx, int ty) {			
		if ((sx==tx) && (sy==ty)) return "YES";		
	
		// remove circle with same center but smaller
		n = SZ(x); 
		FOR(i, n) {
			valid[i] = true;
			FOR(j, i) if ((x[i]==x[j])&&(y[i]==y[j])){
				if (r[i] < r[j]) valid[i] = false;
				else valid[j] = false;
			}
		}
		int m = 0;
		FOR(i, n) if (valid[i]) {
			x[m] = x[i], y[m] = y[i], r[m] = r[i];
			++m;
		}
		n = m;
										
		FOR(i, n) FOR(j, n) dist[i][j] = hypot(x[i]-x[j], y[i]-y[j]);
		FOR(i, n) {
			low[i] = 1e9;
			high[i] = -1e9;
		}
	
		// which circle could the point access to at initial
		CL(visited, 0);
		FOR(i, n) {
			double d = hypot(sx-x[i], sy-y[i]);
			if (d < r[i] + 1e-9) {
				visited[i] = true;
				low[i] = high[i] = d;
			} 
		}
		
		// bellman ford, repeatly update low[] and high[]
		CL(used, 0);
		bool update = true;
		while (update) {
			update = false;
			FOR(i, n) if (visited[i]) {
				FOR(j, n) if (j!=i) {
					double mx = max(0., dist[i][j]-r[j]);
					if (!used[i][j] && insect(low[i], high[i], mx, dist[i][j]+r[j]))
					{
						used[i][j] = used[j][i] = true;
						low[i] = min(low[i], mx);
						high[i] = max(high[i], min(double(r[i]), dist[i][j]+r[j]));
						
						low[j] = min(low[j], max(0., dist[i][j]-r[i]));
						high[j] = max(high[j], min(double(r[j]), dist[i][j]+r[i]));
						update = visited[j] = true;
					}
				}
			}
		}
		
		FOR(i, n) {
			double d = hypot(tx-x[i], ty-y[i]);
			if ((low[i]<d) && (d<high[i])) return "YES";
		}
		return "NO";
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
