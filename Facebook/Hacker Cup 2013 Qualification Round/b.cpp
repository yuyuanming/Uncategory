/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description: Balanced Smileys
Your friend John uses a lot of emoticons when you talk to him on Messenger. In addition to being a person who likes to express himself through emoticons, he hates unbalanced parenthesis so much that it makes him go :(

Sometimes he puts emoticons within parentheses, and you find it hard to tell if a parenthesis really is a parenthesis or part of an emoticon.

A message has balanced parentheses if it consists of one of the following:

- An empty string ""
- One or more of the following characters: 'a' to 'z', ' ' (a space) or ':' (a colon)
- An open parenthesis '(', followed by a message with balanced parentheses, followed by a close parenthesis ')'.
- A message with balanced parentheses followed by another message with balanced parentheses.
- A smiley face ":)" or a frowny face ":("
Write a program that determines if there is a way to interpret his message while leaving the parentheses balanced.

Input
The first line of the input contains a number T (1 ¡Ü T ¡Ü 50), the number of test cases. 
The following T lines each contain a message of length s that you got from John.

Output
For each of the test cases numbered in order from 1 to T, output "Case #i: " followed by a string stating whether or not it is possible that the message had balanced parentheses. If it is, the string should be "YES", else it should be "NO" (all quotes for clarity only)

Constraints
1 ¡Ü length of s ¡Ü 100
 

Example input 
5
:((
i am sick today (:()
(:)
hacker cup: started :):)
)(

Example output
Case #1: NO
Case #2: YES
Case #3: YES
Case #4: YES
Case #5: NO

 *
 *        Version:  1.0
 *        Created:  2013/1/26 13:30:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yuanming Yu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
char line[200];
int dp[110][110];

int solve(int i, int j) {
	if (i > j) return 0; //empty

	// single character a-z, ' ', :
	if (i == j) {
		if (('a' <= line[i]) && (line[i] <= 'z')) return 1;
		if (line[i] == ' ') return 1;
		if (line[i] == ':') return 1;
		return 0;
	}

	// :( and :)
	if ((i+1 == j) && (line[i] == ':')) {
		if ((line[j] == '(') || (line[j] == ')')) return 1;
	}


	int& ret = dp[i][j];
	if (ret >= 0) return ret;

	if ((line[i] == '(') && (line[j] == ')')) ret = max(ret, solve(i+1, j-1));

	for (int k=i; k<j; ++k) ret = max(ret, solve(i, k) * solve(k+1, j));

	return ret;
}

int main() {
/*
	scanf("%s", line);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, strlen(line)-1));

	return 0;
*/
	//freopen("b.in", "r", stdin);
	scanf("%d", &T);
	gets(line);
	for (int t=0; t<T; ++t) {
		memset(dp, -1, sizeof(dp));
		gets(line);
		//printf("%d\n", strlen(line));

		int ret = solve(0, strlen(line) - 1);
		printf("Case #%d: %s\n", t+1, (ret == 0 ? "NO" : "YES"));
	}
	return 0;
}
