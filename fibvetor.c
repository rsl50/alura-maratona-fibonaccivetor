#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
* https://cursos.alura.com.br/course/maratona-de-programacao/task/48371
*
* Na maioria dos problemas de programa��o din�mica acontecer� de encontrarmos uma recurs�o que funciona, 
* mas � muito lenta, e ent�o tentaremos aplicar uma t�cnica de otimiza��o de c�digo para torn�-lo mais r�pido.
*
* Sendo assim, fizemos com que o computador memorizasse alguns casos para que fossem respondidos de imediato, 
* sem a necessidade de fazer outra recurs�o. O nome dessa t�cnica usada na programa��o din�mica, bastante espec�fico, ser� memoiza��o.
* 
* Esse ser� um passo importante, salvar alguns itens j� calculados num vetor ou matriz, para conseguir retorn�-los rapidamente, evitando recalcul�-los.
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
