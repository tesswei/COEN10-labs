#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20


char words[MAX_WORDS][MAX_LENGTH];
int length[MAX_WORDS];
int counter = 0;


void input(void);
void reverse(void);
void convert(void);
void info(void);
void show(void);

//Puts it in alphabetical order
void input(void) {
int i,j,k;
char temp[MAX_LENGTH];
printf("Input 10 words to sort alphabetically\n");
	for(i=0;i<MAX_WORDS; i++)
	{
		if (scanf("%s", &temp)<1)
				break;
		counter++;
        	for (j = 0; j < i; j++) {
            		if (strcmp(temp, words[j]) < 0) {
                		break;
            	}
        }
        for (k = counter-1; k >=j; k--) {
            strcpy(words[k+1], words[k]);
        }
        strcpy(words[j], temp);
       
    }
    show();
}
// Reverses the order
void reverse(void) {
int i;
char temp[MAX_LENGTH];
    for ( i = 0; i < counter / 2; i++) {
        strcpy(temp, words[i]);
        strcpy(words[i], words[counter - 1 - i]);
        strcpy(words[counter - 1 - i], temp);
    }
    show();
}

// converts to uppercase
void convert(void) {
int i=0;
char *p;
int count=0;
for(i=0;i<counter;i++)
	{
		count=0;
		p = words[i];
	
		while(*p!='\0')
		{
			count++;
			if (*p >='a' && *p<='z')
			{
				*p = (toupper(*p));
			}
  
	p++;
		}
	length[i]=count;
	}	
	show();
}

//Gives longest and shortest word and average word length
void info(void) {
int i;
int minLen = MAX_LENGTH, maxLen = 0;
int avgLen = 0;
int minpos;
int maxpos;
    for (i = 0; i < counter; i++) {
        avgLen += length[i];
        if (length[i] < minLen) 
	{	minLen = length[i];
		minpos=i;

	}	
        if (length[i] > maxLen)
		{
		 maxLen = length[i];
		maxpos=i;
		}
    }
    avgLen /= counter;
    printf("Shortest word: %s\n", words[minpos]);
    printf("Longest word: %s\n", words[maxpos]);
    printf("Average word length: %d\n", avgLen);

    for (i = 0; i < counter; i++) {
        if (isalpha(words[i][0])) {
            printf("%s\n", words[i]);
        }
    }
}

//Allows to print
void show(void) {
int i;
    for (i = 0; i < counter; i++) {
        printf("%s\n", words[i]);
    }
}


int main(void) {
    input();
    reverse();
    convert();
    info();
    return 0;
}

