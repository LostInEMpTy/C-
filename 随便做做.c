#include <stdio.h>
int main()
{
    int a,b,c,d,x;
    printf("������һ����λ��");
    scanf("%d",&x);
    a=x/1000;
    b=(x-a*1000)/100;
    c=(x-a*1000-b*100)/10;
    d=x-a*1000-b*100-c*10;
    printf("��λ����������%d%d%d%d\n",d,c,b,a);
    return 0;
}
