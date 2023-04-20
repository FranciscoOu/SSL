#include <stdio.h>

int main()
{
	FILE *fp=fopen("output.txt","w");

    		fprintf(fp,"Hola mundo\n");

    	fclose(fp);
	return 0;
}
 
