#include <stdio.h>
int main()
{
	int a,b,c,d,m;
	printf("������a=");
	scanf("%d",&a);
	printf("������b=");
	scanf("%d",&b);
	printf("������c=");
	scanf("%d",&c);
	printf("������d=");
	scanf("%d",&d);
	if((a>b)||(c>d))
	{
		if(a<c)
		{
			m=c;
			c=a;
			a=m;
		}
		if(b<d)
		{
			m=b;
			b=d;
			d=m;
		}	 
	}
	printf("�ɴ�С���Ϊ��%d %d %d %d",a,b,c,d);
	return 0;
}
