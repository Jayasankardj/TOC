#include<stdio.h> 
#include<string.h> 
int trans_table[10][5][3]; 
char symbol[5],a; 
int e_closure[10][10],ptr,state; 
void find_e_closure(int x); 
int main() 
{ 
 int i,j,k,n,num_states,num_symbols; 
 for(i=0;i<10;i++) 
 { 
  for(j=0;j<5;j++) 
  { 
   for(k=0;k<3;k++) 
   { 
    trans_table[i][j][k]=-1; 
   } 
  } 
 } 
 printf("How may states in the NFA with e-moves:"); 
 scanf("%d",&num_states); 
 printf("How many symbols in the input alphabet including e :"); 
 scanf("%d",&num_symbols); 
 printf("Enter the symbols without space. Give 'e' first:"); 
 scanf("%s",symbol); 
 for(i=0;i<num_states;i++) 
 { 
  for(j=0;j<num_symbols;j++) 
  { 
   printf("How many transitions from state %d for the input %c:",i,symbol[j]); 
   scanf("%d",&n); 
   for(k=0;k<n;k++) 
   { 
    printf("Enter the transitions %d from state %d for the input %c :", k+1,i,symbol[j]); 
    scanf("%d",&trans_table[i][j][k]); 
   } 
  } 
 } 
 for(i=0;i<10;i++) 
 { 
  for(j=0;j<10;j++) 
  { 
   e_closure[i][j]=-1; 
  } 
 } 
 for(i=0;i<num_states;i++) 
 e_closure[i][0]=i; 
 for(i=0;i<num_states;i++) 
 { 


  if(trans_table[i][0][0]==-1) 
  continue; 
  else 
  { 
    state=i; 
    ptr=1; 
    find_e_closure(i); 
  } 
 } 
 for(i=0;i<num_states;i++) 
 { 
  printf("e-closure(%d)= {",i); 
  for(j=0;j<num_states;j++) 
  { 
   if(e_closure[i][j]!=-1) 
   { 
    printf("%d, ",e_closure[i][j]); 
   } 
  } 
  printf("}\n"); 
 } 
} 
void find_e_closure(int x) 
{ 
 int i,j,y[10],num_trans; 
 i=0; 
 while(trans_table[x][0][i]!=-1) 
 { 
  y[i]=trans_table[x][0][i]; 
  i=i+1; 
 } 
 num_trans=i; 
 for(j=0;j<num_trans;j++) 
 { 
  e_closure[state][ptr]=y[j]; 
  ptr++; 
  find_e_closure(y[j]); 
 } 
}
