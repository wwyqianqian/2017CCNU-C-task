#include <stdio.h>
int main(void)
{
    int a[100],i,j,t,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(i=1;i<=n-1;i++) //n个数排序，只用进行n-1趟
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]<a[j+1]) //比较大小并交换
            {  t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();
    return 0;
}
