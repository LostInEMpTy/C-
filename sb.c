#include <stdio.h>
int main()
{
	int a,b,c,d,m;
	printf("请输入a=");
	scanf("%d",&a);
	printf("请输入b=");
	scanf("%d",&b);
	printf("请输入c=");
	scanf("%d",&c);
	printf("请输入d=");
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
	printf("由大到小输出为：%d %d %d %d",a,b,c,d);
	return 0;
}
