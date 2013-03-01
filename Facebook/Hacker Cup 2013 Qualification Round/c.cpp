/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  Find the Min
		 URL:http://www.facebook.com/hackercup/problems.php?pid=494433657264959&round=185564241586420
 *
 *        Version:  1.0
 *        Created:  2013/1/26 14:03:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yuanming Yu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
int m[210000];
int T, a, b, c, r, n, k;
set<int> Q;
map<int, int> tab;

void valid_Q() {
	for (;;) {
		int val = *Q.begin();
		if (tab[val] > 0) {
			Q.erase(Q.begin());
		}
		else return;
	}
}

int main() {
	//freopen("c.in", "r", stdin);

	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		scanf("%d%d", &n, &k);
		scanf("%d%d%d%d", &a, &b, &c, &r);

		tab.clear();
		Q.clear();
		for (int i=0; i<=k; ++i) Q.insert(i);

		m[0] = a;
		tab[a]++;
		for (int i=1; i<k; ++i) {
			m[i] = (ll(b) * m[i-1] + c) % r;
			tab[m[i]]++;
		}

		valid_Q();
		m[k] = *Q.begin();
		Q.erase(Q.begin());
		for (int i=k+1; i<=k*2; ++i) {
			int val = m[i - k - 1];
			tab[val]--;
			if (tab[val] == 0) {
				Q.insert(val);
			}

			valid_Q();
			m[i] = *Q.begin();
			Q.erase(Q.begin());
			tab[m[i]]++;
		}

		int ret = m[k + ((n - 1 - k) % (k + 1))];
		printf("Case #%d: %d\n", t+1, ret);
	}
}
