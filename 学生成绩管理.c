#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#define N 100 
typedef struct student {
	char studentID[11];
	char name[10] ;
	char score[6][4] ;
	int total;
} STUDENT;
struct link {
	STUDENT date ;
	struct link *next;
	struct link *prev;
};
int m,n;
char f[6][10];
void input(); //录入每个学生的学号.姓名和各科考试成绩
void course(struct link*ps ); //计算每门课程的总分和平均分
void stdudent(struct link*ps ); //计算每个学生的总分和平均分
void descending(struct link*ps );//按每个学生的总分由高到低排出名次表
void ascending(struct link*ps );//按每个学生的总分由低到高排出名次表
void number(struct link*ps  ) ;//按学号由小到大排出成绩表
void addwithremove (struct link*ps  ) ;//添加和删除学生信息
void searchnumber (struct link*ps );//按学号查询学生排名及其考试成绩
void searchname (struct link*ps ) ;//按姓名查询学生排名及其考试成绩
void statistic(struct link*ps ) ;//统计不同类别内学生人数和情况
void list (struct link*ps  );//输出每个学生的信息
void wfile(struct link*ps );// 将学生信息写入文件
void rfile (); //将信息从文件中读出
void exits();//退出
void help () ; //帮助
void freememory(struct link*ps);//归还空间
void add (struct link*ps  ); //添加学生信息
void del( struct link*ps ); // 删除学生信息
void login();//界面信息 
void revise(struct link*ps );//修改学生信息 
void logins();//用户须知 
int main() {
	login();
	Sleep (2000);
	system("CLS");
	logins();
	Sleep (4000);
	system("CLS");
	int a,n=0;
	printf("\t\t\t ---------------------------------------------- \n");
	printf("\t\t\t|     *****欢迎来到学生成绩管理系统！*****     |\n");
    printf("\t\t\t|----------------------------------------------|\n");
	printf("\t\t\t|          将为您提供以下服务                  |\n");
	printf("\t\t\t|          1.录入学生信息                      |\n");
	printf("\t\t\t|          2.从文件中读取学生信息              |\n");
	printf("\t\t\t|          3.查看功能                          |\n");
	printf("\t\t\t|          0.退出                              |\n");
	printf("\t\t\t ---------------------------------------------- \n");
	printf("请输入您的需求\n");
	scanf("%d",&a);
	system("CLS");
	
	while (a<0||a>3) {
		printf("您的输入有误，请重新选择。\n");
		scanf(" %d",&a);
	}
	
	while (a==3) {
		help()  ;
		printf("请您继续录入信息");
		scanf("%d",&a);
	}
	
	if(a==1) input();
	if(a==2)  rfile ()  ;
	if(a==0)  exits() ;
	return 0;
	
}

void exits() {
		printf("       感谢您的使用");
	exit(0);
}

void stdudent(struct link*ps ) {
	
	int to;
	int i,j;
	float s;
	s=m;
	to=0;
	
	 printf("\t\t\t|-------------------------------------------------------|\n");
	 printf("\t\t\t|        总分	    平均分\n");
	 printf("\t\t\t|-------------------------------------------------------|\n" );
	 
	for(j=0; j<n; j++) {
		printf("\t\t\t|%s",ps->date.name);
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;
		printf("\t%d",to);
		printf("\t%0.2f\n",to/s);
		ps=ps->next;
	}
	 printf("\t\t\t|-------------------------------------------------------|\n" );
	return ;
}




