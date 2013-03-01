/*
 * =====================================================================================
 *
 *       Filename:  1301.cpp
 *
 *    Description:  sub prob 3
 *
 *        Version:  1.0
 *        Created:  2013/1/27 15:18:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

int f[100];
int n;

int main() {
	f[1] = -1;
	f[2] = -1;
	f[3] = 1;
	scanf("%d", &n);

	for (int i=4; i<=n; ++i) if (i % 2 == 0){
		f[i] = -1;
		for (int k=1; k+k+k-1<i; ++k) 
			if (f[i-k] == -1) {
				f[i] = 1;
				break;
			}
	}
	else {
		f[i] = 1;
	}
	for (int i=1; i<=n; ++i) {
		printf("%d %d\n", i, f[i]);
	}
	return 0;
}
