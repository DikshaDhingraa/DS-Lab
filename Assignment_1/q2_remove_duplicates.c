#include <stdio.h>
int main(){int n,a[100];printf("Enter number of elements: ");scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(a[i]==a[j]){for(int k=j;k<n-1;k++)a[k]=a[k+1];n--;j--;}printf("Array after removing duplicates: ");for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");return 0;}