void input() {
	int	i=0,j;
	int next=1;
	int choice;
	char a;
	printf("请输入人数");
	scanf("%d",&n);
	printf("请输入多少门成绩");
	scanf("%d",&m) ;
	printf("请输入要输入成绩的科目\n"); 
	
		for(j=0;j<m;j++)
	{   scanf("%s",f[j]);
	}
	
	struct link *head=NULL;
	struct link  *p=NULL,*q=NULL;
	struct link *l;
	head=(struct link *)malloc(sizeof(struct link));
	p=(struct link *)malloc(sizeof(struct link));
	
	if(p==NULL) {
		printf("NO enough memory!\n");
		exit(1);
	}
	
	if( head==NULL) {
		printf("NO enough memory!\n");
		exit(1);
	}
	
	if(p==NULL)  exit(0);
	head->next=p;
	l=head->next;
	p->prev=head;
	system("CLS");
	
	printf("\t\t\t|--------------------------------------------------------------- \n");
	printf("\t\t\t| 学号      姓名      ");
	
	for(j=0;j<m;j++)
	{  printf  ("%s   ",f[j]);
	} printf("   \n");
	
	printf("\t\t\t|--------------------------------------------------------------- \n");
	
	while(i<n ) {
		printf("\t\t\t|");
		scanf("%s",p->date.studentID);
		scanf("%s",p->date.name);
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
		q=(struct link *)malloc(sizeof(struct link));
		if(q==NULL) {
			printf("NO enough memory!\n");
			exit(1);
		}
		q->prev=p;
		p->next=q;
		p=q;
		i++;
	}
	printf("\t\t\t|--------------------------------------------------------------- \n");
	p->prev->next=NULL;
	printf("\n") ;
	printf("请选择您接下来的操作\n") ;
	help();
	printf("\n") ;
	while(next==1) {
		scanf (" %d",&choice );
		if(choice==2)  { 	system("CLS");course(l )  ;}
		else if(choice==3)  { 	system("CLS");
	stdudent(l ) ;}
		else if(choice==4)    {	system("CLS");  descending(l ) ;}
		else if(choice==5)    {	system("CLS");ascending(l )  ;}
		else if(choice==6)   {	system("CLS"); number(l );}
		else if(choice==7)   	{system("CLS"); addwithremove(l );}
		else if(choice==8)  	{system("CLS"); searchnumber(l );}
		else if(choice==9)    	{
		 system("CLS"); searchname (l ) ;}
		else if(choice==10)     	{system("CLS");statistic(l );}
		else if(choice==11)   	{system("CLS");list(l );}
		else if(choice==12)   	{system("CLS");rfile ();}
		else if(choice==1)  	{system("CLS");input() ;}
		else if(choice==13)  	{system("CLS");wfile(l );}
		else exits();
		printf("请问您还需要其它操作吗,按y或n继续\n");
		scanf(" %c",&a);
		if(a=='y')  {
			next=1;
			printf("请继续选择操作\n");
			help();
		} else next=0;
		l=head->next;
	}
	
	freememory(l) ;
	free(head);
	printf("      感谢您的使用     ");
	return;
	
}
void course(struct link*ps ) {
	
	struct link* q=ps;
	int to;
	int i,j;
	float s;
	s=n;
     printf("\t\t\t|-------------------------------------------------------|\n");
	 printf("\t\t\t|		总分	平均分\n");
	 printf("\t\t\t|-------------------------------------------------------|\n" );	
	for(j=0; j<m; j++) {
		to=0;
		printf  ("\t\t\t|%s   ",f[j]);
		for(i=0; i<n; i++) {
			to=(ps->date.score[j][0]-48)*10+(ps->date.score[j][1]-48)+to;
			ps=ps->next;
		}
		printf("%d",to);
		printf("      %0.2f\n",to/s);
		ps=q;
	}
	
	 printf("\t\t\t|-------------------------------------------------------|\n" );
	 
	return ;
}

