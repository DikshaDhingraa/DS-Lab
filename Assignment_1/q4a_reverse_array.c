#include <stdio.h>
int main(){int n,a[100];scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0,j=n-1;i<j;i++,j--){int t=a[i];a[i]=a[j];a[j]=t;}for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");return 0;}
