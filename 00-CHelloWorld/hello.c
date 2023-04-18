#include <stdio.h>

int main()
{
    fprintf(stdout,"Hola mundo\n"); 

	FILE *fp=fopen("output.txt","w");

    fprintf(fp,"Hola mundo\n");

    fclose(fp);
	return 0;
}
 