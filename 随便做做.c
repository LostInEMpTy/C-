#include <stdio.h>
int main()
{
    int a,b,c,d,x;
    printf("请输入一个四位数");
    scanf("%d",&x);
    a=x/1000;
    b=(x-a*1000)/100;
    c=(x-a*1000-b*100)/10;
    d=x-a*1000-b*100-c*10;
    printf("四位数倒过来是%d%d%d%d\n",d,c,b,a);
    return 0;
}