void wfile (struct link*ps ) {
	struct link *q;
	int i,j;
	FILE *p;
	char path[100];
	printf("请输入文件路径,要用双斜杠形式\n") ;
	
	scanf("%s",path);
	p=fopen(path,"a+");
	
	if(p==NULL)  p=fopen("D:\\information.txt","wt");
	if(p==NULL)  p=fopen("D:\\information.txt","at");
	
	while(ps!=NULL) {
		
		fprintf(p,"%s  %s",ps->date.studentID,ps->date.name);
		for(j=0; j<m; j++)
			fprintf(p,"  %s",ps->date.score[j]);
		fprintf(p,"\n");
		ps=ps->next;
		
	}
	
	fclose(p);
}
void help() {
	printf("\t\t\t ------------------------------------------------------- \n");
	printf("\t\t\t|              *****欢迎使用帮助目录！*****             |\n");
    printf("\t\t\t|-------------------------------------------------------|\n");
	printf("\t\t\t|  0.退出                                               |\n");
	printf("\t\t\t|  1.录入每个学生的学号.姓名和各科考试成绩              |\n");
	printf("\t\t\t|  2.计算每门课程的总分和平均分                         |\n");
	printf("\t\t\t|  3.计算每个学生的总分和平均分                         |\n") ;
	printf("\t\t\t|  4.按每个学生的总分由高到低排出名次表                 |\n");
	printf("\t\t\t|  5.按每个学生的总分由低到高排出名次表                 |\n");
	printf("\t\t\t|  6.按学号由小到大排出成绩表                           |\n");
	printf("\t\t\t|  7.添加学生信息,删除学生信息或修改信息                |\n");
	printf("\t\t\t|  8.按学号查询学生排名及其考试成绩                     |\n");
	printf("\t\t\t|  9.按姓名查询学生排名及其考试成绩                     |\n");
	printf("\t\t\t|  10.统计不同类别内学生人数和情况                      |\n");
	printf("\t\t\t|  11.输出每个学生的信息                                |\n");
	printf("\t\t\t|  12.从文件中读出每个学生的记录信息并显示              |\n");
	printf("\t\t\t|  13.将学生信息写入文件                                |\n");
	printf("\t\t\t ------------------------------------------------------- \n");
	return ;
	
}
void rfile () {
	
    int o=0;
	int h;
	int b;
	char a;
	int i=0;
	int next=1;
	int choice;
	char *p;
	char e;
	int k;
	char ch;
	char path[100];
	FILE *p1;
	struct link *p2;
	struct link *p3;
	struct link *l;
	struct link *p4;
	struct link *head;
	char s[100];
	
	printf("请输入文件路径,要用双斜杠形式\n") ;
	scanf("%s",path);
	p1=fopen(path,"rt");
	
	if(p1==NULL) {
		printf("对不起该路径下不存在该文件，是否输入信息，按y或n继续\n");
		scanf(" %c",&a);
		if(a=='y')  input();
		else 	exits();
		
	} else {
		printf("是否格式化输出，按y或n继续\n");
		scanf(" %c",&e);
		if(e=='n') {
			while((fgets(s,N,p1))!=NULL)
			{
				printf(s);
				o++;
			}
		   printf("\n总共有%d个学生\n",o);
			close(p1);
			Sleep (9000);
			system("CLS");
			main();
		}
		
		if(e=='y') {
			printf("请输入文本中学生人数");
			scanf("%d",&n);
			printf("请输入考生科目数");
			scanf("%d",&m);
				printf("请输入要输入成绩的科目"); 
		for(h=0;h<m;h++)
		
	{   scanf("%s",f[h]);
	}
			system("CLS");
			STUDENT str[n];
			for(i=0; i<n; i++)
			 {
				fscanf(p1,"%s",str[i].studentID) ;
				fscanf(p1,"%s",str[i].name);
				for(k=0; k<m; k++)
					fscanf(p1,"%s",str[i].score[k]);
			}
			
			printf("\t\t\t学号\t姓名") ;
		    	for(h=0;h<m;h++)

	{  printf("\t\t%s",f[h]);
	}
	       printf("\n");
	   
	    printf("\t\t--------------------------------------------\n");
	    
			for(i=0; i<n; i++) {
				printf("\t\t\t%s\t%s",str[i].studentID,str[i].name);
				for(k=0; k<m; k++)  printf("\t\t%s",str[i].score[k]);
				printf("\n");
			}
			
			head=(struct link *)malloc(sizeof(struct link));
			
			fclose(p1);
			if(head==NULL) {
				printf("NO enough memory!\n");
				exit(1);
			}
			
			p2=(struct link *)malloc(sizeof(struct link));
			head->next=p2;
			if(p2==NULL) {

				printf("NO enough memory!\n");
				exit(1);
			}
			
			l=head->next;
			
			for (i=0; i<n; i++) {
				p3=(struct link *)malloc(sizeof(struct link));
				if(p3==NULL) {
					printf("NO enough memory!\n");
					exit(1);
				}
				strcpy(p2->date.name,str[i].name);
				strcpy(p2->date.studentID,str[i].studentID);
				for(k=0; k<m; k++)
					strcpy(p2->date.score[k],str[i].score[k]);
				p3->prev=p2;
				p2->next=p3;
				p2=p3;
			}
			
			p2->prev->next=NULL;
			free(p3);
			printf("\n请选择您接下来的操作\n") ;
			help();
			
			while(next==1) {
				scanf (" %d",&choice );
				if(choice==2)   {  system("CLS");course(l)  ;}
				else if(choice==3)  { system("CLS");
			 stdudent(l ) ;}
				else if(choice==4)    {system("CLS");        descending(l) ;}
				else if(choice==5)       { system("CLS");               ascending(l)  ;}
				else if(choice==6)          { system("CLS"); number(l);}
				else if(choice==7)       {system("CLS");       addwithremove(l );}
				else if(choice==8) {
				  system("CLS"); searchnumber (l ) ;}
				else if(choice==9)    {system("CLS");  searchname (l ) ;}
				else if(choice==10)    {system("CLS"); statistic(l );}
				else if(choice==11)   {system("CLS");list(l );}
				else if(choice==12)   {
				 system("CLS");rfile ();}
				else if(choice==1)  {system("CLS");input() ;}
				else if(choice==13)    {system("CLS");           wfile(l );}
				else exits();
				l=head->next;
				printf("请问您还需要其它操作吗,按y或n继续\n");
				scanf(" %c",&a);
				
				if(a=='y')  {
					next=1;
					printf("请继续选择操作\n");
						help();
				} else next=0;
		
		}
		}
	}
	freememory(l) ;
	free(head);
	printf("       感谢您的使用");
	return ;
}
void descending(struct link*ps ) {
	STUDENT  a[n];
	char name1[10];
	int to;
	int i,j;
	int temp;
	float s;
	s=m;
	to=0;
	
	for(j=0; j<n; j++) {
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//算出单个人的总分
		a[j].total=to;
		strcpy(a[j].name,ps->date.name);
		ps=ps->next;
	}
	
	for(j=0; j<n; j++)
		for(i=j+1; i<n; i++)
			if(a[i].total>a[j].total) {
				temp=a[j].total;
				a[j].total=a[i].total;
				a[i].total=temp;
				strcpy(name1,a[j].name);
				strcpy(a[j].name,a[i].name) ;
				strcpy(a[i].name,name1);
			}
			
			printf("\t\t\t|----------------------------------------------- |\n" );
			
	for(i=0; i<n; i++) 
	        printf("\t\t\t|第%d名：%s        总分：%d                  \n",i+1,a[i].name,a[i].total);
			printf("\t\t\t|----------------------------------------------- |\n" );
			return ;
			
}

