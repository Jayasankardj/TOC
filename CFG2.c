#include<stdio.h> 
#include<string.h> 
int main() 
{ 
 char s[100]; 
 int i,flag,flag1,flag2; 
 int l; 
 printf("enter a string to check:"); 
 scanf("%s",s); 
 l=strlen(s); 
 flag=1; 
 for(i=0;i<l;i++) 
 { 
  if(s[i]!='0' && s[i]!='1') 
  { 
      flag=0; 
  } 
 } 
 if(flag!=1) 
  printf("string is Not Valid\n"); 
 if(flag==1) 
 { 
  if(l%2!=0)  
          { 
            printf("The string does not satisfy the condition 0n1n\n"); 
            printf("String Not Accepted\n"); 
             } 
  else 
  { 
   flag1=1; 
   for(i=0;i<(l/2);i++) 
   { 
    if(s[i]!='0') 
    { 
     flag1=0; 
    } 
   } 
   flag2=1; 
   for(i=l/2;i<l;i++) 
   { 
    if(s[i]!='1') 
    { 
     flag2=0; 
    } 
   } 
   if(flag1==1 && flag2==1) 
               { 
                printf("The string satisfies the condition 0n1n\n"); 
                printf("String Accepted\n"); 
             } 
   else 
               { 
                printf("The string does not satisfy the condition 0n1n\n"); 
                printf("String Not Accepted\n"); 
            } 
  } 
 } 
} 
