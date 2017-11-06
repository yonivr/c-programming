#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void zeroarr(char s[])
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        s[i]=0;
    }
}

char *  splitComma(char s[])
{
    int i;//s iterator
    int j=0;//temp iterator
    int gotComma=0;
    char *res = malloc (sizeof (char) * strlen(s));
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==',')
        {
            gotComma=1;
            return res;
        }
        if(gotComma==0)
        {
            res[j]=s[i];
            j++;
        }   
    }
    return res;
}

void iterateLine(char s[])
{
    int	i=-1, count = 0;
    char c=',';
    char *res = malloc (sizeof (char) * strlen(s));
    res = splitComma(s);
	printf("%s\n",res);
	while(s[++i])
	{
	   if(s[i] == c) 
	   {
	       zeroarr(res);
	       res = splitComma(s+i+1);
	       printf("%s\n",res);
	       count++;
	   }
	}  
	printf("%d\n",count);
}

int main()
{
    char s[]="apple,banana,mango,melon";
    iterateLine(s);
    return 0;
}
