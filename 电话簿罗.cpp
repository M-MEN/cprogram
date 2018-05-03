//�绰��
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
};//�绰+������Ϣ�ṹ��
typedef struct phone PHONE;
PHONE *phonebank(PHONE *head,int num);//����(��������)�绰��
void printbank(PHONE *head1);//�����Ϣ����
void phonechange(PHONE *head2);//�޸���Ϣ����
void namechange(PHONE *head3);//�޸���������
void callchange(PHONE *head4);//�޸ĵ绰����
void addphone(PHONE *head5);//����
void searchphone(PHONE *head6);//����
void deletephone(PHONE *head7);//ɾ��
void sortphone(PHONE *head8);//����

int paiduanbank=0;//�Ƿ񴴽��绰�� 
int n=1;//������
int main()
{
	PHONE *Head;
	int chiose,loop=1;
	char xishou;
	printf("*********ʹ�ð���*********\n");
	printf("[ 1 ]�����绰��\n");
	printf("[ 2 ]����绰��\n");
	printf("[ 3 ]������ϵ��\n");//����绰��
	printf("[ 4 ]�޸���ϵ����Ϣ\n");
	printf("[ 5 ]������ϵ��\n");//���������Һ͵绰�Ų���
	printf("[ 6 ]ɾ����ϵ��\n");
	printf("[ 7 ]�绰������\n");
	printf("[ 8 ]��ȫ�˳�\n");
	printf("**************************\n");
	while(loop)
	{
			printf("��ѡ��һ��ѡ��: ");
	        scanf("%d",&chiose);
			if(chiose>8||chiose<1)
			{
				printf("\n�������,�޴�ѡ��,����������(1-8): ");
				scanf("%d",&chiose);
			}
	        switch (chiose)
			{
	         case 1:
				 {
					 if(paiduanbank)
					 {
						 printf("�Ѿ�����,�Ƿ����´���[Y/N] :");
						 getchar();
						 xishou=getchar();
						 if(xishou=='Y'||xishou=='y')Head=phonebank(Head,N);
						 else printf("��ʹ�õ�ǰ�绰��");
					 }
					 else Head=phonebank(Head,N);
					 break;
				 }
	         case 2:
				 {
					 if(!paiduanbank)
					 {
						 printf("����ϵ�ˣ����ȴ����洢��ϵ��\n");
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
				 printf("�������!");
				 loop=0;
				 break;
			}
			 default :break;
			}
	}
	return 0;
}
PHONE *phonebank(PHONE *head,int num)//��¼��ϵ�˵绰������
{
	struct phone *newp,*p2;
	int i;
	char xishou,xishou2;
	printf("��ʾ : �洢�绰����������������!\n");
	//printf("��������ϵ�˵������Լ��绰(������绰����ʱ,�Զ������): \n");
	p2=newp=(struct phone *)malloc(LED);//newp=(struct phone *)calloc(LED,100);
	printf("��������ϵ�˵����� : ");
    scanf("%s",newp->name);
	printf("��������ϵ�˵ĵ绰 : ");
    scanf("%s",newp->call);
	//scanf("%s,%s",newp->name,newp->call);
	head=NULL;	
	for(i=1;i<=N;i++)
	{
		printf("�Ƿ�����洢[Y/N]:");
		getchar();
		xishou2=getchar();
		if(xishou2=='Y'||xishou2=='y')
		{
			//printf("������洢:\n");
			if(n==1)head=newp;
			else p2->next=newp;
			p2=newp;
			newp=(struct phone *)malloc(LED);
			printf("��������ϵ�˵����� : ");
			scanf("%s",newp->name);
	        printf("��������ϵ�˵ĵ绰 : ");
	        scanf("%s",newp->call);
			//scanf("%s,%s",newp->name,newp->call);
			n++;
		}
		else if(xishou2=='N'||xishou2=='n')
		{
			printf("�˴β������ɴ洢%d���绰��ȷ����ֹ��[Y/N]:",N-i+1);
			getchar();
			xishou=getchar();
			if(xishou=='Y'||xishou=='y')
			{
				printf("�Ѿ���ֹ\n");
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
void printbank(PHONE *head1)//���
{
	PHONE *p=head1;
	int i=1;
	printf("\n�Ѵ洢��Ϣ���� \n\n");
	printf("���      ����      �绰    \n");
	while(p!=NULL)
		{
			printf("%3d%12s%9s\n",i,p->name,p->call);
			p=p->next;
			i++;
		}
		
}
void phonechange(PHONE *head2)//�޸�
{
	char xishou;
	printf("����Ҫ�޸�ĳ��ϵ������[Y],����Ҫ�޸�ĳ��ϵ�˵绰[N]:");
	getchar();
	xishou=getchar();
	if(xishou=='Y'||xishou=='y') namechange(head2);
	else callchange(head2);
}
void namechange(PHONE *head3)
{
	PHONE *p=head3;
	char newname[20],oldname[20];
	printf("����������Ҫ�޸ĵ���ϵ������:");
	scanf("%s",oldname);
	while(p!=NULL)
	{
		if(strcmp(p->name,oldname)==0)
		{
			printf("������������:");
	        scanf("%s",newname);
			strcpy(p->name,newname);
			printf("�޸������ɹ�\n");
			break;
		}
		p=p->next;
	}
	if(p==NULL)printf("�����ڴ�����\n");
}
void callchange(PHONE *head4)
{
	PHONE *p=head4;
	char newcall[20],oldcall[20];
	printf("����������Ҫ�޸ĵ���ϵ�˵绰:");
	scanf("%s",oldcall);
	while(p!=NULL)
	{
		if(strcmp(p->call,oldcall)==0)
		{
			printf("�������µ绰:");
	        scanf("%s",newcall);
			strcpy(p->call,newcall);
			printf("�޸ĵ绰�ɹ�\n");
			break;
		}
		p=p->next;
	}
	if(p==NULL)printf("�����ڴ˵绰");
}
void addphone(PHONE *head5)//����
{
	PHONE *p=head5,*newh,*p3;
	int loop2=1;
	newh=(struct phone *)malloc(LED);
	printf("����������ϵ������ :");	
	scanf("%s",newh->name);
	printf("����������ϵ�˵绰 :");
	scanf("%s",newh->call);
	while(p!=NULL)
	{
		p3=p;
		if(strcmp(newh->call,p->call)==0)
		{printf("�˺����Ѵ��ڣ����϶��ǼǴ�����ˣ�\n");
		break;}
		if(strcmp(newh->name,p->name)==0)
		{printf("����ϵ�������Ѵ���(����������ͬ���룬�����֣���: luo2)\n");
		break;}
		p=p->next;
	}
	if(p==NULL)
	{
		p3->next=newh;
		p3=newh;
		newh->next=p;
		printf("���ӳɹ�\n");
	}
}
void searchphone(PHONE *head6)//����
{
	PHONE *p=head6,*p2;
	p2=(struct phone *)malloc(LED);
	printf("��������Ҫ���ҵ����� :");
	scanf("%s",p2->name);
	while(p!=NULL)
	{
		if(strcmp(p2->name,p->name)==0)
		{
			printf("����: %s,�绰: %s\n",p->name,p->call);
			break;
			p=p->next;
		}
	}
	if(p==NULL)printf("�绰����û�д洢������Ϣ\n");
}
void deletephone(PHONE *head7)//ɾ��
{
	PHONE *p=head7,*p3;
	char name[20];
	printf("����������Ҫɾ������ϵ������ :");
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
			printf("ɾ���ɹ�\n");
			n=n-1;
			break;	
		}
	}
	if(p==NULL)printf("�绰����û�д洢������Ϣ\n");
}
void sortphone(PHONE *head8)
{
	PHONE *p,*p2,*p3;
	char t[20];
	int n1,n2,choice;
	printf("��ѡ������ʽ:��1.��������ĸ����2.������������");
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
	printf("����ɹ�\n");
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
	printf("����ɹ�\n");
	break;
	}
	default :break;
	}
}