void ascending(struct link*ps  ) {

	STUDENT  a[n];
	char name1[10];
	int to;
	int i,j;
	int temp;
	float s;
	s=m;
	to=0;
	
	for(j=0; j<n; j++) {
		to=0;
		for(i=0; i<m; i++)
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//算出单个人的总分
		a[j].total=to;
		strcpy(a[j].name,ps->date.name);
		ps=ps->next;
	}
	
	for(j=0; j<n; j++)
		for(i=j+1; i<n; i++)
			if(a[i].total<a[j].total) {
				temp=a[j].total;
				a[j].total=a[i].total;
				a[i].total=temp;
				strcpy(name1,a[j].name);
				strcpy(a[j].name,a[i].name) ;
				strcpy(a[i].name,name1);
			}
			
			 temp=n;
			 
	printf("\t\t\t|----------------------------------------------- |\n" );		 		 
	for(i=0; i<n; i++) printf("\t\t\t|第%d名：%s 总分：%d             \n",temp--,a[i].name,a[i].total);
	printf("\t\t\t|----------------------------------------------- |\n" );
	return ;
}

void list (struct link*ps ) {
	
	printf("\t\t\t|------------------------------------------------------- |\n" );
	printf("\t\t\t|学号		姓名		");
	int j;
		for(j=0;j<m;j++)
	{  printf  ("%s		",f[j]);
	} 
	
	printf("\n");
	printf("\t\t\t|------------------------------------------------------- |\n" );
	
	while(ps!=NULL) {
		printf("\t\t\t|%s	%s  ",ps->date.studentID,ps->date.name);
		for(j=0; j<m; j++)
			printf("  %s	 ",ps->date.score[j]);
		printf("\n") ;
		ps =ps->next;
		
	}
	
	printf("\t\t\t|------------------------------------------------------- |\n" );
	return ;
}

