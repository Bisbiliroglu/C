#include "stdio.h"
/*

girilen 32 bitlik sayýyý bytelarýna ayýrýr

*/

int main (void)
{
	
	unsigned int a = 0xAABBCCDD;
	unsigned int * b = NULL;
	unsigned char *b2 = NULL;
	unsigned char b3[4];
	int c = 0xff;
	printf("%X\n\n",a);
	b = &a;
	b2 = (unsigned char*)&a;

	printf("bit shifting yöntemi ile \n");
	
	for(int i = 0; i<sizeof(int); i++)
	{
		printf("%X\n", (0xff) & ((a >> (8*i)))) ;		
	}	
	
	printf("\n");
	printf("pointer yöntemi ile \n");

	for(int i = 0; i<sizeof(int); i++)
	{
	//	b3[i] = *(b2 + i);
		printf("%X\n", *(b2 + i)) ;		
	}	
	

	return 0;	
}
