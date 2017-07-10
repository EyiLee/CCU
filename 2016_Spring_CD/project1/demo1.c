#include<stdio.h>

int main(int argc, char **argv) {

	/* comment */
	// comment
	int testint;
	char testchar;
	float testfloat;
	double testdouble;
	void *testvoid;

	int i = 0;
	scanf("%d", &i);

	for(i = 0; i < 10; i++) {
		i += 1;
		i -= 1;
		i *= 1;
		i /= 1;
		i %= 1;
		printf("Hello World!\n");
	}

	i = 10;
	while(i--) {
		if(i > 5) {
			continue;
		}
		else if(i > 3) {
			testvoid = NULL;
		}
		else {
			break;
		}
	}

	return 0;
}