void number(struct link*ps  ) {
	
	int i=0;
	int j,k;
	struct link*p;
	struct link*l=ps;
	struct link *p1[n];
	struct link *h;
	h=  (struct link *)malloc(sizeof(struct link));
	strcpy( h->date.studentID,"9999999999");
	
	for(ps->date.studentID; ps!=NULL; ps=ps->next) {
		p1[i]=h;
		for( p=l; p!=NULL; p=p->next) {
			if(i>=0) {
				if(strcmp(p1[i]->date.studentID,p->date.studentID)>0) {
					j=0;
					while(strcmp(p1[j]->date.studentID,p->date.studentID)<0)
						j++;
					if(j==i) p1[i]=p;
				}
			}
		}
		i++;
	}
	
    printf("\t\t\t|-----------------------------------------------------------------|\n" );
	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
	{  printf  ("%s		",f[j]);
	} 
	printf("\n");
	
	printf("\t\t\t|----------------------------------------------------------------|\n" );

	for(j=0; j<n; j++) {
		printf("\t\t\t|%s    %s  ",p1[j]->date.studentID,p1[j]->date.name);
		for(k=0; k<m; k++)
			printf("   %s",p1[j]->date.score[k]);
		printf("\n") ;
	}
	
	printf("\t\t\t|----------------------------------------------------------------|\n" );

	return;
}
void searchnumber (struct link*ps ) {

	int flag=0;
	int j;
	char a[11];
	printf("请输入您的学号:\n") ;
	
	scanf("%s",a);
		printf("\t\t\t|----------------------------------------------------------- \n" );
    	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------------------- \n" );

	while(ps!=NULL) {
		if(strcmp(ps->date.studentID,a)==0) {
			printf("\t\t\t|%s\t\t%s\t\t",ps->date.studentID,ps->date.name);
			for(j=0; j<m; j++)
				printf("%s\t\t",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}
	if(flag==0) printf("对不起，您输入的学号未在列表中找到\n") ;
	return ;
}
void searchname (struct link*ps ) {

	int flag=0;
	int j;
	char a[11];
	printf("请输入您要查询的姓名\n") ;
	scanf("%s",a);
		printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
	
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
    	
	while(ps!=NULL) {
		if(strcmp(ps->date.name,a)==0) {
			printf("\t\t\t%s\t\t%s\t\t",ps->date.studentID,ps->date.name);
			for(j=0; j<m; j++)
				printf("%s\t\t",ps->date.score[j]);
			printf("\n") ;
			flag=1;
		}
		ps=ps->next;
	}

	if(flag==0) printf("对不起，您输入的姓名未在列表中找到\n") ;
	return ;
}
void statistic(struct link*ps ) {
	int g=0;
	char s[10];
	struct link*p;
	int k;
	p=ps;
	int flag=0;
	int i;
	int j;
	int a[5]= {0,0,0,0,0};
	printf("请输入您要划分类别的科目\n") ;
	scanf("%s",s);

	while(g==0)
	{
	for(k=0;k<m;k++) 
	if(strcmp(s,f[k])==0) {
	 i=k;
     g=1;} 
  
    if(g==0) 
	{  printf("对不起，您输入的科目没有找到，请重新输入\n");
	scanf("%s",s);  }
}
	i++;

	while(flag<n) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j<60) a[0]++;
		if(j>=60&&j<70) a[1]++;
		if(j>=70&&j<80)  a[2]++;
		if(j>=80&&j<90)  a[3]++;
		if(j>=90&&j<=100)  a[4]++;
		ps =ps->next ;
		flag++;
	}

	ps=p;
	printf("优秀人数(90-100)有%d人\n",a[4]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=90&&j<=100)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("良好人数(80-89)有%d人\n",a[3]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=80&&j<90)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("中等人数(70-79)有%d人\n",a[2]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=70&&j<80)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("及格人数(60-69)有%d人\n",a[1]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=60&&j<70)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;

	printf("不及格人数(<60)有%d人\n",a[0]);
	flag=0;

	while(flag<n) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j<60)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
		flag++;
	}
	return;
	
}
void addwithremove (struct link*ps  ) {
	int a;
	int b=0; 
	printf("请输入你要选择的操作\n1.添加一个学生的信息\n2.删除一个学生的信息\n3.修改一个学生的信息");

	while(b==0)
	{  scanf(" %d",&a);
	if(a==1)  { system("CLS");   add(ps );break;} 
	if(a==2)  { system("CLS");   del (ps );break;}
	if(a==3)  {  system("CLS");   revise(ps)    ;break;}
    else printf("请重新输入\n");
}
	return;
}
void add (struct link*ps  ) {
	char s[10];
	int g=0;
	int i,j;

	struct link*p;

	struct link*q;
		printf("请输入您要插入的学生的位置，请输入整数");
		scanf("%d",&i);
	
	 while( g==0 )
	 {
	if(i>1&&i<n+1) {
		n++;
		int flag=1;
		while(flag<i-1) {
			ps=ps->next;
			flag++;
		}
		printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
		p=(struct link*)malloc(sizeof(struct link));
		printf("\t\t\t|");
		scanf("%s",p->date.studentID);
		scanf("%s",p->date.name);
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
		p->prev=ps;
		p->next=ps->next;
		ps->next->prev=p;
		ps->next=p;
	    return ;
	}
	if(i==1) {
		n++;
		p=(struct link*)malloc(sizeof(struct link));
		p->prev=ps->prev;
		ps->prev->next=p;
		ps->prev=p;
		p->next=ps;
		printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
	
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|");
		scanf("%s",p->date.studentID);
		scanf("%s",p->date.name);
	
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}
		return ;
	}

	if(i==n+1) {
		int flag=1;
		while(flag<i-1) {
			ps=ps->next;
			flag++;
		}
		n++;
		p=(struct link*)malloc(sizeof(struct link));
		ps->next=p;
		p->prev=ps;
		p->next=NULL;
		printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|");
		scanf("%s",p->date.studentID);
		scanf("%s",p->date.name);
		for(j=0; j<m; j++) {
			scanf(" %s",p->date.score[j]);
		}  
		return;
	
}      gets(s);
      printf("您的输入有误，请重新输入\n");
	 	 scanf(" %d",&i);
	 
}
}

