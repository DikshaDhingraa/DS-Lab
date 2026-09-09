#include <stdio.h>
#define MAX 100
int arr[MAX], n=0;
void create(){printf("Enter number of elements: ");scanf("%d",&n);if(n<0||n>MAX){printf("Invalid size\n");n=0;return;}for(int i=0;i<n;i++)scanf("%d",&arr[i]);}
void display(){for(int i=0;i<n;i++)printf("%d ",arr[i]);printf("\n");}
void insertElement(){int p,x;printf("Enter position and value: ");scanf("%d%d",&p,&x);if(p<1||p>n+1||n==MAX){printf("Invalid\n");return;}for(int i=n;i>=p;i--)arr[i]=arr[i-1];arr[p-1]=x;n++;}
void deleteElement(){int p;printf("Enter position: ");scanf("%d",&p);if(p<1||p>n){printf("Invalid\n");return;}for(int i=p-1;i<n-1;i++)arr[i]=arr[i+1];n--;}
void linearSearch(){int x;printf("Enter element: ");scanf("%d",&x);for(int i=0;i<n;i++)if(arr[i]==x){printf("Found at position %d\n",i+1);return;}printf("Not found\n");}
int main(){int ch;do{printf("\n1.Create 2.Display 3.Insert 4.Delete 5.Linear Search 6.Exit\nEnter choice: ");scanf("%d",&ch);switch(ch){case 1:create();break;case 2:display();break;case 3:insertElement();break;case 4:deleteElement();break;case 5:linearSearch();break;}}while(ch!=6);return 0;}
