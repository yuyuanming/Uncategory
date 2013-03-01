#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef int F;
typedef double C;
#define F_INF (1<<29)
#define C_INF 1.0E+9
#define MAXV 900
#define MAXE 400000 // E*2!

int V,E;
F cap[MAXE];
C cost[MAXE],dist[MAXV],pot[MAXV];
int to[MAXE],prev[MAXE],last[MAXV],path[MAXV];
bool used[MAXV];
priority_queue <pair <C, int> > q;

class MinCostFlow{
    public:

    MinCostFlow(int n){
        int i;
        V = n; E = 0;
        REP(i,V) last[i] = -1;
    }

    void add_edge(int x, int y, F w, C c){
        cap[E] = w; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
    }

    pair <F, C> search(int s, int t){
        F ansf=0; C ansc=0;
        int i;

        REP(i,V) used[i] = false;
        REP(i,V) dist[i] = C_INF;
    
        dist[s] = 0; path[s] = -1; q.push(make_pair(0,s));
        while(!q.empty()){
            int x = q.top().second; q.pop();
            if(used[x]) continue; used[x] = true;
            for(int e=last[x];e>=0;e=prev[e]) if(cap[e] > 0){
                C tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if(tmp < dist[to[e]] && !used[to[e]]){
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    q.push(make_pair(-dist[to[e]],to[e]));
                }
            }
        }

        REP(i,V) pot[i] += dist[i];

        if(used[t]){
            ansf = F_INF;
            for(int e=path[t];e>=0;e=path[to[e^1]]) ansf = min(ansf,cap[e]);
            for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf;}
        }

        return make_pair(ansf,ansc);
    }

    pair <F, C> mincostflow(int s, int t){
        F ansf=0; C ansc=0;
        int i;
        while(1){
            pair <F, C> p = search(s,t);
            if(!used[t]) break;
            ansf += p.first; ansc += p.second;
        }
        return make_pair(ansf,ansc);
    }
};

int x[410],y[410];

int main(void){
    int N,i,j;
    
    cin >> N;
    REP(i,N) cin >> x[i] >> y[i];
/*  N = 400;
    srand(2743);
    REP(i,N){
        x[i] = rand() % 1000;
        y[i] = rand() % 1000;
    }
*/  
    int ymax = -10000, cnt = 0, root = -1;
    REP(i,N) ymax = max(ymax, y[i]);
    REP(i,N) if(y[i] == ymax) cnt++;
    if(cnt != 1){
        cout << -1 << endl;
        return 0;
    }
    REP(i,N) if(y[i] == ymax) root = i;
    
    MinCostFlow mcf(2*N+2);
    REP(i,N) if(i != root) mcf.add_edge(2*N, i, 1, 0);
    REP(i,N) mcf.add_edge(N+i, 2*N+1, 2, 0);
    REP(i,N) REP(j,N) if(y[i] < y[j]){
        int dx = x[i] - x[j], dy = y[i] - y[j], d = dx * dx + dy * dy;
        mcf.add_edge(i, N+j, 1, sqrt((double)d));
    }
    
    pair <int, double> ans = mcf.mincostflow(2*N, 2*N+1);
    if(ans.first != N-1){
        cout << -1 << endl;
    } else {
        printf("%.9f\n", ans.second);
    }
    
    return 0;
}

