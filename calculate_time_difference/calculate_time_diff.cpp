#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int getDateFromRawText(char * source, int startIndex, int endIndex)
{
     char buffer[endIndex - startIndex];
	
	memset(buffer, 0, 4);

	for(int i = 0; i< endIndex - startIndex; i++ )
	{
		
		buffer[i] = source[startIndex + i];
	//		printf("buffer c %c \n",buffer[i] );

	}
//	printf("buffer %s \n",buffer);
	
	return atoi(buffer);
}

int main (void)
{
	char startTimeRaw[13]; 
	char endTimeRaw[13]; 	
	struct tm startTime, endTime;
	time_t startTime_t, endTime_t;
	
	while(1)
	{
	
		printf("yyyyaagg_ssdd cinsinden baslangic tarihini giriniz\n");
		scanf("%s",&startTimeRaw);
		printf("yyyyaagg_ssdd cinsinden bitis tarihini giriniz\n");
		scanf("%s",&endTimeRaw);
		printf("Baslangic tarihi: %s \nbitis tarihi: %s \n",startTimeRaw,endTimeRaw);
		
		//	printf("%d/%d/%d %d:%d",startTime.tm_mday,startTime.tm_mon,startTime.tm_year,startTime.tm_hour,startTime.tm_min  );
		
		startTime.tm_year = getDateFromRawText(startTimeRaw ,0,4) - 1900;
		startTime.tm_mon = getDateFromRawText(startTimeRaw, 4,6) - 1;
		startTime.tm_mday =  getDateFromRawText(startTimeRaw, 6,8);
		startTime.tm_hour =  getDateFromRawText(startTimeRaw, 9,11);
		startTime.tm_min =  getDateFromRawText(startTimeRaw, 11,13);
		
		endTime.tm_year = getDateFromRawText(endTimeRaw ,0,4) - 1900;
		endTime.tm_mon = getDateFromRawText(endTimeRaw, 4,6) - 1;
		endTime.tm_mday =  getDateFromRawText(endTimeRaw, 6,8);
		endTime.tm_hour =  getDateFromRawText(endTimeRaw, 9,11);
		endTime.tm_min =  getDateFromRawText(endTimeRaw, 11,13);
		
		
		startTime_t = mktime ( &startTime );
	  	endTime_t = mktime ( &endTime );
	  //	time_diff_in_seconds = difftime(endTime_t, startTime_t) / 1000;
	  	printf("Time diff %.f minutes \n\n", difftime(endTime_t, startTime_t)/60);
	
	}
	
	
	
	
	return 0;
}
