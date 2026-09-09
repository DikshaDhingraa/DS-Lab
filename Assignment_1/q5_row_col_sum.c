#include <stdio.h>
int main(){int r,c,a[10][10];scanf("%d%d",&r,&c);for(int i=0;i<r;i++)for(int j=0;j<c;j++)scanf("%d",&a[i][j]);for(int i=0;i<r;i++){int s=0;for(int j=0;j<c;j++)s+=a[i][j];printf("Row %d = %d\n",i+1,s);}for(int j=0;j<c;j++){int s=0;for(int i=0;i<r;i++)s+=a[i][j];printf("Column %d = %d\n",j+1,s);}return 0;}
