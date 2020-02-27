#include <stdio.h>
#include <stdlib.h>

char buf[10009];

int calc_fibonacci (int n) {	
	if (n == 0) {
        return 0;
    } else if (n == 1) {
         return 1;
    } else return (calc_fibonacci(n - 1) + calc_fibonacci(n - 2));	
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
		}
	}
	
	return (0);
}
