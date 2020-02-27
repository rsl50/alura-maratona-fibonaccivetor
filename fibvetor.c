#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char buf[10009];
int cnt[70];
bool ja_calculou[70];
int F[70];


int calc_fibonacci (int n) {
	
	if (ja_calculou[n]) {
		return F[n];		
	} 
	
	cnt[n]++;
	ja_calculou[n] = true;		
	
	if (n == 0) {
		F[n] = 0;
	}
	else if (n == 1) {
	   	F[n] = 1;
	}
	else {
	   	F[n] = (calc_fibonacci(n - 1) + calc_fibonacci(n - 2));
	}
	
	return F[n];
}


int main () {
	
	FILE * fp;
	fp = freopen("input1.txt", "r", stdin);
	
	if (fp != NULL)	{
		fgets(buf, 10009, fp);
		int test_cases = strtol(buf, NULL, 10);
		
		while (test_cases--) {
			fgets(buf, 10009, fp);
			int val = strtol(buf, NULL, 10);
			
			int result = calc_fibonacci(val);
			printf("Fib(%d) = %d\n", val, result);
			
			int i = 0;
			for (i = 0; i <= val; i++) {
            	printf("Calculei o fibonacci(%d) %d vezes!\n", i, cnt[i]);
        	}
		}
	}
	
	return (0);
}
