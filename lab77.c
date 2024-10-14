#include <stdio.h>
#include <string.h>
#define SIZE 6
int main ()
{
	int answer;
	int slot;
	int appts=0;
	int i, j;
	char name [20];
	char schedule [6][20];
	char letter;
	for (i=0; i<6;i++)
	schedule [i][0]= '\0';
	while (1) {
		printf("\n type 1 to schedule an appt, type 2 to cancel an appt, type 3 to show schedule, type 4 to show names, or type 9 to quit.\n");
		scanf("%d", &answer);
			if (answer==1)
				{
				if (appts==6)
					printf("All appts are full.");
				else
						
							{
							printf("Enter your name.");
							scanf("%s", &name);
							for (i=0;i<SIZE;i++)
								{
								if (schedule[i][0] == '\0')
									{
									strcpy(schedule[appts], name);
									appts++;
									printf("Appt scheduled \n");
									break;
									}
		
								}
							}
				}
			else if (answer==2)
				{
				if (appts==0)
					printf("There is nothing to cancel.");
				else
					{ 
					printf("enter your name to cancel appt \n");
					scanf("%s", &name);
					for (i=0; i < appts; i++)
						{
							if (strcmp(schedule[i], name) == 0)
								schedule [i][0] = '\0';
								
								for (j=i+1; j<SIZE; j++)
									{
									if (schedule[i]!='\0')
										{
										strcpy(schedule[j-1], schedule[j]);
										schedule[j][0]='\0';
										appts--;
										}
									}
						}
					}
				}
			else if (answer==3)
				{
				
					for (i=0; i<SIZE; i++)
					{
						if (schedule[i][0] == '\0')
					        {
							printf("%d pm is available \n", i+1);
						}
						 else
						{
							printf("%d pm is booked by %s\n", i+1, schedule[i]);
						}
					}
				}
			
			else if (answer==4)
				{
				printf("Enter the first letter of your name.");
				scanf("%c", &letter);
					for (i=0; i<SIZE; i++)
						{
						if (letter == schedule[i][0])
							printf("%s \n", schedule[i]);
						}
				}
			else if (answer==9)
				return 0;
			else 
				printf("bad option.");
	}
}
