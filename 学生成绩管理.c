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
void input(); //¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�
void course(struct link*ps ); //����ÿ�ſγ̵��ֺܷ�ƽ����
void stdudent(struct link*ps ); //����ÿ��ѧ�����ֺܷ�ƽ����
void descending(struct link*ps );//��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void ascending(struct link*ps );//��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void number(struct link*ps  ) ;//��ѧ����С�����ų��ɼ���
void addwithremove (struct link*ps  ) ;//��Ӻ�ɾ��ѧ����Ϣ
void searchnumber (struct link*ps );//��ѧ�Ų�ѯѧ���������俼�Գɼ�
void searchname (struct link*ps ) ;//��������ѯѧ���������俼�Գɼ�
void statistic(struct link*ps ) ;//ͳ�Ʋ�ͬ�����ѧ�����������
void list (struct link*ps  );//���ÿ��ѧ������Ϣ
void wfile(struct link*ps );// ��ѧ����Ϣд���ļ�
void rfile (); //����Ϣ���ļ��ж���
void exits();//�˳�
void help () ; //����
void freememory(struct link*ps);//�黹�ռ�
void add (struct link*ps  ); //���ѧ����Ϣ
void del( struct link*ps ); // ɾ��ѧ����Ϣ
void login();//������Ϣ 
void revise(struct link*ps );//�޸�ѧ����Ϣ 
void logins();//�û���֪ 
int main() {
	login();
	Sleep (2000);
	system("CLS");
	logins();
	Sleep (4000);
	system("CLS");
	int a,n=0;
	printf("\t\t\t ---------------------------------------------- \n");
	printf("\t\t\t|     *****��ӭ����ѧ���ɼ�����ϵͳ��*****     |\n");
    printf("\t\t\t|----------------------------------------------|\n");
	printf("\t\t\t|          ��Ϊ���ṩ���·���                  |\n");
	printf("\t\t\t|          1.¼��ѧ����Ϣ                      |\n");
	printf("\t\t\t|          2.���ļ��ж�ȡѧ����Ϣ              |\n");
	printf("\t\t\t|          3.�鿴����                          |\n");
	printf("\t\t\t|          0.�˳�                              |\n");
	printf("\t\t\t ---------------------------------------------- \n");
	printf("��������������\n");
	scanf("%d",&a);
	system("CLS");
	
	while (a<0||a>3) {
		printf("������������������ѡ��\n");
		scanf(" %d",&a);
	}
	
	while (a==3) {
		help()  ;
		printf("��������¼����Ϣ");
		scanf("%d",&a);
	}
	
	if(a==1) input();
	if(a==2)  rfile ()  ;
	if(a==0)  exits() ;
	return 0;
	
}

void exits() {
		printf("       ��л����ʹ��");
	exit(0);
}

