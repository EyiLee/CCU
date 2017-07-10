#include<stdio.h>
int main() {
	enum {one = 2,two,three} x;
	enum {four = 3,five} y;
	x = y;
	printf("%d %d %d %d",one,two,x,y);
}
