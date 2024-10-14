#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 6
void schedule1 (void);
void cancelbyname (void);
void cancelbytime (void);
void list (void);
void firstletter (void);
int priority (void);
int answer;
int slot;
int appts=0;
int canceltime;
int letter2;
int option2 (char);
char name [20];
char schedule [6][20];
char letter;
char phonenum[10];
char phone [6][20];
int main ()
{
int a;
int flag=0;
int i,j;
	for (i=0; i<6;i++)
	schedule [i][0]= '\0';
	while (1) {
		printf("\n type 1 to schedule an appt, type 2 to cancel an appt by name, type 3 to cancel by time, type 4 to show schedule,to search schedule by first letter type 5,type 6 for priority, type 7 to check how many times a letter occurs or type 9 to quit.\n");
		scanf("%d", &answer);
		fflush(stdin);
		switch (answer)
		{
		
		case 1:
			schedule1();
			break;
		case 2: 
			cancelbyname();
			break;
		case 3:
			cancelbytime();
			break;
		case 4:
			list();
			break;
		case 5:
			firstletter();
			break;
		case 6:
			if (flag==0)
				flag = priority();
			else 
				printf("You cannot choos epriority twice");
			break;
		case 7:
			printf ("What letter would you like to check");
                        scanf (" %c", &letter2);
			a = option2(letter2);
			printf ("This letter occurs %d times",a);
			break;
		case 9:
			return 0;
		default:
			printf("bad option\n");
			fflush(stdin);
			}
	}

}
void schedule1 (void)
{
int i;
				
				if (appts==6)
                                        printf("All appts are full.");
                                else

                                                        {
                                                        printf("Enter your name.");
                                                        scanf("%s", &name);
							fflush(stdin);
							for (i=0; i<SIZE; i++)
								if (strcmp (schedule[i], name)==0)
									{
									printf("Appt exist for this name");
									return;
									}
							printf("Enter your Phone number");
							scanf("%s",&phonenum);
							fflush(stdin);
                                                        for (i=0;i<SIZE;i++)
                                                                {
                                                                if (schedule[i][0] == '\0' && phone[i][0]=='\0')
                                                                        {
                                                                        strcpy(schedule[i], name);
                                                                        appts++;
									strcpy(phone[i],phonenum);
                                                                        printf("Appt scheduled \n");
                                                                        break;
                                                                        }

                                                                }

                             	                      }
				
}

void cancelbyname (void)
{
int i,j;				
                                if (appts==0)
                                        printf("There is nothing to cancel.\n");
                                else
                                        {
					printf("enter your name to cancel \n");
                                        scanf("%s", &name);
                                        for (i=0; i < appts; i++)
                                                {
                                                        if (strcmp(schedule[i], name) == 0)
							{
                                                                schedule [i][0] = '\0';
								appts--;
								phone[i][0] = '\0';
                                                                for (j=i+1; j<SIZE; j++)
                                                                        {
                                                                        if (schedule[j][0]!='\0' && phone[j][0]!='\0')
                                                                                {
                                                                                strcpy(schedule[j-1], schedule[j]);
                                                                                schedule[j][0]='\0';
										strcpy(phone[j-1], phone[j]);
										phone[j][0]='\0';
                                                                               // appts--;
										printf("The appt at %dpm has been moved to %dpm \n",j,j-1);
                                                                                }
								 }
							}
                                                }
                                        }
                                

}
void cancelbytime (void)

 {
int i,j;
                 		  
                                if (appts==0)
                                        printf("There is nothing to cancel.");
                                else
                                        {
                                        printf("enter the time you want to cancel \n");
                                        scanf("%d", &canceltime);
						canceltime--;
						if(schedule[canceltime]=='\0' && phone[canceltime]=='\0')
						{
							printf("no appt scheduled");
						
                                   		}
						else
                                               		 {
								schedule[canceltime][0]='\0';
								phone[canceltime][0]='\0';
								appts--;
                                                                for (j=canceltime+1; j<SIZE; j++)
                                                                        {
                                                                        if (schedule[j][0]!='\0' && phone[j][0]!='\0')
                                                                                {
                                                                                strcpy(schedule[j-1], schedule[j]);
                                                                                schedule[j][0]='\0';
										strcpy(phone[j-1], phone[j]);
										phone[j][0]='\0';
										printf("appt at %d pm moved to %d pm \n", j+1,j);
                                                                                }
                                                                        }
                                                }
                                        }
}
void list (void)
{
int i;
				for (i=0; i<SIZE; i++)
                                        {
				if (schedule[i][0] == '\0' && phone[i][0] == '\0')
                                                {
                                                        printf("%d pm is available \n", i+1);
                                                }
                                                 else
                                                {
                                                        printf("%d pm is booked by %s phone%s\n", i+1, schedule[i], phone[i]);
                                                }
                                        }
}
void firstletter (void)
{
int i;                                        
                {                        

                        if (appts==0)
				printf("No appts booked");
			else
                                {
                                printf("Enter the first letter of your name.");
                                scanf(" %c", &letter);
					fflush(stdin);
                                        for (i=0; i<SIZE; i++)
                                                {
                                                if (letter == schedule[i][0])
                                                        printf("%d pm %s \n",i+1, schedule[i]);
                                                }
                                }
                   } 
	    
}
int option2(char letter2)
{ 
int count=0;
char *p;
int i;

			for(i=0;i<appts;i++)
			{
				p=schedule[i];
				while(*p!='\0')
				{
				if (*p==letter2 )
				{
				count++;
				}
				p++;
				}
			}
	
				return count;
			
}	

int priority (void)
{
int i,j;
	{
			
				if(appts==SIZE)
				{
				printf("The appt booked by %s has been cancelled",schedule[SIZE-1]);
				appts--;
				}
			printf("Please enter your name");
			scanf ("%s",&name);
			printf ("Please enter your number");
			scanf ("%s",&phonenum);
				   for (i=appts-1; i>=0; i--)
                                 {
                                  	strcpy(schedule[i+1], schedule[i]);
                                  	strcpy(phone[i+1], phone[i]);
                                        printf("The appt at for %s for number %s at %dpm has been moved to %dpm \n",schedule[i],phone[i],i+1,i+2);
				                                                                                                                                      
                                 }
				
                                  strcpy(schedule[0], name);
                                  appts++;
                                  strcpy(phone[0],phonenum);
                                  printf("Appt scheduled for 1pm by %s\n", schedule[0]);
                                
                                                                                                                                                                                                              
        } 
     
         
return 1;
}											
