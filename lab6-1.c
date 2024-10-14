#define SIZE 6
#include <stdio.h>
int main()
{
	int answer;
	int slot;
	int apt = 0;
	int schedule[SIZE] = {0, 0, 0, 0 ,0, 0};
	int i;
	while (1) {
		printf("\n Input 1 to schedule an appointment, 2 to cancel, and 3 to show schedule, and 9 to quit\n");

		scanf("%d", &answer);
			if (answer == 1)
				{
				if (apt == 6)
					printf ("All appts are full");
				else
					for (i=0; i<SIZE; i++)
						{
						if (schedule[i]==0)
							{
							printf( "Your appt is at %d pm", i+1);
							apt++;
							schedule[i]= i+1;
							break;

							}		

						}
				}
			else if (answer == 2)
				{
				if (apt == 0)
					printf("There is nothing to cancel");
				else	
					{
					printf("Enter the slot you want to cancel \n");

					scanf("%d",&slot);
					
						if (schedule[slot-1]==0)
							printf("Time slot not reserved so it cannot be cancelled");

						else 
							schedule[slot-1]=0;
							apt--;
					}
				}
				else if (answer == 3)
					{
					for (i=0; i<SIZE; i++)
						{
						if (schedule[i]>0)
							printf("%d pm - booked\n", i+1);
						else 
							printf("%d pm -available\n",i+1);
						}
					}
			
		else if (answer==9)

			return (0);
		else 
			printf("bad option");				
		}						
		
}
	
	
