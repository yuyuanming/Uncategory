/*
 * =====================================================================================
 *
 *       Filename:  expt4.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/3/12 9:53:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>

double p;
int B[2][2][2];
double bs[10];

void print();

double best_ept;
int best_B[2][2][2];

double calc_bs(int code) {
	double ret = 0;
	
	for (int x1=0; x1<2; ++x1)
	for (int x2=0; x2<2; ++x2)
	for (int x3=0; x3<2; ++x3) {
		double tmp = B[x1][x2][x3];
		if (code & 4) tmp *= (2*x1-1.0);
		if (code & 2) tmp *= (2*x2-1.0);
		if (code & 1) tmp *= (2*x3-1.0);

		ret += tmp;
	}

	return ret / 8;
}

void solve() {
	for (int code=0; code<8; ++code) {
		bs[code] = calc_bs(code);
	}

	double ept = 0;
	for (int x1=0; x1<2; ++x1)
	for (int x2=0; x2<2; ++x2)
	for (int x3=0; x3<2; ++x3) {

		double tmp = 0;
		for (int code=0; code<8; ++code){
			double pp = 1.0;
			double pi = 1.0;

			if (code & 4) {
				pp *= p;
				pi *= (2*x1-1.0);
			}
			if (code & 2) {
				pp *= p;
				pi *= (2*x2-1.0);
			}
			if (code & 1) {
				pp *= p;
				pi *= (2*x3-1.0);
			}

			tmp += bs[code] * pp * pi;
		}

		//ept += (tmp * tmp * tmp * tmp / 6.0  + tmp * tmp) / 8.0;
		ept += (tmp * tmp * tmp * tmp) / 8.0;

	}

	if (ept > best_ept) {
		best_ept = ept;

		for (int x1=0; x1<2; ++x1)
		for (int x2=0; x2<2; ++x2)
		for (int x3=0; x3<2; ++x3) 
			best_B[x1][x2][x3] = B[x1][x2][x3];

		//print();
	}
}

void go(int code, int tot) {
	int x3 = code & 1, x2 = (code / 2) & 1, x1 = (code / 4) & 1;

	if (code == 8) {
		if (tot != 4) return;
		solve();
		return;
	}

	B[x1][x2][x3] = 1;
	go(code+1, tot+1);
	B[x1][x2][x3] = -1;
	go(code+1, tot);
}

void print() {
	printf("Expetation: %.6lf\n", best_ept);
	for (int x1=0; x1<2; ++x1)
	for (int x2=0; x2<2; ++x2)
	for (int x3=0; x3<2; ++x3) {
		printf("(%d %d %d) -> %d\n", (2*x1-1), (2*x2-1), (2*x3-1), best_B[x1][x2][x3]);
	}
}

int main() {
	//  test code
	/*
	B[0][0][0] = -1;
	B[0][0][1] = 1;
	B[0][1][0] = -1;
	B[0][1][1] = -1;
	B[1][0][0] = 1;
	B[1][0][1] = 1;
	B[1][1][0] = 1;
	B[1][1][1] = 1;

	printf("%.6lf\n", calc_bs(6));
	return 0;
	*/
	
	B[0][0][0] = 1;
	B[0][0][1] = 1;
	B[0][1][0] = 1;
	B[0][1][1] = -1;
	B[1][0][0] = 1;
	B[1][0][1] = -1;
	B[1][1][0] = -1;
	B[1][1][1] = -1;

	p = 0.1;

	solve();
	print();

	return 0;
	

	printf("Input p = ");
	scanf("%lf", &p);
	best_ept = -1;
	go(0, 0);
	print();
	return 0;
}
