#define MAX 500 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
int table[MAX]; 
char text[MAX]; 
char pattern[MAX]; 
void shiftTable(char patern[],int m) 
{ 
 int i,j; 
 for(i=0;i<MAX;i++) 
 table[i]=m; 
 
 for(j=0;j<m-1;j++) 
 table[pattern[j]]=m-1-j;
} 
int Horspool(char pattern[],int m,char text[],int n) 
{ 
 int i,j,k; 
 shiftTable(pattern,m); 
 i=m-1;
 while(i<n) 
 { 
 k=0; 
 while ((k<m) && (pattern[m-1-k]==text[i-k])) 
 { 
 k++; 
 } 
 if(k==m) 
 return i-(m-1); 
 else 
 i=i+table[text[i]]; 
 } 
} 
void main() 
{ 
 int m,n,result; 
 double clk; 
 clock_t start,end; 
 
 printf("ENTER A TEXT\n"); 
 scanf("%s",text); 
 
 printf("ENTER PATTERN TO SEARCH\n"); 
 scanf("%s",pattern); 
 
 m=strlen(pattern); 
 n=strlen(text); 
 
 start=clock(); 
 result=Horspool(pattern,m,text,n); 
 end=clock(); 
 
 if(result==-1)
 printf("PATTERN NOT FOUND\n"); 
 else 
 printf("PATTERN FOUND AT %d\n",result); 
 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 
 printf("TIME REQUIRED IS %f\n",clk); 
}
