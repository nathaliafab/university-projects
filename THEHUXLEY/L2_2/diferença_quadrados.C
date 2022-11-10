// https://www.thehuxley.com/problem/1006

#include <stdio.h>
#include <math.h>

int main()
{
	int x, menorQ, maiorQ;

	scanf("%d", &x);

    while(x != 0){
		menorQ = pow(x/2, 2);
		maiorQ = pow((x/2)+1, 2);

		printf("%d - %d\n", maiorQ, menorQ);

		scanf("%d", &x);
	}
		
  return 0;
}
