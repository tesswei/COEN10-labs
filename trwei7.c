#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main ()
{
	int rand1;
	int rand2;
	int counter = 0;
	int i;
	int result;
	int percent;
	srand((int)time(NULL));
	int input;
	for (i=0; i < 10; i ++)
	{
		rand1 = rand()%13;
     		rand2 = rand()%13;
		printf("%d * %d \n", rand1 , rand2);	
		scanf("%d" , &input); 
		result= rand1 * rand2;
	
	if (input==result)
	{
		printf("yay\n");
		counter++;
	}
	else 
	{
		printf("Wrong, the correct answer is %d\n",result);
	}
	}
	printf("The percent you got correct was %d %%\n ", counter*10);
	

}