void stdudent(struct link*ps ) {
	
	int to;
	int i,j;
	float s;
	s=m;
	to=0;
	
	 printf("\t\t\t|-------------------------------------------------------|\n");
	 printf("\t\t\t|        �ܷ�	    ƽ����\n");
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
	printf("����������");
	scanf("%d",&n);
	printf("����������ųɼ�");
	scanf("%d",&m) ;
	printf("������Ҫ����ɼ��Ŀ�Ŀ\n"); 
	
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
	printf("\t\t\t| ѧ��      ����      ");
	
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
	printf("��ѡ�����������Ĳ���\n") ;
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
		printf("����������Ҫ����������,��y��n����\n");
		scanf(" %c",&a);
		if(a=='y')  {
			next=1;
			printf("�����ѡ�����\n");
			help();
		} else next=0;
		l=head->next;
	}
	
	freememory(l) ;
	free(head);
	printf("      ��л����ʹ��     ");
	return;
	
}
void course(struct link*ps ) {
	
	struct link* q=ps;
	int to;
	int i,j;
	float s;
	s=n;
     printf("\t\t\t|-------------------------------------------------------|\n");
	 printf("\t\t\t|		�ܷ�	ƽ����\n");
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
	printf("�������ļ�·��,Ҫ��˫б����ʽ\n") ;
	
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
	printf("\t\t\t|              *****��ӭʹ�ð���Ŀ¼��*****             |\n");
    printf("\t\t\t|-------------------------------------------------------|\n");
	printf("\t\t\t|  0.�˳�                                               |\n");
	printf("\t\t\t|  1.¼��ÿ��ѧ����ѧ��.�����͸��ƿ��Գɼ�              |\n");
	printf("\t\t\t|  2.����ÿ�ſγ̵��ֺܷ�ƽ����                         |\n");
	printf("\t\t\t|  3.����ÿ��ѧ�����ֺܷ�ƽ����                         |\n") ;
	printf("\t\t\t|  4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�                 |\n");
	printf("\t\t\t|  5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�                 |\n");
	printf("\t\t\t|  6.��ѧ����С�����ų��ɼ���                           |\n");
	printf("\t\t\t|  7.���ѧ����Ϣ,ɾ��ѧ����Ϣ���޸���Ϣ                |\n");
	printf("\t\t\t|  8.��ѧ�Ų�ѯѧ���������俼�Գɼ�                     |\n");
	printf("\t\t\t|  9.��������ѯѧ���������俼�Գɼ�                     |\n");
	printf("\t\t\t|  10.ͳ�Ʋ�ͬ�����ѧ�����������                      |\n");
	printf("\t\t\t|  11.���ÿ��ѧ������Ϣ                                |\n");
	printf("\t\t\t|  12.���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ              |\n");
	printf("\t\t\t|  13.��ѧ����Ϣд���ļ�                                |\n");
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
	
	printf("�������ļ�·��,Ҫ��˫б����ʽ\n") ;
	scanf("%s",path);
	p1=fopen(path,"rt");
	
	if(p1==NULL) {
		printf("�Բ����·���²����ڸ��ļ����Ƿ�������Ϣ����y��n����\n");
		scanf(" %c",&a);
		if(a=='y')  input();
		else 	exits();
		
	} else {
		printf("�Ƿ��ʽ���������y��n����\n");
		scanf(" %c",&e);
		if(e=='n') {
			while((fgets(s,N,p1))!=NULL)
			{
				printf(s);
				o++;
			}
		   printf("\n�ܹ���%d��ѧ��\n",o);
			close(p1);
			Sleep (9000);
			system("CLS");
			main();
		}
		
		if(e=='y') {
			printf("�������ı���ѧ������");
			scanf("%d",&n);
			printf("�����뿼����Ŀ��");
			scanf("%d",&m);
				printf("������Ҫ����ɼ��Ŀ�Ŀ"); 
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
			
			printf("\t\t\tѧ��\t����") ;
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
			printf("\n��ѡ�����������Ĳ���\n") ;
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
				printf("����������Ҫ����������,��y��n����\n");
				scanf(" %c",&a);
				
				if(a=='y')  {
					next=1;
					printf("�����ѡ�����\n");
						help();
				} else next=0;
		
		}
		}
	}
	freememory(l) ;
	free(head);
	printf("       ��л����ʹ��");
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
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//��������˵��ܷ�
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
	        printf("\t\t\t|��%d����%s        �ܷ֣�%d                  \n",i+1,a[i].name,a[i].total);
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
			to=(ps->date.score[i][0]-48)*10+(ps->date.score[i][1]-48)+to;//��������˵��ܷ�
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
	for(i=0; i<n; i++) printf("\t\t\t|��%d����%s �ܷ֣�%d             \n",temp--,a[i].name,a[i].total);
	printf("\t\t\t|----------------------------------------------- |\n" );
	return ;
}

