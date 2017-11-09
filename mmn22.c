#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LINE 64
#define LINE_LEN 64
#define HALT 9

int isValidWord(char s[]);
char * addEnd(char *s);
int compareString(char *s1, char *s2);
int isValidCommand(char *s);
int isValidNumber(char s[]);
int ifAllSpace(char s[]);
char * zeroarr(char s[]);
char *  splitComma(char s[], char c);
int iterateLine(char s[]);
int getLine(char s[], int lim);
void readInput();


int main()
{
	//char s[]="print_comp A";

	char s[64];
	readInput(s, 64);
	//iterateLine(s);
	return 0;
}


int isValidWord(char s[])
{
	if ((s[0] >= 'A'&&s[0] <= 'F') && (strlen(s) == 1))
		return 0;
	return -1;
}

int compareString(char *s1, char *s2)
{
	int i;
	for (i = 0; i < strlen(s1); i++)
	{
		if (s1[i] != s2[i])
		{
			return 1;
		}
	}
	return 0;
}
/**
int isValidCommand(char *s)
{
char *valid_commands[] = { "halt", "abs" ,"print_comp" , "add_comp","sub_comp" , "mult_comp_real" , "mult_comp_img"  , "mult_comp_comp" , "read_comp" };
int i;
int arrlen = sizeof(valid_commands) / sizeof(valid_commands[0]);
for (i = 0; i < arrlen; i++)
{
if (strcmp(s, valid_commands[i]) == 0)
{
if (i == 0)
return HALT;
if (i == 1 || i == 2)
return 1;
if (i == arrlen - 1)
return 3;
return 2;
}
}
return -1;
}
*/

int isValidCommand(char *s)
{
	char *valid_commands[] = { "halt", "abs" ,"print_comp" , "add_comp","sub_comp" , "mult_comp_real" , "mult_comp_img"  , "mult_comp_comp" , "read_comp" };
	int i;
	int arrlen = sizeof(valid_commands) / sizeof(valid_commands[0]);

	for (i = 0; i<arrlen; i++)
	{
		if (strstr(s, valid_commands[i]) !=NULL)
		{
			if (i == 0)
			{
				return HALT;
			}
			if (i == 1 || i == 2)
				return 1;
			if (i == arrlen - 1)
				return 3;
			return 2;
		}
	}
	return -1;
}

int isValidNumber(char s[])
{
	if (atof(s)>0)
		return 0;
	return -1;
}


int ifAllSpace(char s[])
{
	int i;
	if (strlen(s) == 0)
		return 0;
	for (i = 0; i<(int)strlen(s); i++)
	{
		if (s[i] != ' ')
			return -1;
	}
	return 0;
}


/*
zero a char array
*/
char * zeroarr(char s[])
{
	int i;
	char *res = malloc(sizeof(char) * strlen(s));
	for (i = 0; i<(int)strlen(s); i++)
	{
		s[i] = '\0';
	}
	return res;
}

/**
* input  - char array s
* output - first string until comma
* purpose - return first word until comma
**/
char *  splitComma(char s[], char c)
{
	int i;//s iterator
	int j = 0;//temp iterator
	char *res = malloc(sizeof(char) * strlen(s)); //allocate a string to return
	zeroarr(res);
	for (i = 0; i<strlen(s); i++)//iterate until the end of s string
	{
		if (s[i] == c)//in case comma is found return array until comma
		{
			res[j] = '\0';
			return res;
		}
		else
		{//copy current char to res array if char is not comma and iterate res
			if (s[i] != ' ')
			{
				res[j] = s[i];
				j++;
			}

		}
	}
	res[j] = '\0';
	//res = addEnd(res);
	return res;//case no comma return the entire string
}
/**
* iterate s string , split string by comma and perform actions by the command
**/
int iterateLine(char s[])
{
	int	i = -1;
	int action = -2;
	int countcomma = 0;
	int isOnlySpace = 0;
	int excessflag = 0;
	int wordcount = 0;
	int wordstate = 0;// 0 - word not started , 1 word started , 2 space after word , 3 word after space
	char c = ',';//seperator 
	char *res = malloc(sizeof(char) * strlen(s)); //allocate string for current word
	char temparr[3];
	
	/************first word********/
	if (ifAllSpace(s) == 0)
		return 0;
	res=zeroarr(res);
	res = splitComma(s, ' ');//split string by space to find first command
	
	if (res[0] == ' ')
	{
		while (res[0] != ' ')
		{
			res = splitComma(s, ' ');
		}
	}
	res = addEnd(res);
	action = isValidCommand(res);
	if (action == HALT)
		return HALT;
	if (action == -1)
		printf("Invalid command\n");
	wordcount++;
	/***********second word*****************/
	if (action != -1)
	{
		i = strlen(res);//start from next word after command
		zeroarr(res);//zero res arr
		res = splitComma(s + i, c);//find next word before comma

		if (strlen(res)>0)
			wordcount++;
		if (action + 1 - wordcount<0)
		{
			if (excessflag == 0 && action != -1)
			{
				printf("Excessive text\n");
				excessflag = 1;
			}
		}
		else
		{
			if (isValidWord(res) == -1 && strlen(res)>0)
			{
				temparr[0] = res[0];
				temparr[1] = '\0';
				if (isValidWord(temparr) == -1)
					printf("Invalid complex variable\n");
			}
		}



		/*************************************/
		while (s[++i])//iterate string s until the end
		{
			if (wordstate == 0 && s[i] != ' ')
			{
				wordstate = 1;//char in string
			}
			if (wordstate == 1 && s[i] == ' ')
			{
				wordstate = 2;//space after char in string
			}
			if (wordstate == 2 && s[i] != ' '&&s[i] != c)
			{
				wordstate = 3;//char after space in string
				printf("Missing comma\n");
			}

			if (s[i] == c) //case found seperator
			{
				if (countcomma == 1)
				{
					printf("Multiple consecutive commas\n");
					countcomma = 0;
				}
				countcomma = 1;
				zeroarr(res);//zero the current word
				res = splitComma(s + i + 1, c);//current word is set by offset i from start and comma seperator
				if (strlen(res)>0)
					wordcount++;
				wordstate = 0;
				if ((wordcount == 3 && action == 3) && (isValidNumber(res) == -1))
				{
					printf("Wrong parameter, second parameter must be a real number\n");
				}
			}
			else if (s[i] != c && s[i] != ' ')
			{
				countcomma = 0;
			}
		}
		if (action + 1 - wordcount<0)
		{
			if (excessflag == 0 && action != -1)
			{
				printf("Excessive text\n");
				excessflag = 1;
			}
		}

	}
	return 0;
}

int getLine(char s[], int lim)
{
	int i;
	int c = 0;
	printf("Complex numbers calculator ready, please enter command:\n");
	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i++] = c;
	s[i] = '\0';
	return i;
}


void readInput()
{
	int action = 0;
	char line[LINE_LEN];
	while (getLine(line, LINE_LEN) > 0 && action != HALT)
	{
		printf("line is		 %s\n", line);
		action = iterateLine(line);
	}
}



char * addEnd(char *s)
{
	int len = strlen(s)+1;
	char *temp = malloc(sizeof(char) * len);
	strcpy(temp, s);
	temp[len] = '\0';
	return temp;
}
