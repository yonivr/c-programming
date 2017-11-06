#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int isValidWord(char s[])
{
    if((s[0]>='A'&&s[0]<='F')&&(strlen(s)==1))
        return 0;
    return -1;
}

int isValidCommand(char s[])
{
    char *valid_commands[] = {"halt", "abs" ,"print_comp" , "add_comp","sub_comp" , "mult_comp_real" , "mult_comp_img"  , "mult_comp_comp" , "read_comp"   };
    int i;
    int arrlen=sizeof(valid_commands)/sizeof(valid_commands[0]);
    for(i=0;i<arrlen;i++)
    {
        if(strcmp(s,valid_commands[i])==0)
            {
                if(i==0)
                    return 0;
                if(i==1||i==2)
                    return 1;
                if(i==arrlen-1)
                    return 3;
                return 2;
                    
            }
    }
    return -1;
}

int isValidNumber(char s[])
{
    if(atof(s)>0)
        return 0;
    return -1;
}




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
    int action=-2;
    int wordcount=0;
    char c=',';//seperator 
    char *res = malloc (sizeof (char) * strlen(s)); //allocate string for current word
    /************first word********/
    res = splitComma(s,' ');//split string by space to find first command
    //printf("%s\n",res);
    action=isValidCommand(res);
    if(action==-1)
        printf("Invalid command\n");
    wordcount++;
   // printf("%d   %s\n",wordcount,res);
    /***********second word*****************/
    i=strlen(res);//start from next word after command
    zeroarr(res);//zero res arr
   res = splitComma(s+i,c);//find next word before comma
   if(isValidWord(res)==-1)
   {
       printf("Invalid complex variable\n");
   }
    wordcount++;
 //   printf("%d   %s\n",wordcount,res);
   /*************************************/
  // printf("%s\n",res);
	while(s[++i])//iterate string s until the end
	{
	   if(s[i] == c) //case found seperator
	   {
	       zeroarr(res);//zero the current word
	       res = splitComma(s+i+1,c);//current word is set by offset i from start and comma seperator
	       wordcount++;
	  //     printf("%d   %s\n",wordcount,res);
	       if((wordcount==3&&action==3)&&(isValidNumber(res)==-1))
	       {
	           printf("Wrong parameter, second parameter must be a real number\n");
	       }
	       //printf("%s\n",res);
	   }
	}  
	
}

int main()
{
    //char s[]="apple    ,banana,mango,melon";
    char s[]="read_comp A, B, 23.7";
    //char string[]="read_comp1";
  //  printf("%d\n",isValidCommand(string));
   iterateLine(s);
    return 0;
}