void list (struct link*ps ) {
	
	printf("\t\t\t|------------------------------------------------------- |\n" );
	printf("\t\t\t|ѧ��		����		");
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
	printf("\t\t\t|ѧ��		����		");
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
	printf("����������ѧ��:\n") ;
	
	scanf("%s",a);
		printf("\t\t\t|----------------------------------------------------------- \n" );
    	printf("\t\t\t|ѧ��		����		");
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
	if(flag==0) printf("�Բ����������ѧ��δ���б����ҵ�\n") ;
	return ;
}
void searchname (struct link*ps ) {

	int flag=0;
	int j;
	char a[11];
	printf("��������Ҫ��ѯ������\n") ;
	scanf("%s",a);
		printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|ѧ��		����		");
	
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

	if(flag==0) printf("�Բ��������������δ���б����ҵ�\n") ;
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
	printf("��������Ҫ�������Ŀ�Ŀ\n") ;
	scanf("%s",s);

	while(g==0)
	{
	for(k=0;k<m;k++) 
	if(strcmp(s,f[k])==0) {
	 i=k;
     g=1;} 
  
    if(g==0) 
	{  printf("�Բ���������Ŀ�Ŀû���ҵ�������������\n");
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
	printf("��������(90-100)��%d��\n",a[4]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=90&&j<=100)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("��������(80-89)��%d��\n",a[3]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=80&&j<90)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("�е�����(70-79)��%d��\n",a[2]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=70&&j<80)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;
	printf("��������(60-69)��%d��\n",a[1]);

	while(ps!=NULL) {
		j=(ps->date.score[i-1][0]-48)*10+(ps->date.score[i-1][1]-48);
		if(j>=60&&j<70)
			printf("%s  %s  %s\n",ps->date.studentID,ps->date.name,ps->date.score[i-1]);
		ps =ps->next ;
	}
	ps=p;

	printf("����������(<60)��%d��\n",a[0]);
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
	printf("��������Ҫѡ��Ĳ���\n1.���һ��ѧ������Ϣ\n2.ɾ��һ��ѧ������Ϣ\n3.�޸�һ��ѧ������Ϣ");

	while(b==0)
	{  scanf(" %d",&a);
	if(a==1)  { system("CLS");   add(ps );break;} 
	if(a==2)  { system("CLS");   del (ps );break;}
	if(a==3)  {  system("CLS");   revise(ps)    ;break;}
    else printf("����������\n");
}
	return;
}
void add (struct link*ps  ) {
	char s[10];
	int g=0;
	int i,j;

	struct link*p;

	struct link*q;
		printf("��������Ҫ�����ѧ����λ�ã�����������");
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
    	printf("\t\t\t|ѧ��		����		");
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
    	printf("\t\t\t|ѧ��		����		");
	
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
    	printf("\t\t\t|ѧ��		����		");
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
      printf("����������������������\n");
	 	 scanf(" %d",&i);
	 
}
}

void del(struct link*ps 	) {
	int g=0;
	int flag =0;
	int a;
	char b;
	printf("������Ҫɾ����ѧ����Ϣ\n1.����    2.ѧ��\n");
	scanf(" %d",&a);

	if(a==1) {
		searchname(ps );
		char a[11];
		printf("\n��ȷ����Ҫɾ��������\n") ;
		scanf("%s",a);
	
		if(n!=1){ 
		while(ps!=NULL) {  g++;
			if(strcmp(ps->date.name,a)==0) {
				printf("��ѧ����Ϣ�ѱ�ɾ��\n");
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

if(flag==0) printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�\n");
	}
		  if(n==1)
  {
  	   if(strcmp(ps->date.name,a)==0)
  	  {  	printf("��ѧ����Ϣ�ѱ�ɾ��\n");
  	        ps->prev->next=NULL;
  	        printf("�ñ����Ѳ�����ѧ����Ϣ,��ʹ�ù���1����ѧ����Ϣ\n");
		   }   
		else printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�\n");   
          
  }
}
	if(a==2) {
		char a[11];
		searchnumber(ps );
		printf("\n��ȷ����Ҫɾ����ѧ��\n") ;
		scanf("%s",a);
	
		if(n!=1){
			
		while(ps!=NULL) {  g++;
			if(strcmp(ps->date.studentID,a)==0) {
				printf("��ѧ����Ϣ�ѱ�ɾ��\n");
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
		if(flag==0) printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�\n");
	}
	  if(n==1)
	{
		 if(strcmp(ps->date.studentID,a)==0)
  	  {  	printf("��ѧ����Ϣ�ѱ�ɾ��\n");
  	        ps->prev->next=NULL;
  	        printf("�ñ����Ѳ�����ѧ����Ϣ,��ʹ�ù���1����ѧ����Ϣ\n");
		   }   
		else printf("�Բ��𣬸�ѧ����Ϣδ���ҵ�\n");
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
	printf("\n\n\n\t\t\tѧ����Ϣ����ϵͳ\n\n");
	printf("\t\t\t  �汾��: 0.2 \n\n");
	printf("\n\n\n\t\t\t  2019��1��7��\n\n");
	printf("\t\t\tcxtao(100����:0);\n\n");
} 

void logins()
{
     printf("\n\n\n\t\t\t  �û���֪\n\n");
 printf("\t\t���ڸ�ϵͳ�����ַ�����ʽ��������\n");
 printf("\t\t   ���뽫100����:0��ʽд��      \n");


} 

void revise (struct link*ps )
{	int flag =0;
    int a;
	char b[10];
	char c[10];
	int i=0,j=0;
	int g;
	printf("������Ҫ�޸ĵ�ѧ����Ϣ\n1.����   2.ѧ��\n");
	scanf("%d",&a);

	if(a==1) {
		printf("\n������Ҫ�޸ĵ�ѧ��������\n");
		scanf(" %s",b) ;
	 
	  while(ps!=NULL) 
	    {
	    if(strcmp(b,ps->date.name)==0)  	
	   { printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|ѧ��		����		");
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
		{printf("\n�������ѧ������û�б��ҵ�\n"); return;} 
		printf("\n��������Ҫ�޸ĵĿ�Ŀ");
		scanf("%s",c) ;
		for(i=0;i<m;i++)
	    if(strcmp(f[i],c)==0) g=i;
	    
	    printf("\n�������޸ĵķ���");
	    scanf("%s",ps->date.score[g]);
	    printf("\n�޸ĳɹ�\n");
}
if(a==2) {
	
		printf("������Ҫ�޸ĵ�ѧ����ѧ��\n");
		scanf(" %s",b) ;
	 
	  while(ps!=NULL) 
	    {
	    if(strcmp(b,ps->date.studentID)==0)  	
	   { printf("\t\t\t|----------------------------------------------- |\n" );
    	printf("\t\t\t|ѧ��		����		");
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
		{printf("\n�������ѧ������û�б��ҵ�\n"); return;} 
		printf("\n��������Ҫ�޸ĵĿ�Ŀ");
		scanf("%s",c) ;
		for(i=0;i<m;i++)
	    if(strcmp(f[i],c)==0) g=i;
	    printf("\n�������޸ĵķ���");
	    scanf("%s",ps->date.score[g]);
	    printf("\n�޸ĳɹ�\n");}
    return;
}
