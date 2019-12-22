#include <stdio.h>
#include "txtFind.h"
#include <string.h>
#define LINE 256
#define WORD 30
#define enter '\n'
#define tab '\t'
#define space ' '
#define printLine "a"
#define printSimilarWords "b"

int GetLine(char s[])
{
    int counter=0;
    char c;
    while (scanf("%c",&c)!=EOF && c!=enter)
    {
            s[counter++]=c;
    }//while
    s[counter]='\0';
    //printf("Line: %s\n",s);
    return counter;
}//getLine

int GetWord(char s[])
{
    int counter=0;
    char c;
    while (scanf("%c",&c)!=EOF)
    {
        // printf("%d %c ",counter,c);
        if(c==tab || c==space) 
        {
            // printf("BREAK\n");
            break;
        }//else   
        if(c==enter)
            {
                counter--;
                break;
            }//if                 
        else
            s[counter++]=c; 
    }//while
     s[counter]='\0';
    // printf("Word: %s, counter= %d\n",s,counter);
    return counter;
}//GetWord

int substring(char * str1, char * str2)
{
    int j,i;
    int len2=strlen(str2);
    int len1=strlen(str1);
    if(len1>len2)
        return 0;
    for (i = 0; i < len2-len1; i++)
    {
       for (j = 0; j < len1; j++)
       {
            if(*(str2+i+j)!=*(str1+j))
               break;
       }//for
        if(j>=len1)
            return 1;    
    }//for
    return 0;
}//substring

int similar (char *str1, char *str2, int n)
{
    int len2=strlen(str2);
    int i=0;
    int len1=strlen(str1);
    int j=0;
    if(len2<len1)
        return 0;
    while(j<len1 && i<len2)
    {
        if(*(str1+j)==*(str2+i))//If this char of str1 is inside str2
            j++;
        i++;    
    }//while
    if(j>=len1 && (len2-len1)<=n)//Checking the two criterions
        return 1;
    return 0;
}//similar

void print_lines(char* str)
{
    char s[LINE];
    int counter=GetLine(s);
    while (counter)
    {
    int ans=0;
    char word[WORD];
    char* w=word;
    int j=0;
    int i;
      for (i = 0; i < counter; i++)
      {
        //Create word
         if(s[i]!='\0' && s[i]!=space && s[i]!=tab && s[i]!=enter)
         {
             word[j++]=s[i];
         }//if
         else
         {
                word[j]='\0';
                if(ans!=1)
                    ans=similar(str,w,1);
                //printf("Word= %s, len=%ld, ans= %d\n",w,strlen(w),ans);
                j=0;  
         }//else
      }//for
        char copy[LINE];
        strcpy(copy,s);
         counter=GetLine(s);
         if(counter==0)
            word[j]='\0';
         else
            word[j-1]='\0';
         if(ans!=1)
            ans=similar(str,w,1);
        //printf("Word= %s, len=%ld, ans= %d\n",w,strlen(w),ans);
         if(ans==1)
            printf("%s\n",copy);
            
    }//while
}//print_lines
void print_strAsIs(char a[],int count)
{
    if(count==1)
        printf("Empty");
    for (int i = 0; i < count; i++)
    {
        printf("%c",a[i]);
    }//for
    printf("\n");
}//print_strAsIs

void print_similar_words(char* str)
{
    char w[WORD];
    char* word=w;
    int counter=GetWord(w);
    while (counter)
    {
        if(similar(str,word,1)){
            //printf("TRUE\n");
            print_strAsIs(w,counter);
        }//if
        counter=GetWord(w);
    }//while
}//print_similar_words

void SpecificTextParser()
{
    char op[WORD];
    char name[WORD];
    char line[LINE];
    int l=GetWord(name);
    //printf("name=%s , len=%ld\n",name,strlen(name));
    l=GetWord(op);
    //printf("op=%s , len=%ld\n",op,strlen(op));
    l=GetLine(line);//Empty Line
    //printf("%s\n",line);
    char a[]="a";
    char b[]="b";
    if(similar(op,a,0)==1)
    {
        print_lines(name);
    }//if
    else if(similar(op,b,0)==1)
    {
        print_similar_words(name);
    }//else if
    else
        printf("ERR: Wrong input operation");
    
}//SpecificTextParser