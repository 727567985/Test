#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct stud_node
{ 
int num; 
char name[20]; 
char subject[20];
float nor_score;
float ex_score;
float text_score; 
float total_score; 
struct stud_node *next; 
};
struct stud_node* read(struct stud_node *head);  //��ȡ�ļ����� 
  	void record(struct stud_node *head);             //��¼ 
int menu();                  //�˵� 
	struct stud_node * del(struct stud_node *head);                    //ɾ��	 
	struct stud_node * insert(struct stud_node *head);                   //��� 
	struct stud_node * change(struct stud_node *head);                   //�޸�
void inquiry(struct stud_node *head);                 //��ѯ
    void reading(struct stud_node *head);               //ȫ���� 
    void num_rearch(struct stud_node *head);           //ѧ�Ų��� 
    void sub_rearch(struct stud_node *head);           //��Ŀ���� 
    void name_rearch(struct stud_node *head);          //�������� 
    void maxmin_rearch(struct stud_node *head);        //ĳ����ֵ����
	void good_rearch(struct stud_node *head);          //ĳ�������� 
struct stud_node *sort(struct stud_node *head);						//���� 
  	struct stud_node *sort_text(struct stud_node *head);  			//��������
	struct stud_node *sort_total(struct stud_node *head);			//�������� 
int main()
{
  int n=1;                  //�˵�����
    struct stud_node *head;
    head=NULL; 
    head=read(head);
while(n)
{
	  n=menu(); 
	  switch(n)
	  {
	  	 		case 0:	printf("\n||==============================================||\n");
		 		printf("||��ӭ�´����ұ�����~o( =�ɦء�= )m~~~���褦�ʤ�||\n");
				printf("||==============================================||\n");break;
		case 1:head=insert(head);break;					
		case 2:head=del(head);break;
 		case 3:head=change(head);break;
 		case 4:inquiry(head);break;    
 		case 5:head=sort(head);break;
 		case 6:record(head);break;
 		default:printf("error!!!!!\n");break;
	  }
}
  return 0;
 }
 
 
 int menu()
 {
 	int n;
 	printf("<0>�˳�ϵͳ\n");                           //�� 
 	printf("<1>ѧ���ɼ���Ϣ�����\n");					//�� 
 	printf("<2>ѧ���ɼ���Ϣ��ɾ��\n");					//�� 
 	printf("<3>ѧ���ɼ���Ϣ���޸�\n");					//�� 
 	printf("<4>��ѯϵͳ\n");                          //��
	printf("<5>����ϵͳ\n");      						//��
	printf("<6>�����ļ�\n");						 //�� 
 	printf("��������Ҫִ��ʲô����");
 	scanf("%d",&n);
 	return n;
 }
void inquiry(struct stud_node *head)
{
	int n=1;
		 while(n)
{
	printf("<0>�˳���ѯϵͳ\n");                    //�� 
	printf("<1>ѧ�Ų�ѯ\n");                        //�� 
	printf("<2>������ѯ\n");                       //�� 
	printf("<3>�γ�����ѯ\n");                     //�� 
	printf("<4>ĳ����ߺ���ͷ�\n");              //�� 
	printf("<5>ĳ�������ʼ���������\n");             //�� 
	printf("<6>�鿴ȫ����\n");                      //�� 
	 printf("��������Ҫִ��ʲô����");
	scanf("%d",&n);
	  switch(n)
	  {
	  	 		case 0:break;
		case 1:num_rearch(head);break;
		case 2:name_rearch(head);break;
  		case 3:sub_rearch(head);break;
 		case 4:maxmin_rearch(head);break;    
 		case 5:good_rearch(head);break;
 		case 6:reading(head);break;
 		default:printf("error!!!!!\n");break;
	  } 
}
}

struct stud_node* read(struct stud_node *head)
{
	FILE *fp;
	int i=0;
		printf("��ȡ������\n");
	if((fp=fopen("student_data.txt","r"))==NULL)
	{
		printf("û�л��ܣ��Ӱ�!!\n");
		return NULL;
	}
	struct stud_node *tail,*p;
	while(!feof(fp))
	{
		p=(struct stud_node*)malloc(sizeof(struct stud_node));
		fscanf(fp,"%d %s %s %f %f %f %f",&p->num,&p->name,&p->subject,&p->nor_score,&p->ex_score,&p->text_score,&p->total_score);
		p->next=NULL;
		if(i==0)
		{
			head=tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}i++;
	}
	fclose(fp);
	printf("!��ȡ�ɹ�!\n");
	return head;
}

