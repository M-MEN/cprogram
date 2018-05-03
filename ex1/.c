#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define M 3
#define N 10
#define LED sizeof(struct student)
struct student
{
	char name[19];
	int sex;         //0表示男，1表示女
	char nation[10];
	int old;
	char address[50];
	int lial;
	int English;
	int math;
	int Clang;
	int allscore;
	struct student *next;
};
typedef struct student STUDENT;
void changecolor();//改颜色
void modify(char *rightmm);//修改密码，要用文件
STUDENT *Studentbank(STUDENT *head,int num);//录入学生信息
STUDENT *perinput(STUDENT *head1);//人工输入学生信息
void savetofile(STUDENT *head3,FILE *fp4);//文件导入信息
void findscore(STUDENT *head2);//查找
void addscore(STUDENT *head4);//添加成绩
void print(STUDENT *head5);//所有人成绩显示
void deletescore(STUDENT *head6);//删除学生成绩
FILE *fp,*fp2,*fp3;	
STUDENT *Head;
int n=1;//链表数
int main()
{

	int l=1,i=0,choice,loop=1;
	char password[10],name[15],name2[15];
	char right[10];
	fp2=fopen("用户名.txt","r");
	fgets(name,10,fp2);
	fp=fopen("登陆密码.txt","r");
	fgets(right,10,fp);
	fclose(fp);
	fclose(fp2);
	printf("请输入用户名 :");
	scanf("%s",name2);
	printf("请输入登陆密码 :");
	scanf("%s",password);
	while(l)
	{
		if(strcmp(password,right)==0&&strcmp(name,name2)==0)
		{
			printf("登录成功,欢迎来到学生成绩管理系统\n");
			l=0;
		    printf("*********使用帮助*********\n");
			printf("[ 1 ]更改背景颜色和字体颜色\n");
			printf("[ 2 ]录入学生基本信息\n");
			printf("[ 3 ]查询成绩\n");
			printf("[ 4 ]总分排名\n");
			printf("[ 5 ]登陆密码修改\n");
			printf("[ 6 ]添加学生成绩\n");
			printf("[ 7 ]删除学生成绩\n");
			printf("[ 8 ]修改学生成绩\n");
			printf("[ 9 ]安全退出\n");
			printf("[ 10]显示使用帮助\n");
			printf("[ 11]成绩显示\n");
			printf("**************************\n");
			while(loop)
			{
				printf("请选择一个操作选项(1-11):");
				scanf("%d",&choice);
				if(choice<0||choice>11)
				{
					printf("选择错误,请重新选择(1-11):");
					scanf("%d",&choice);
				}
				switch(choice)
				{
				case 1:
					{
						changecolor();
						break;
					}
				case 2:
					{
						Head=Studentbank(Head,N);
						break;
					}
				case 3:
					{
						findscore(Head);
						break;
					}
				case 5:
					{
						modify(right);
						break;
					}
				case 6:
					{
						addscore(Head);
						break;
					}
				case 7:
					{
						deletescore(Head);
						break;
					}
				case 9:
					{
						loop=0;
						break;
					}
				case 10:
					{
			printf("*********使用帮助*********\n");
		    printf("[ 1 ]更改背景颜色和字体颜色\n");
			printf("[ 2 ]录入学生基本信息\n");
			printf("[ 3 ]查询成绩\n");
			printf("[ 4 ]总分排名\n");
			printf("[ 5 ]登陆密码修改\n");
			printf("[ 6 ]添加学生成绩\n");
			printf("[ 7 ]删除学生成绩\n");
			printf("[ 8 ]修改学生成绩\n");
			printf("[ 9 ]安全退出\n");
			printf("[ 10]显示使用帮助\n");
			printf("**************************\n");
			break;
					}
				case 11:
					{
						print(Head);
						break;
					}
				default :break;
				}
			}
		}
	    if(strcmp(password,right)!=0||strcmp(name,name2)!=0)
		{
			i++;
			if(i<=2)printf("密码或用户名输入错误，你还有%d次机会\n",M-i);
			if(i==3)
			{
				printf("机会用完了,即将退出登陆界面,再见!\n");
				break;
			}
			printf("请输入用户名 :");
	        scanf("%s",name2);
			printf("请输入登陆密码 :");
			scanf("%s",password);
		}
	}
	return 0;
}
void modify(char *rightmm)//修改密码
{
	char test[15];
	char right2[20];
	printf("请输入原有密码 :");
	scanf("%s",test);
	if(strcmp(test,rightmm)==0)
	{
		printf("请输入新密码 :");
		scanf("%s",right2);
		if((fp=fopen("登陆密码.txt","w"))==NULL)
		{
			printf("无法打开此文件\n");
			exit(0);
		}
		rewind(fp);
		fputs(right2,fp);
		fclose(fp);
		printf("修改密码成功!\n");
	}
	else printf("密码错误，不可更改密码");
}
void changecolor()//换颜色
{
	char n,m;
	char command[9]="color 07";
	printf("0=黑色\n");
	printf("1=蓝色\n");
	printf("2=绿色\n");
	printf("3=湖蓝色\n");
	printf("4=红色\n");
	printf("5=紫色\n");
    printf("6=黄色\n");
    printf("7=白色\n");
    printf("8=灰色\n");
    printf("请选择背景颜色修改为 :");
	getchar();
	scanf("%c",&n);
    printf("请选择字体颜色修改为 :");
	getchar();
	scanf("%c",&m);
	command[6]=n;
	command[7]=m;
	printf("    更换成功！  \n");
	system(command);
}
STUDENT *Studentbank(STUDENT *head,int num)//录入学生信息
{
	int choice,i=1;
	STUDENT *p,*p2;
	printf("请选择学生信息录入方式(【1】从文件中调入/【2】手动输入):");
	//getchar();
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		{
			fp3=fopen("学生信息录入表.txt","r");
			savetofile(head,fp3);
			break;
		}
	case 2:
		{
			return perinput(head);
			break;
		}
	default :
		{
			printf("对不起，无法识别该操作！");
			break;
		}
	}
}
STUDENT *perinput(STUDENT *head1)//人工输入学生信息
{
	STUDENT *p,*p2;	
	char xishou;
	int loop2=1;
	p=p2=(STUDENT *)malloc(LED);
	printf("请输入学生姓名:");
	scanf("%s",p->name);
	printf("请输入学生性别(0表示男，1表示女):");
	scanf("%d",&p->sex);
	printf("请输入学生所属民族:");
	scanf("%s",p->nation);
	printf("请输入学生年龄:");
	scanf("%d",&p->old);
	printf("请输入学生家庭住址:");
	scanf("%s",p->address);
	//getchar();
	printf("请（以,相隔）输入学生的四门成绩（线性代数,英语,数学,C语言）:");
	//getchar();
	scanf("%d,%d,%d,%d",&p->lial,&p->English,&p->math,&p->Clang);
	p->allscore=p->lial+p->English+p->math+p->Clang;
	head1=NULL;
	while(loop2&&n<N)
	{
	printf("是否继续录入【Y/N】:");
	getchar();
	xishou=getchar();
	if(xishou=='Y'||xishou=='y')
	{
		if(n==1)head1=p;
		else p2->next=p;
		p2=p;
		p=(STUDENT *)malloc(LED);
		printf("请输入学生姓名:");
	    scanf("%s",p->name);
    	printf("请输入学生性别:");
     	scanf("%d",&p->sex);
    	printf("请输入学生所属民族:");
    	scanf("%s",p->nation);
		printf("请输入学生年龄:");
    	scanf("%d",&p->old);
    	printf("请输入学生家庭住址:");
    	scanf("%s",p->address);
    	printf("请（以,相隔）输入学生的四门成绩（线性代数,英语,数学,C语言）:");
    	scanf("%d,%d,%d,%d",&p->lial,&p->English,&p->math,&p->Clang);
		p->allscore=p->lial+p->English+p->math+p->Clang;
		n++;
	}
	else 
	{
		if(head1==NULL)
		{
			head1=p;
			p->next=NULL;
		}
		break;
	}
	}
	if(p!=head1)
	{
	p2->next=p;
	p2=p;
	p2->next=NULL;
	}
	return head1;
}
void findscore(STUDENT *head2)//查找
{
	STUDENT *p=head2;
	char name[20];
	printf("请输入你所要查找学生的姓名:");
	scanf("%s",name);
	printf("信息成绩如下\n");
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			printf("姓名  性别  民族   年龄   住址   成绩（线性代数,英语,数学,C语言）总成绩\n");
			printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		    break;
		}
		p=p->next;
	}
	if(p==NULL)printf("无此学生成绩\n\n");
}
/*	printf("姓名  性别  民族   年龄   住址   成绩（线性代数,英语,数学,C语言）总成绩\n");
	while(p!=NULL)
	{
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%26d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		p=p->next;
	}
*/
void savetofile(STUDENT *head3,FILE *fp4)//文件导入信息
{
	STUDENT *p=head3;
	if(fgetc(fp4)==EOF)printf("文件中还未导入过数据\n");
	else 
	{
		while(fgetc(fp4)!=EOF)
		{
			p=(STUDENT *)malloc(LED);
			fscanf(fp4,"%19s",p->name);
			fscanf(fp4,"%d",&p->sex);
			fscanf(fp4,"%10s",p->nation);
			fscanf(fp4,"%d",&p->old);
			fscanf(fp4,"%50s",p->address);
			fscanf(fp4,"%d",&p->lial);
			fscanf(fp4,"%d",&p->English);
			fscanf(fp4,"%d",&p->math);
			fscanf(fp4,"%d",&p->Clang);
			fscanf(fp4,"%d",&p->allscore);
			
		    printf("%s,%d,%s,%d,%s,%d,%d,%d,%d,%d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
			p=p->next;
		}
	}
}
void addscore(STUDENT *head4)//添加成绩
{
	STUDENT *p=head4,*p2,*newp;
	char name[20];
	printf("请输入所要添加学生姓名:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)break;
		p=p->next;
	}
	if(p!=NULL)printf("已存在此学生成绩,不可添加\n");
	else 
	{
		newp=(STUDENT *)malloc(LED);
		strcpy(newp->name,name);
    	printf("请输入学生性别:");
     	scanf("%d",&newp->sex);
    	printf("请输入学生所属民族:");
    	scanf("%s",newp->nation);
		printf("请输入学生年龄:");
    	scanf("%d",&newp->old);
    	printf("请输入学生家庭住址:");
    	scanf("%s",newp->address);
    	printf("请（以,相隔）输入学生的四门成绩（线性代数,英语,数学,C语言）:");
    	scanf("%d,%d,%d,%d",&newp->lial,&newp->English,&newp->math,&newp->Clang);
		newp->allscore=newp->lial+newp->English+newp->math+newp->Clang;
		p=head4;
		while(p!=NULL)
		{
			p=p->next;
			if(p!=NULL)
			  if(p->next==NULL)p2=p;
		}
		if(head4->next!=NULL)
		{
			p2->next=newp;
			p2=newp;
			newp->next=p;
		}
		else 
		{
			head4->next=newp;
			newp->next=p;
		}
	}
}
void print(STUDENT *head5)//所有人成绩显示
{
	STUDENT *p=head5;
	printf("姓名  性别  民族   年龄   住址   成绩（线性代数,英语,数学,C语言）总成绩\n");
	while(p!=NULL)
	{
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		p=p->next;
	}
}
void deletescore(STUDENT *head6)//删除学生成绩
{
	STUDENT *p=head6,*p2,*p3,*p4;
	char name[20],xishou;
	printf("请输入你所要删除成绩的学生姓名:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)break;
		p=p->next;
	}
	if(p==NULL)printf("抱歉,没有找到该学生成绩,不存在此学生成绩\n");
	else 
	{
		printf("姓名  性别  民族   年龄   住址   成绩（线性代数,英语,数学,C语言）总成绩\n");
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
        printf("该生信息如上，请核实确定删除[Y/N]:");
		getchar();
		xishou=getchar();
	    if(xishou=='Y'||xishou=='y')
		{
			p=head6;
			while(p!=NULL)
			{
				p3=p->next;
				if(p3!=NULL)
				  if(strcmp(p3->name,name)==0)p2=p;
				if(strcmp(p->name,name)==0)
				{
					p4=p;
					break;
				}
				p=p->next;
			}
			if(p4==head6)
			{
				head6=p4->next;
			}
		    else p2->next=p->next;
			printf("删除成功\n");
		}
		else printf("每一份成绩都重要,少点粗心,我们就少打一点代码啊\n");

	}
}