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
struct stud_node* read(struct stud_node *head);  //读取文件资料 
  	void record(struct stud_node *head);             //记录 
int menu();                  //菜单 
	struct stud_node * del(struct stud_node *head);                    //删除	 
	struct stud_node * insert(struct stud_node *head);                   //添加 
	struct stud_node * change(struct stud_node *head);                   //修改
void inquiry(struct stud_node *head);                 //查询
    void reading(struct stud_node *head);               //全数据 
    void num_rearch(struct stud_node *head);           //学号查找 
    void sub_rearch(struct stud_node *head);           //科目查找 
    void name_rearch(struct stud_node *head);          //姓名查找 
    void maxmin_rearch(struct stud_node *head);        //某科最值查找
	void good_rearch(struct stud_node *head);          //某科优秀率 
struct stud_node *sort(struct stud_node *head);						//排序 
  	struct stud_node *sort_text(struct stud_node *head);  			//考试排序
	struct stud_node *sort_total(struct stud_node *head);			//总评排序 
int main()
{
  int n=1;                  //菜单功能
    struct stud_node *head;
    head=NULL; 
    head=read(head);
while(n)
{
	  n=menu(); 
	  switch(n)
	  {
	  	 		case 0:	printf("\n||==============================================||\n");
		 		printf("||欢迎下次临幸本功能~o( =∩ω∩= )m~~~さようなら||\n");
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
 	printf("<0>退出系统\n");                           //√ 
 	printf("<1>学生成绩信息的添加\n");					//√ 
 	printf("<2>学生成绩信息的删除\n");					//√ 
 	printf("<3>学生成绩信息的修改\n");					//√ 
 	printf("<4>查询系统\n");                          //√
	printf("<5>排序系统\n");      						//√
	printf("<6>存入文件\n");						 //√ 
 	printf("请问您需要执行什么功能");
 	scanf("%d",&n);
 	return n;
 }
void inquiry(struct stud_node *head)
{
	int n=1;
		 while(n)
{
	printf("<0>退出查询系统\n");                    //√ 
	printf("<1>学号查询\n");                        //√ 
	printf("<2>姓名查询\n");                       //√ 
	printf("<3>课程名查询\n");                     //√ 
	printf("<4>某科最高和最低分\n");              //√ 
	printf("<5>某科优秀率及不及格率\n");             //√ 
	printf("<6>查看全数据\n");                      //√ 
	 printf("请问您需要执行什么功能");
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
		printf("读取机密中\n");
	if((fp=fopen("student_data.txt","r"))==NULL)
	{
		printf("没有机密！坑啊!!\n");
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
	printf("!读取成功!\n");
	return head;
}

void reading(struct stud_node *head)
{
	struct stud_node *p;
	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
 	printf("学号:");
 	scanf("%d",&n);
 	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
 	printf("姓名:");
 	scanf("%s",name);
 	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
 	printf("科目:");
 	scanf("%s",subject);
 	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
	printf("请问您要找哪科的最值?:");
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
	printf("未知科目!!\n");
	else
	{
		for(p=head;p!=NULL;p=p->next)
		{
			if(!strcmp(p->subject,sub))
			{
				if(p->total_score==max)
				{
					printf("最高分学生信息：\n");
						printf("%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
				}
				if(min==p->total_score)
				{
					printf("最低分学生信息:\n");
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
	printf("请问您要找哪科的优秀率及不及格率?:");
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
	printf("未知科目!!\n");
	else
{
	gr=(float)good/(float)count;
	br=(float)bad/(float)count;
	printf("%s优秀率:%.1f,不及格率:%.1f\n",sub,gr,br);
}
}

struct stud_node *sort(struct stud_node *head)
{
	int n=1;
	while(n)
	{
	printf("<0>退出排序系统\n");			//√ 
	printf("<1>考试成绩排序\n");			//√ 
	printf("<2>总评成绩排序\n"); 			//√ 
	printf("您需要怎样的操作?");
	scanf("%d",&n);
	switch(n)
	{
		case 0:break;
		case 1:head=sort_text(head);break;
		case 2:head=sort_total(head);break;
		default:printf("什么骚操作，无法识别!!!凸(艹皿艹 )\n");break;
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
	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
	printf("请输入您要添加的信息:?\n");
	printf("学号(0终止):");
	scanf("%d",&num);
	while(num)
	{
		p1=(struct stud_node*)malloc(sizeof(struct stud_node));
		printf("名字 科目 平时成绩 考试成绩 实验成绩：\n");
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
			printf("学号(0终止):");
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
		printf("没有任何记录in here o(╥﹏╥)o\n");
		return head;
	}
	printf("请问您要删除哪个学生的数据？");
	printf("学号+姓名(例:2233 张三)");
	scanf("%d %s",&num,name);
	int count=0;
	struct stud_node *p,*p2;
	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
 		printf("请问您想删除哪个科目数据?\n");
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
				printf("删除成功，~o( =∩ω∩= )m大概。。自己看\n");
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
		printf("没有任何记录in hereo(╥﹏╥)o\n");
		return head;
	}
	printf("请问您要修改哪个学生的数据？\n");
	printf("学号+姓名+科目(例:2233 张三 程序设计)");
	scanf("%d %s %s",&num,name,sub);
	int count=0;
	struct stud_node *p;
	printf("学号 姓名 科目 平时成绩 实验成绩 考试成绩 总成绩\n");
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
 		printf("请修改该生的平时成绩 实验成绩 考试成绩!\n");
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
	printf("看样纸应该修改成功了..\n");
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
		printf("已建立新文本!\n");
	}
	while(p!=NULL)
	{
		fprintf(fp,"%d %s %s\t%.1f\t%.1f\t%.1f\t%.1f\n",p->num,p->name,p->subject,p->nor_score,p->ex_score,p->text_score,p->total_score);
		p=p->next;
	}
	printf("已缓存为'studen_data.txt\n'");
}