void reading(struct stud_node *head)
{
	struct stud_node *p;
	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
       printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score); 
}
}

 void num_rearch(struct stud_node *head)
 {
 		int n,count=0;
 	struct stud_node *p;
 	p=head;
 	printf("ѧ��:");
 	scanf("%d",&n);
 	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
		if(p->num==n)
		{
		printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		count++; 		
		}
	}
	if(count==0)
	{
	printf("No information!\n");
	}
		}       

void name_rearch(struct stud_node *head)
{
	 		int count=0;
	 		char name[20]={0};
 	struct stud_node *p;
 	p=head;
 	printf("����:");
 	scanf("%s",name);
 	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
		if(!strcmp(p->name,name))
		{
		printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		count++; 		
		}
	}
	if(count==0)
	{
	printf("No information!\n");
	}
}

void sub_rearch(struct stud_node *head)
{
	 		int count=0;
	 		char subject[20]={0};
 	struct stud_node *p;
 	p=head;
 	printf("��Ŀ:");
 	scanf("%s",subject);
 	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
		if(!strcmp(p->subject,subject))
		{
		printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		count++; 		
		}
	}
	if(count==0)
	{
	printf("No information!\n");
	}
}

void maxmin_rearch(struct stud_node *head)
{
	int max=-1,min=1000;
	char sub[20];
	struct stud_node *p;
	int count=0;
	printf("������Ҫ���ĿƵ���ֵ?:");
	scanf("%s",sub);
	for(p=head;p!=NULL;p=p->next)
	{
		if(!strcmp(p->subject,sub))
		{
			if(max<=p->total_score)
			max=p->total_score;
			if(min>=p->total_score)
			min=p->total_score;
			count++;
		}
	}
	if(count==0)
	printf("δ֪��Ŀ!!\n");
	else
	{
		for(p=head;p!=NULL;p=p->next)
		{
			if(!strcmp(p->subject,sub))
			{
				if(p->total_score==max)
				{
					printf("��߷�ѧ����Ϣ��\n");
						printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
				}
				if(min==p->total_score)
				{
					printf("��ͷ�ѧ����Ϣ:\n");
						printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
				}
			}
		}
	}
}

void good_rearch(struct stud_node *head)
{
	char sub[20];
	struct stud_node *p;
	int count=0;
	int good=0,bad=0;
	float gr,br;
	printf("������Ҫ���ĿƵ������ʼ���������?:");
	scanf("%s",sub);
	for(p=head;p!=NULL;p=p->next)
	{
		if(!strcmp(p->subject,sub))
		{
 if(p->total_score<60)
 bad++;
 if(p->total_score>=90)
 good++;
 count++;
		}
	}
	if(count==0)
	printf("δ֪��Ŀ!!\n");
	else
{
	gr=(float)good/(float)count;
	br=(float)bad/(float)count;
	printf("%s������:%.1f,��������:%.1f\n",sub,gr,br);
}
}

struct stud_node *sort(struct stud_node *head)
{
	int n=1;
	while(n)
	{
	printf("<0>�˳�����ϵͳ\n");			//�� 
	printf("<1>���Գɼ�����\n");			//�� 
	printf("<2>�����ɼ�����\n"); 			//�� 
	printf("����Ҫ�����Ĳ���?");
	scanf("%d",&n);
	switch(n)
	{
		case 0:break;
		case 1:head=sort_text(head);break;
		case 2:head=sort_total(head);break;
		default:printf("ʲôɧ�������޷�ʶ��!!!͹(ܳ��ܳ )\n");break;
	}
	}
	return head;
}

struct stud_node *sort_text(struct stud_node *head)
{
	struct stud_node *p1,*p2,*temp;
	struct stud_node *p;
	int count=1;
	while(count)
	{
		count=0;
		p2=head->next;
		if(head->text_score<p2->text_score)
		{
			temp=head;
			head=p2;
			p2=temp;
			temp->next=head->next;
			head->next=p2;
			p2->next=temp->next;
			count++;
		}
		for(p1=head->next;p1->next!=NULL;p1=p1->next)
		{
			p2=p1->next;
			if(p1->text_score<p2->text_score)
			{
			temp=p1;
			p1=p2;
			p2=temp;
			temp->next=p1->next;
			p1->next=p2;
			p2->next=temp->next;
			count++;
			}
		}
	}
	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
       printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score); 
}
return head;
}

struct stud_node *sort_total(struct stud_node *head)
{
	struct stud_node *p1,*p2,*temp;
	struct stud_node *p;
	int count=1;
	while(count)
	{
		count=0;
		p2=head->next;
		if(head->total_score<p2->total_score)
		{
			temp=head;
			head=p2;
			p2=temp;
			temp->next=head->next;
			head->next=p2;
			p2->next=temp->next;
			count++;
		}
		for(p1=head->next;p1->next!=NULL;p1=p1->next)
		{
			p2=p1->next;
			if(p1->total_score<p2->total_score)
			{
			temp=p1;
			p1=p2;
			p2=temp;
			temp->next=p1->next;
			p1->next=p2;
			p2->next=temp->next;
			count++;
			}
		}
	}
	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p !=NULL;p=p->next)
	{
       printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score); 
}
return head;
}

