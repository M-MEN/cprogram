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
	int sex;         //0��ʾ�У�1��ʾŮ
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
void changecolor();//����ɫ
void modify(char *rightmm);//�޸����룬Ҫ���ļ�
STUDENT *Studentbank(STUDENT *head,int num);//¼��ѧ����Ϣ
STUDENT *perinput(STUDENT *head1);//�˹�����ѧ����Ϣ
void savetofile(STUDENT *head3,FILE *fp4);//�ļ�������Ϣ
void findscore(STUDENT *head2);//����
void addscore(STUDENT *head4);//��ӳɼ�
void print(STUDENT *head5);//�����˳ɼ���ʾ
void deletescore(STUDENT *head6);//ɾ��ѧ���ɼ�
FILE *fp,*fp2,*fp3;	
STUDENT *Head;
int n=1;//������
int main()
{

	int l=1,i=0,choice,loop=1;
	char password[10],name[15],name2[15];
	char right[10];
	fp2=fopen("�û���.txt","r");
	fgets(name,10,fp2);
	fp=fopen("��½����.txt","r");
	fgets(right,10,fp);
	fclose(fp);
	fclose(fp2);
	printf("�������û��� :");
	scanf("%s",name2);
	printf("�������½���� :");
	scanf("%s",password);
	while(l)
	{
		if(strcmp(password,right)==0&&strcmp(name,name2)==0)
		{
			printf("��¼�ɹ�,��ӭ����ѧ���ɼ�����ϵͳ\n");
			l=0;
		    printf("*********ʹ�ð���*********\n");
			printf("[ 1 ]���ı�����ɫ��������ɫ\n");
			printf("[ 2 ]¼��ѧ��������Ϣ\n");
			printf("[ 3 ]��ѯ�ɼ�\n");
			printf("[ 4 ]�ܷ�����\n");
			printf("[ 5 ]��½�����޸�\n");
			printf("[ 6 ]���ѧ���ɼ�\n");
			printf("[ 7 ]ɾ��ѧ���ɼ�\n");
			printf("[ 8 ]�޸�ѧ���ɼ�\n");
			printf("[ 9 ]��ȫ�˳�\n");
			printf("[ 10]��ʾʹ�ð���\n");
			printf("[ 11]�ɼ���ʾ\n");
			printf("**************************\n");
			while(loop)
			{
				printf("��ѡ��һ������ѡ��(1-11):");
				scanf("%d",&choice);
				if(choice<0||choice>11)
				{
					printf("ѡ�����,������ѡ��(1-11):");
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
			printf("*********ʹ�ð���*********\n");
		    printf("[ 1 ]���ı�����ɫ��������ɫ\n");
			printf("[ 2 ]¼��ѧ��������Ϣ\n");
			printf("[ 3 ]��ѯ�ɼ�\n");
			printf("[ 4 ]�ܷ�����\n");
			printf("[ 5 ]��½�����޸�\n");
			printf("[ 6 ]���ѧ���ɼ�\n");
			printf("[ 7 ]ɾ��ѧ���ɼ�\n");
			printf("[ 8 ]�޸�ѧ���ɼ�\n");
			printf("[ 9 ]��ȫ�˳�\n");
			printf("[ 10]��ʾʹ�ð���\n");
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
			if(i<=2)printf("������û�����������㻹��%d�λ���\n",M-i);
			if(i==3)
			{
				printf("����������,�����˳���½����,�ټ�!\n");
				break;
			}
			printf("�������û��� :");
	        scanf("%s",name2);
			printf("�������½���� :");
			scanf("%s",password);
		}
	}
	return 0;
}
void modify(char *rightmm)//�޸�����
{
	char test[15];
	char right2[20];
	printf("������ԭ������ :");
	scanf("%s",test);
	if(strcmp(test,rightmm)==0)
	{
		printf("������������ :");
		scanf("%s",right2);
		if((fp=fopen("��½����.txt","w"))==NULL)
		{
			printf("�޷��򿪴��ļ�\n");
			exit(0);
		}
		rewind(fp);
		fputs(right2,fp);
		fclose(fp);
		printf("�޸�����ɹ�!\n");
	}
	else printf("������󣬲��ɸ�������");
}
void changecolor()//����ɫ
{
	char n,m;
	char command[9]="color 07";
	printf("0=��ɫ\n");
	printf("1=��ɫ\n");
	printf("2=��ɫ\n");
	printf("3=����ɫ\n");
	printf("4=��ɫ\n");
	printf("5=��ɫ\n");
    printf("6=��ɫ\n");
    printf("7=��ɫ\n");
    printf("8=��ɫ\n");
    printf("��ѡ�񱳾���ɫ�޸�Ϊ :");
	getchar();
	scanf("%c",&n);
    printf("��ѡ��������ɫ�޸�Ϊ :");
	getchar();
	scanf("%c",&m);
	command[6]=n;
	command[7]=m;
	printf("    �����ɹ���  \n");
	system(command);
}
STUDENT *Studentbank(STUDENT *head,int num)//¼��ѧ����Ϣ
{
	int choice,i=1;
	STUDENT *p,*p2;
	printf("��ѡ��ѧ����Ϣ¼�뷽ʽ(��1�����ļ��е���/��2���ֶ�����):");
	//getchar();
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		{
			fp3=fopen("ѧ����Ϣ¼���.txt","r");
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
			printf("�Բ����޷�ʶ��ò�����");
			break;
		}
	}
}
STUDENT *perinput(STUDENT *head1)//�˹�����ѧ����Ϣ
{
	STUDENT *p,*p2;	
	char xishou;
	int loop2=1;
	p=p2=(STUDENT *)malloc(LED);
	printf("������ѧ������:");
	scanf("%s",p->name);
	printf("������ѧ���Ա�(0��ʾ�У�1��ʾŮ):");
	scanf("%d",&p->sex);
	printf("������ѧ����������:");
	scanf("%s",p->nation);
	printf("������ѧ������:");
	scanf("%d",&p->old);
	printf("������ѧ����ͥסַ:");
	scanf("%s",p->address);
	//getchar();
	printf("�루��,���������ѧ�������ųɼ������Դ���,Ӣ��,��ѧ,C���ԣ�:");
	//getchar();
	scanf("%d,%d,%d,%d",&p->lial,&p->English,&p->math,&p->Clang);
	p->allscore=p->lial+p->English+p->math+p->Clang;
	head1=NULL;
	while(loop2&&n<N)
	{
	printf("�Ƿ����¼�롾Y/N��:");
	getchar();
	xishou=getchar();
	if(xishou=='Y'||xishou=='y')
	{
		if(n==1)head1=p;
		else p2->next=p;
		p2=p;
		p=(STUDENT *)malloc(LED);
		printf("������ѧ������:");
	    scanf("%s",p->name);
    	printf("������ѧ���Ա�:");
     	scanf("%d",&p->sex);
    	printf("������ѧ����������:");
    	scanf("%s",p->nation);
		printf("������ѧ������:");
    	scanf("%d",&p->old);
    	printf("������ѧ����ͥסַ:");
    	scanf("%s",p->address);
    	printf("�루��,���������ѧ�������ųɼ������Դ���,Ӣ��,��ѧ,C���ԣ�:");
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
void findscore(STUDENT *head2)//����
{
	STUDENT *p=head2;
	char name[20];
	printf("����������Ҫ����ѧ��������:");
	scanf("%s",name);
	printf("��Ϣ�ɼ�����\n");
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			printf("����  �Ա�  ����   ����   סַ   �ɼ������Դ���,Ӣ��,��ѧ,C���ԣ��ܳɼ�\n");
			printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		    break;
		}
		p=p->next;
	}
	if(p==NULL)printf("�޴�ѧ���ɼ�\n\n");
}
/*	printf("����  �Ա�  ����   ����   סַ   �ɼ������Դ���,Ӣ��,��ѧ,C���ԣ��ܳɼ�\n");
	while(p!=NULL)
	{
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%26d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		p=p->next;
	}
*/
void savetofile(STUDENT *head3,FILE *fp4)//�ļ�������Ϣ
{
	STUDENT *p=head3;
	if(fgetc(fp4)==EOF)printf("�ļ��л�δ���������\n");
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
void addscore(STUDENT *head4)//��ӳɼ�
{
	STUDENT *p=head4,*p2,*newp;
	char name[20];
	printf("��������Ҫ���ѧ������:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)break;
		p=p->next;
	}
	if(p!=NULL)printf("�Ѵ��ڴ�ѧ���ɼ�,�������\n");
	else 
	{
		newp=(STUDENT *)malloc(LED);
		strcpy(newp->name,name);
    	printf("������ѧ���Ա�:");
     	scanf("%d",&newp->sex);
    	printf("������ѧ����������:");
    	scanf("%s",newp->nation);
		printf("������ѧ������:");
    	scanf("%d",&newp->old);
    	printf("������ѧ����ͥסַ:");
    	scanf("%s",newp->address);
    	printf("�루��,���������ѧ�������ųɼ������Դ���,Ӣ��,��ѧ,C���ԣ�:");
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
void print(STUDENT *head5)//�����˳ɼ���ʾ
{
	STUDENT *p=head5;
	printf("����  �Ա�  ����   ����   סַ   �ɼ������Դ���,Ӣ��,��ѧ,C���ԣ��ܳɼ�\n");
	while(p!=NULL)
	{
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
		p=p->next;
	}
}
void deletescore(STUDENT *head6)//ɾ��ѧ���ɼ�
{
	STUDENT *p=head6,*p2,*p3,*p4;
	char name[20],xishou;
	printf("����������Ҫɾ���ɼ���ѧ������:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)break;
		p=p->next;
	}
	if(p==NULL)printf("��Ǹ,û���ҵ���ѧ���ɼ�,�����ڴ�ѧ���ɼ�\n");
	else 
	{
		printf("����  �Ա�  ����   ����   סַ   �ɼ������Դ���,Ӣ��,��ѧ,C���ԣ��ܳɼ�\n");
		printf("%s%4d%8s%7d%9s%6d,%d,%d,%d,%21d\n",p->name,p->sex,p->nation,p->old,p->address,p->lial,p->English,p->math,p->Clang,p->allscore);
        printf("������Ϣ���ϣ����ʵȷ��ɾ��[Y/N]:");
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
			printf("ɾ���ɹ�\n");
		}
		else printf("ÿһ�ݳɼ�����Ҫ,�ٵ����,���Ǿ��ٴ�һ����밡\n");

	}
}