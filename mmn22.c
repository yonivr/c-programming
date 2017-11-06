#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
zero a char array 
*/
void zeroarr(char s[])
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        s[i]=0;
    }
}

/**
 * input  - char array s
 * output - first string until comma
 * purpose - return first word until comma
 **/
char *  splitComma(char s[],char c)
{
    int i;//s iterator
    int j=0;//temp iterator
    char *res = malloc (sizeof (char) * strlen(s)); //allocate a string to return
    for(i=0;i<strlen(s);i++)//iterate until the end of s string
    {
        if(s[i]==c)//in case comma is found return array until comma
        {
            return res;
        }
        else
        {//copy current char to res array if char is not comma and iterate res
            if(s[i]!=' ')
            {
                res[j]=s[i];
                j++;    
            }
            
        }   
    }
    return res;//case no comma return the entire string
}
/**
 * iterate s string , split string by comma and perform actions by the command
 **/
void iterateLine(char s[])
{
    int	i=-1;
    char c=',';//seperator 
    char *res = malloc (sizeof (char) * strlen(s)); //allocate string for current word
    res = splitComma(s,' ');//split string by space to find first command
    printf("%s\n",res);
    i=strlen(res);//start from next word after command
    zeroarr(res);//zero res arr
   res = splitComma(s+i,c);//find next word before comma
   printf("%s\n",res);
	while(s[++i])//iterate string s until the end
	{
	   if(s[i] == c) //case found seperator
	   {
	       zeroarr(res);//zero the current word
	       res = splitComma(s+i+1,c);//current word is set by offset i from start and comma seperator
	       printf("%s\n",res);
	   }
	}  
	
}

int main()
{
    //char s[]="apple    ,banana,mango,melon";
    char s[]="read_comp A, 45.1, 23.7";
    iterateLine(s);
    return 0;
}
