#include<stdio.h>
int main ()
{
int n;
printf("Enter ARRAY Size:");
scanf("%d",&n);

int array[n];
printf("Enter ARRAY:");
for(int i=0;i<n;i++)
{
    scanf("%d",&array[i]);
}

int i,j,temp;
for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++)
    {
        if(array[j]>array[j+1])
        {
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
    }
}

for(int i=0;i<n;i++)
{
    printf("%d ",array[i]);
}

return 0;
}
