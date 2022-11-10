// https://www.thehuxley.com/problem/1240

#include <stdio.h>

int main() {
	int flag = 1, i = 0, tam = 0;
    char string[101];
    
	scanf("%100[^\n]", string);
		
	while(string[tam] != '\0')
		tam++;

	while(flag && i < tam)
		if(string[i++] != string[--tam])
			flag = 0;

	flag ? printf("S") : printf("N");

	return 0;
}
