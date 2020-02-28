#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
* https://cursos.alura.com.br/course/maratona-de-programacao/task/48371
*
* Na maioria dos problemas de programação dinâmica acontecerá de encontrarmos uma recursão que funciona, 
* mas é muito lenta, e então tentaremos aplicar uma técnica de otimização de código para torná-lo mais rápido.
*
* Sendo assim, fizemos com que o computador memorizasse alguns casos para que fossem respondidos de imediato, 
* sem a necessidade de fazer outra recursão. O nome dessa técnica usada na programação dinâmica, bastante específico, será memoização.
* 
* Esse será um passo importante, salvar alguns itens já calculados num vetor ou matriz, para conseguir retorná-los rapidamente, evitando recalculá-los.
*/

char buf[10009];
bool ja_calculou[70];
unsigned long long F[70];

unsigned long long calc_fibonacci (int n) {
	if (ja_calculou[n]) {
		return F[n];
	}

	ja_calculou[n] = true;
	
	if (n == 0) {
		F[n] = 0;
	}
	else if (n == 1) {
		F[n] = 1;
	} else {
		F[n] = (calc_fibonacci(n-1) + calc_fibonacci(n-2));
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
			int n = strtol(buf, NULL, 10);
			
			printf("Fib(%d) = %llu\n", n, calc_fibonacci(n));
		}
	}
	
	return (0);
}
