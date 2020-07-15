#include<stdio.h>
int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int year,month,week,day,C,R,A;
void INPUT()
{
	printf("请输入年份：");
	scanf("%d",&year);
}
int Year(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
	{
		return 366;
	}
	else
	{
		return 365;
	}
}
main()//以2020年7月6日（星期一）为基准 
{
	int yearsum=0,i,j,date,Yday;
	INPUT();
	Yday=Year(year);
	if(Yday==366)
	{
		M[1]=29;
	}
	if(year<2020)
	{
		C=abs(year-2020);
		R=abs(year%4-4);
		A=(C-R)/4;
		yearsum=A*366+(C-A)*365+188;
		week=yearsum%7;
	}
	if(year>2020)
	{
		C=abs(year-2020);
		R=year%4;
		A=(C-R)/4;
		yearsum=A*366+(C-A)*365+178;
		week=yearsum%7;
	}
	if(year==2020)
	{
	    yearsum=178;
	    week=yearsum%7-1;
	}
	for(i=0;i<12;i++)
	{
		printf("------------------------%d月------------------------\n",i+1);
		printf("一\t二\t三\t四\t五\t六\t日\n");
		date=1;
		for(j=0;j<week;j++)
		{
			printf("\t");
		}
		while(date<=M[i])
		{
			printf("%d\t",date);
			date++;
			week=(week+1)%7;
			if(week==0)
			{
				printf("\n");
			}
		}
		printf("\n\n");
	}
}