void del(struct link*ps 	) {
	int g=0;
	int flag =0;
	int a;
	char b;
	printf("请输入要删除的学生信息\n1.姓名    2.学号\n");
	scanf(" %d",&a);

	if(a==1) {
		searchname(ps );
		char a[11];
		printf("\n请确认您要删除的姓名\n") ;
		scanf("%s",a);
	
		if(n!=1){ 
		while(ps!=NULL) {  g++;
			if(strcmp(ps->date.name,a)==0) {
				printf("该学生信息已被删除\n");
				flag=1;
					break;
			} 
			ps=ps->next;
		}
      if(g!=n)
     {
	   ps->prev->next=ps->next;                                                              
				ps->next->prev=ps->prev;
  }  
      if(flag==1)
     {
	  if(g==n)
     {
     ps->prev->next=NULL;	
	 }
}

if(flag==0) printf("对不起，该学生信息未被找到\n");
	}
		  if(n==1)
  {
  	   if(strcmp(ps->date.name,a)==0)
  	  {  	printf("该学生信息已被删除\n");
  	        ps->prev->next=NULL;
  	        printf("该表单中已不存在学生信息,请使用功能1输入学生信息\n");
		   }   
		else printf("对不起，该学生信息未被找到\n");   
          
  }
}
	if(a==2) {
		char a[11];
		searchnumber(ps );
		printf("\n请确认您要删除的学号\n") ;
		scanf("%s",a);
	
		if(n!=1){
			
		while(ps!=NULL) {  g++;
			if(strcmp(ps->date.studentID,a)==0) {
				printf("该学生信息已被删除\n");
				flag=1;
				break;
			}
			ps=ps->next;
	
		}
	
		if(flag==1)
	{
		
			if(g==n)
		 {
     ps->prev->next=NULL;	
	 }
}

		if(g!=n)
		{
		ps->prev->next=ps->next;                                                              
				ps->next->prev=ps->prev;		
		}
		if(flag==0) printf("对不起，该学生信息未被找到\n");
	}
	  if(n==1)
	{
		 if(strcmp(ps->date.studentID,a)==0)
  	  {  	printf("该学生信息已被删除\n");
  	        ps->prev->next=NULL;
  	        printf("该表单中已不存在学生信息,请使用功能1输入学生信息\n");
		   }   
		else printf("对不起，该学生信息未被找到\n");
	}
}
	return ;
	
}

