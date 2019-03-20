
#include <stdio.h>
#include <conio.h> 
#include <time.h>
#include <stdlib.h>

int last_random_number = -1;

bool controlDigits(int value1, int value2,int value3,int value4)
{
	int values[4]= {value1,value2,value3,value4};
	int digits[8];
	int digitsctr = 0;
	for(int i = 0; i<4;i++)
	{
		while (values[i] > 0) {
		 int digit = values[i] % 10;
		 digits[digitsctr] = digit;
		 values[i] /= 10;
		 digitsctr++;
		}
	}
//	for(int i = 0; i< 8; i++)
//	printf("digits: %d\n",digits[i]);
	for(int i = 0; i< 8; i++)
		for(int j = 0; j<8; j++)
			if(i != j)
				if(digits[i] == digits[j])
					return false;
	return true;
}

int getRandomInt(int max_values)
{
	int r = rand();     
	int random = r%max_values;
	if(random != last_random_number)
	{
		last_random_number = random;
		return last_random_number;
	}else{
		return getRandomInt(max_values);
	}
}

 int main(void)
 {
 	clock_t begin = clock();
 	int values[8] = {1,2,3,4,5,6,7,8};
 	int numbers[56];
 	int numbers_ctr = 0;
 	int try_ctr = 0;
 	bool while_breaker = false;
 	
 	srand(time(NULL));   

 	for(int i = 0; i<8 ;i++)
 		for(int j = 0; j<8;j++)
 		{
 			if(i != j)
 			{
 				//printf("i: %d , j: %d, value1: %d, value2:%d\n",i,j,values[i],values[j] );
 				numbers[numbers_ctr] = values[i]*10 + values[j];
 				numbers_ctr++;
 				//printf("number: %d, number_ctr %d\n",numbers[numbers_ctr - 1],numbers_ctr );
 			}
		}
		
	while(true)
	{
		
		int random_numbers[4];
		
		random_numbers[0] = getRandomInt(56);
		random_numbers[1] = getRandomInt(56);
		random_numbers[2] = getRandomInt(56);
		random_numbers[3] = getRandomInt(56);
		printf("try: %d number 1: %d number 2: %d number 3:%d number 4:%d \n",try_ctr,numbers[random_numbers[0]],numbers[random_numbers[1]],numbers[random_numbers[2]],numbers[random_numbers[3]]);	
			if(controlDigits(numbers[random_numbers[0]],numbers[random_numbers[1]],numbers[random_numbers[2]],numbers[random_numbers[3]]))
			{
				try_ctr++;		
				printf("try: %d number 1: %d number 2: %d number 3:%d number 4:%d \n",try_ctr,numbers[random_numbers[0]],numbers[random_numbers[1]],numbers[random_numbers[2]],numbers[random_numbers[3]]);
		
				for(int i = 0; i<4; i++){
					if(numbers[random_numbers[0]]*numbers[random_numbers[1]] == numbers[random_numbers[2]]*numbers[random_numbers[3]] )
					{
						printf("%d*%d = %d*%d = %d \n",numbers[random_numbers[0]],numbers[random_numbers[1]],numbers[random_numbers[2]],numbers[random_numbers[3]] , numbers[random_numbers[0]]*numbers[random_numbers[1]] );	
						while_breaker = true;
						break;
					}
					if(numbers[random_numbers[0]]*numbers[random_numbers[2]] ==numbers[random_numbers[1]]*numbers[random_numbers[3]] )
					{
						printf("%d*%d = %d*%d = %d\n",numbers[random_numbers[0]],numbers[random_numbers[2]],numbers[random_numbers[1]],numbers[random_numbers[3]], numbers[random_numbers[0]]*numbers[random_numbers[2]] );	
						while_breaker = true;
						break;
					}
				}
				if(while_breaker)
				{
					break;	
				}	
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	
 	
 	printf("\n\n %lf Sec________________________________________________________________\nPress any key to exit\n", time_spent);
	getch();
	return 0;
 }