struct stud_node * insert(struct stud_node *head)
{
	struct stud_node *p,*p1,*p2;
	int num,count=0;
	char name[20],sub[20];
	float ns,es,ts,tos;
	printf("��������Ҫ��ӵ���Ϣ:?\n");
	printf("ѧ��(0��ֹ):");
	scanf("%d",&num);
	while(num)
	{
		p1=(struct stud_node*)malloc(sizeof(struct stud_node));
		printf("���� ��Ŀ ƽʱ�ɼ� ���Գɼ� ʵ��ɼ���\n");
		scanf("%s%s%f%f%f",name,sub,&ns,&ts,&es);
		tos=ns*0.2+es*0.25+ts*0.55;
		p1->num=num;
		strcpy(p1->name,name);
		strcpy(p1->subject,sub);
		p1->nor_score=ns;
		p1->text_score=ts;
		p1->ex_score=es;
		p1->total_score=tos;
		p1->next=NULL;
		if(count==0)
		{
			p=p2=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
		count++;
			printf("ѧ��(0��ֹ):");
	scanf("%d",&num);
	 }
	  if(head==NULL)
	  head=p;
	  else
	  {
	  	for(p2=head;p2->next!=NULL;p2=p2->next);
	  	p2->next=p;
	  }
	  return head;
}

struct stud_node * del(struct stud_node *head)
{
	int num;
	char name[20],sub[20];
	float ns,es,ts,tos;
	if(head==NULL)
	{
		printf("û���κμ�¼in here o(�i�n�i)o\n");
		return head;
	}
	printf("������Ҫɾ���ĸ�ѧ�������ݣ�");
	printf("ѧ��+����(��:2233 ����)");
	scanf("%d %s",&num,name);
	int count=0;
	struct stud_node *p,*p2;
	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->num==num&&!strcmp(p->name,name))
		{
			 printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
			 count++;
		}
	}
	if(count==0)
 	printf("Not found!!\n");
 	else
 	{
 		printf("��������ɾ���ĸ���Ŀ����?\n");
 		scanf("%s",sub);
	 		if(head->num==num&&!strcmp(head->name,name)&&!strcmp(head->subject,sub))
			head=head->next;
	else
	{	
	 	for(p=head;p!=NULL;p=p->next)
	{


				p2=p->next;
		if(p2->num==num&&!strcmp(p2->name,name)&&!strcmp(p2->subject,sub))
		{
				p->next=p2->next;
		}
			}
		
	}
				printf("ɾ���ɹ���~o( =�ɦء�= )m��š����Լ���\n");
	}
	return head;
}

struct stud_node * change(struct stud_node *head)
{
		int num,n=0;
			float ns,es,ts,tos;
	char name[20],sub[20];
	if(head==NULL)
	{
		printf("û���κμ�¼in hereo(�i�n�i)o\n");
		return head;
	}
	printf("������Ҫ�޸��ĸ�ѧ�������ݣ�\n");
	printf("ѧ��+����+��Ŀ(��:2233 ���� �������)");
	scanf("%d %s %s",&num,name,sub);
	int count=0;
	struct stud_node *p;
	printf("ѧ�� ���� ��Ŀ ƽʱ�ɼ� ʵ��ɼ� ���Գɼ� �ܳɼ�\n");
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->num==num&&!strcmp(p->name,name)&&!strcmp(p->subject,sub))
		{
			 printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
			 count++;
		}
	}
	if(count==0)
 	printf("Not found!!\n");
 	else
 	{
 		printf("���޸ĸ�����ƽʱ�ɼ� ʵ��ɼ� ���Գɼ�!\n");
 		scanf("%f%f%f",&ns,&es,&ts);
	tos=ns*0.2+es*0.25+ts*0.55;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->num==num&&!strcmp(p->name,name)&&!strcmp(p->subject,sub))
		{
			p->nor_score=ns;
			p->text_score=ts;
			p->ex_score=es;
			p->total_score=tos;
			printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		}
	}
	printf("����ֽӦ���޸ĳɹ���..\n");
	 }
	 return head;
}

void record(struct stud_node *head)
{
	FILE *fp;
	struct stud_node *p;
	p=head;
	if((fp=fopen("student_data.txt","w"))==NULL)
	{
		printf("�ѽ������ı�!\n");
	}
	while(p!=NULL)
	{
		fprintf(fp,"%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		p=p->next;
	}
	printf("�ѻ���Ϊ'studen_data.txt\n'");
}