void freememory(struct link*ps) {

	while(ps!=NULL) {
		ps =ps->next	;
		free(ps);
	}
	return ;
}
void login()
{
	printf("\n\n\n\t\t\t学生信息管理系统\n\n");
	printf("\t\t\t  版本号: 0.2 \n\n");
	printf("\n\n\n\t\t\t  2019年1月7日\n\n");
	printf("\t\t\tcxtao(100请输:0);\n\n");
} 

void logins()
{
     printf("\n\n\n\t\t\t  用户须知\n\n");
 printf("\t\t由于该系统采用字符串形式储存数据\n");
 printf("\t\t   故请将100分以:0形式写出      \n");


} 

void revise (struct link*ps )
{	int flag =0;
    int a;
	char b[10];
	char c[10];
	int i=0,j=0;
	int g;
	printf("请输入要修改的学生信息\n1.姓名   2.学号\n");
	scanf("%d",&a);

	if(a==1) {
		printf("\n请输入要修改的学生的姓名\n");
		scanf(" %s",b) ;
	 
	  while(ps!=NULL) 
	    {
	    if(strcmp(b,ps->date.name)==0)  	
	   { printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|%s\t\t%s\t\t",ps->date.studentID,ps->date.name);
	    for(i=0;i<m;i++)	
	   	printf("%s",ps->date.score[i]);
	    	flag=1;
	    	break;
     	}
	    ps=ps->next;	
		}
	
		if(flag==0)  
		{printf("\n您输入的学生姓名没有被找到\n"); return;} 
		printf("\n请输入您要修改的科目");
		scanf("%s",c) ;
		for(i=0;i<m;i++)
	    if(strcmp(f[i],c)==0) g=i;
	    
	    printf("\n请输入修改的分数");
	    scanf("%s",ps->date.score[g]);
	    printf("\n修改成功\n");
}
if(a==2) {
	
		printf("请输入要修改的学生的学号\n");
		scanf(" %s",b) ;
	 
	  while(ps!=NULL) 
	    {
	    if(strcmp(b,ps->date.studentID)==0)  	
	   { printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|学号		姓名		");
		for(j=0;j<m;j++)
    	{  printf  ("%s		",f[j]);	} 
    	printf("\n");
    	printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|%s\t\t%s\t\t",ps->date.studentID,ps->date.name);
	    for(i=0;i<m;i++)	
	    	printf("%s\t\t",ps->date.score[i]);
	    	flag=1;
	    	break;
     	}
	    ps=ps->next;	
		}
	
		if(flag==0)  
		{printf("\n您输入的学生姓名没有被找到\n"); return;} 
		printf("\n请输入您要修改的科目");
		scanf("%s",c) ;
		for(i=0;i<m;i++)
	    if(strcmp(f[i],c)==0) g=i;
	    printf("\n请输入修改的分数");
	    scanf("%s",ps->date.score[g]);
	    printf("\n修改成功\n");}
    return;
}
