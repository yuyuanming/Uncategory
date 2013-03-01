/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
Beautiful strings

When John was a little kid he didn't have much to do. There was no internet, no Facebook, and no programs to hack on. So he did the only thing he could... he evaluated the beauty of strings in a quest to discover the most beautiful string in the world.

Given a string s, little Johnny defined the beauty of the string as the sum of the beauty of the letters in it.

The beauty of each letter is an integer between 1 and 26, inclusive, and no two letters have the same beauty. Johnny doesn't care about whether letters are uppercase or lowercase, so that doesn't affect the beauty of a letter. (Uppercase 'F' is exactly as beautiful as lowercase 'f', for example.)

You're a student writing a report on the youth of this famous hacker. You found the string that Johnny considered most beautiful. What is the maximum possible beauty of this string?

Input
The input file consists of a single integer m followed by m lines.
Output
Your output should consist of, for each test case, a line containing the string "Case #x: y" where x is the case number (with 1 being the first case in the input file, 2 being the second, etc.) and y is the maximum beauty for that test case.
Constraints
5 ¡Ü m ¡Ü 50
2 ¡Ü length of s ¡Ü 500
Example inputExample output
5
ABbCcc
Good luck in the Facebook Hacker Cup this year!
Ignore punctuation, please :)
Sometimes test cases are hard to make up.
So I just go consult Professor Dalves
Case #1: 152
Case #2: 754
Case #3: 491
Case #4: 729
Case #5: 646

 *
 *        Version:  1.0
 *        Created:  2013/1/26 13:08:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yuanming Yu (yyming[dot]gmail.com)
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int m;
char line[600];
int cnt[30];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &m);
	gets(line);
	for (int i=0; i<m; ++i) {
		gets(line);
		//printf("%s\n", line);

		memset(cnt, 0, sizeof(cnt));
		for (int k=0, len=strlen(line); k < len; ++k) {
			char ch = line[k];
			if (('a' <= ch) && (ch <= 'z')) ++cnt[ch - 'a'];
			if (('A' <= ch) && (ch <= 'Z')) ++cnt[ch - 'A'];
		}

		int sum = 0;
		sort(cnt, cnt+26);
		for (int k=26; k>0; --k) sum += k * cnt[k-1];
		printf("Case #%d: %d\n", i+1, sum);
	}
	return 0;
}
