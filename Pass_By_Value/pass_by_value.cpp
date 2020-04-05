#include <stdio.h>

void function (int a, int b[])
{
	a = 100;
	b[0] = 500;
}



 int main(void)
 {
 	printf("Pass by Value\n");
 	int x = 0;
 	int y[5] = {0,0,0,0,0};
 	printf("Before x: %d y[0]: %d\n",x,y[0]);
 	function(x,y);
 	printf("After x: %d y[0]: %d\n",x,y[0]);
 	printf("\nFonksiyona parametre olarak girilen Array fonksiyon icinde degistildiginde\nfonksiyon sonrasi bu degisikligi korurken,\nayni islemde degisken bu degisikligi koruyamiyor\n");
	return 0;
 }
