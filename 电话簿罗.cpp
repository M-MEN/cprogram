//电话簿
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 10
#define LED sizeof(struct phone)
struct phone
{
	char name[20];
	char call[15];
	struct phone *next;
};//电话+姓名信息结构体
typedef struct phone PHONE;
PHONE *phonebank(PHONE *head,int num);//创建(包含增添)电话簿
void printbank(PHONE *head1);//输出信息函数
void phonechange(PHONE *head2);//修改信息函数
void namechange(PHONE *head3);//修改姓名函数
void callchange(PHONE *head4);//修改电话函数
void addphone(PHONE *head5);//增加
void searchphone(PHONE *head6);//查找
void deletephone(PHONE *head7);//删除
void sortphone(PHONE *head8);//排序

int paiduanbank=0;//是否创建电话簿 
int n=1;//链表数
int main()
{
	PHONE *Head;
	int chiose,loop=1;
	char xishou;
	printf("*********使用帮助*********\n");
	printf("[ 1 ]创建电话簿\n");
	printf("[ 2 ]浏览电话薄\n");
	printf("[ 3 ]增加联系人\n");//插入电话簿
	printf("[ 4 ]修改联系人信息\n");
	printf("[ 5 ]查找联系人\n");//分姓名查找和电话号查找
	printf("[ 6 ]删除联系人\n");
	printf("[ 7 ]电话簿排序\n");
	printf("[ 8 ]安全退出\n");
	printf("**************************\n");
	while(loop)
	{
			printf("请选择一个选项: ");
	        scanf("%d",&chiose);
			if(chiose>8||chiose<1)
			{
				printf("\n输入错误,无此选项,请重新输入(1-8): ");
				scanf("%d",&chiose);
			}
	        switch (chiose)
			{
	         case 1:
				 {
					 if(paiduanbank)
					 {
						 printf("已经创建,是否重新创建[Y/N] :");
						 getchar();
						 xishou=getchar();
						 if(xishou=='Y'||xishou=='y')Head=phonebank(Head,N);
						 else printf("仍使用当前电话簿");
					 }
					 else Head=phonebank(Head,N);
					 break;
				 }
	         case 2:
				 {
					 if(!paiduanbank)
					 {
						 printf("无联系人，请先创建存储联系人\n");
					     break;
					 }
					 else printbank(Head);
					 break;
				 }
			 case 3:
				 {
					 addphone(Head);
					 break;
				 }
			 case 4:
				 {
					 phonechange(Head);
					 break;
				 }
			 case 5:
				 {
					 searchphone(Head);
					 break;
				 }
			 case 6:
				 {
					 deletephone(Head);
					 break;
				 }
			 case 7:
				 {
					 sortphone(Head);
					 break;
				 }
			 case 8:
			{
				 printf("程序结束!");
				 loop=0;
				 break;
			}
			 default :break;
			}
	}
	return 0;
}
PHONE *phonebank(PHONE *head,int num)//记录联系人电话，姓名
{
	struct phone *newp,*p2;
	int i;
	char xishou,xishou2;
	printf("提示 : 存储电话必须在两个及以上!\n");
	//printf("请输入联系人的姓名以及电话(姓名与电话输入时,以逗号相隔): \n");
	p2=newp=(struct phone *)malloc(LED);//newp=(struct phone *)calloc(LED,100);
	printf("请输入联系人的姓名 : ");
    scanf("%s",newp->name);
	printf("请输入联系人的电话 : ");
    scanf("%s",newp->call);
	//scanf("%s,%s",newp->name,newp->call);
	head=NULL;	
	for(i=1;i<=N;i++)
	{
		printf("是否继续存储[Y/N]:");
		getchar();
		xishou2=getchar();
		if(xishou2=='Y'||xishou2=='y')
		{
			//printf("请继续存储:\n");
			if(n==1)head=newp;
			else p2->next=newp;
			p2=newp;
			newp=(struct phone *)malloc(LED);
			printf("请输入联系人的姓名 : ");
			scanf("%s",newp->name);
	        printf("请输入联系人的电话 : ");
	        scanf("%s",newp->call);
			//scanf("%s,%s",newp->name,newp->call);
			n++;
		}
		else if(xishou2=='N'||xishou2=='n')
		{
			printf("此次操作还可存储%d个电话，确认终止？[Y/N]:",N-i+1);
			getchar();
			xishou=getchar();
			if(xishou=='Y'||xishou=='y')
			{
				printf("已经终止\n");
				break;
			}
		}
	}
	p2->next=newp;
	p2=newp;
	p2->next=NULL;
	paiduanbank=1;
	return head;
}
void printbank(PHONE *head1)//输出
{
	PHONE *p=head1;
	int i=1;
	printf("\n已存储信息如下 \n\n");
	printf("序号      姓名      电话    \n");
	while(p!=NULL)
		{
			printf("%3d%12s%9s\n",i,p->name,p->call);
			p=p->next;
			i++;
		}
		
}
void phonechange(PHONE *head2)//修改
{
	char xishou;
	printf("若需要修改某联系人姓名[Y],若需要修改某联系人电话[N]:");
	getchar();
	xishou=getchar();
	if(xishou=='Y'||xishou=='y') namechange(head2);
	else callchange(head2);
}
void namechange(PHONE *head3)
{
	PHONE *p=head3;
	char newname[20],oldname[20];
	printf("请输入你需要修改的联系人姓名:");
	scanf("%s",oldname);
	while(p!=NULL)
	{
		if(strcmp(p->name,oldname)==0)
		{
			printf("请输入新名字:");
	        scanf("%s",newname);
			strcpy(p->name,newname);
			printf("修改姓名成功\n");
			break;
		}
		p=p->next;
	}
	if(p==NULL)printf("不存在此姓名\n");
}
void callchange(PHONE *head4)
{
	PHONE *p=head4;
	char newcall[20],oldcall[20];
	printf("请输入你需要修改的联系人电话:");
	scanf("%s",oldcall);
	while(p!=NULL)
	{
		if(strcmp(p->call,oldcall)==0)
		{
			printf("请输入新电话:");
	        scanf("%s",newcall);
			strcpy(p->call,newcall);
			printf("修改电话成功\n");
			break;
		}
		p=p->next;
	}
	if(p==NULL)printf("不存在此电话");
}
void addphone(PHONE *head5)//增加
{
	PHONE *p=head5,*newh,*p3;
	int loop2=1;
	newh=(struct phone *)malloc(LED);
	printf("请输入新联系人姓名 :");	
	scanf("%s",newh->name);
	printf("请输入新联系人电话 :");
	scanf("%s",newh->call);
	while(p!=NULL)
	{
		p3=p;
		if(strcmp(newh->call,p->call)==0)
		{printf("此号码已存在，您肯定是记错号码了！\n");
		break;}
		if(strcmp(newh->name,p->name)==0)
		{printf("此联系人姓名已存在(若是两个不同号码，请区分，例: luo2)\n");
		break;}
		p=p->next;
	}
	if(p==NULL)
	{
		p3->next=newh;
		p3=newh;
		newh->next=p;
		printf("增加成功\n");
	}
}
void searchphone(PHONE *head6)//查找
{
	PHONE *p=head6,*p2;
	p2=(struct phone *)malloc(LED);
	printf("请输入你要查找的姓名 :");
	scanf("%s",p2->name);
	while(p!=NULL)
	{
		if(strcmp(p2->name,p->name)==0)
		{
			printf("姓名: %s,电话: %s\n",p->name,p->call);
			break;
			p=p->next;
		}
	}
	if(p==NULL)printf("电话簿中没有存储此人信息\n");
}
void deletephone(PHONE *head7)//删除
{
	PHONE *p=head7,*p3;
	char name[20];
	printf("请输入你所要删除的联系人姓名 :");
	scanf("%s",name);
	for(;p!=NULL;p3=p,p=p->next)
	{
		if(strcmp(name,p->name)==0)
		{
			if(p==head7)
			{
				p=head7->next;
				head7=p;
			}
			else 
			{
				p3->next=p->next;
				if(p->next!=NULL)p=p->next;
			}
			printf("删除成功\n");
			n=n-1;
			break;	
		}
	}
	if(p==NULL)printf("电话簿中没有存储此人信息\n");
}
void sortphone(PHONE *head8)
{
	PHONE *p,*p2,*p3;
	char t[20];
	int n1,n2,choice;
	printf("请选择排序方式:（1.姓名首字母排序。2.姓名长度排序）");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	{
	for(p=head8;p!=NULL;p=p->next)
	{
		p2=p->next;
		while(p2!=NULL)
		{
			if(*p->name>*p2->name)
			{
				strcpy(t,p2->name);
				strcpy(p2->name,p->name);
				strcpy(p->name,t);
				strcpy(t,p2->call);
				strcpy(p2->call,p->call);
				strcpy(p->call,t);
			}
			p2=p2->next;
		}
	}
	printf("排序成功\n");
	break;
	}
	case 2:
	{
	for(p=head8;p!=NULL;p=p->next)
	{
		p2=p->next;
		while(p2!=NULL)
		{
			n1=strlen(p->name);
			n2=strlen(p2->name);
			if(n1>n2)
			{
				strcpy(t,p2->name);
				strcpy(p2->name,p->name);
				strcpy(p->name,t);
				strcpy(t,p2->call);
				strcpy(p2->call,p->call);
				strcpy(p->call,t);
			}
			p2=p2->next;
		}
	}
	printf("排序成功\n");
	break;
	}
	default :break;
	}
}