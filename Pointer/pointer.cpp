#include <stdio.h>
#include <conio.h> 

 int main(void)
 {
 	int a = 5;
 	int *b = &a;


 	printf("\n int a = 5;\n int *b = &a;\n\n\n");
 	printf(" a\t = %d\n &a\t = %d\n b\t = %d\n &b\t = %d\n *b\t = %d",a,&a,b,&b,*b);
 	printf("\n\n a  + 7\t = %d\n b  + 7\t = %d\n *b + 7\t = %d\n",a+7, b+7, *b+7);
 	
 	printf("\n\n\n * isareti pointeri tanımlamak icin kullanilir.");
 	printf("\n & isareti adresi dondurur. &a degeri a degiskeninin degerini tutuldugu adresi verir.");
 	printf("\n Pointerlar icerisinde adres tutar. Bu adres degeri gosteren adrestir.");
 	printf("\n\n\n Yapilan ornekte:\n a degiskeninin degeri\t: a = %d	\ta degiskeninin adresi\t: &a = %d\n b degiskeninin icerigi\t: b = %d \tb degiskeninin adresi\t: &b = %d\n b degiskeninin gosterdigi yer\t: *b = %d",a,&a,b,&b,*b);

 	printf("\n\nGoruldugu gibi a degiskeninin adresi b degiskeninin icerigi ile aynidir.\niki degiskeninin adresi farklidir ve b degiskeninin pointeri a degiskeninin icerigine esittir.");

 	
 	
 	printf("\n\n________________________________________________________________\nPress any key to exit\n");
	getch();
	return 0;
 }
