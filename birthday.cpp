#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Date
{
char nm[56];
char date[12];
char email[101];
};
void print(char g,int size)
{
int i;
for(i=1;i<=size;i++) printf("%c",g);
printf("\n");
}
void add()
{
FILE *f;
struct Date t,g;
char nm[56];
char email[101];
char date[12];
printf("Enter nm :  ");
fgets(nm,56,stdin);
nm[strlen(nm)-1]='\0';
fflush(stdin);
printf("Enter date :  ");
fgets(date,12,stdin);
date[strlen(date)-1]='\0';
fflush(stdin);
char m;
printf("Enter email : ");
fgets(email,101,stdin);
email[strlen(email)-1]='\0';
fflush(stdin);
printf("Save(Y/N)");
m=getchar();
fflush(stdin);
if(m!='y' && m!='Y')
{
printf("Date not added\n");
return ;
}
strcpy(g.nm,nm);
strcpy(g.date,date);
strcpy(g.email,email);
f=fopen("birthday.dat","ab");
fwrite(&g,sizeof(struct Date),1,f);
fclose(f);
printf("Date added , press enter to continue...............\n");
getchar();
fflush(stdin);
}
void showListByName()
{
FILE *f;
struct Date t;
char nm[56];
char email[101];
char date[12];
printf("Date (search by nm module)\n");
printf("Enter nm :  ");
fgets(nm,56,stdin);
nm[strlen(nm)-1]='\0';
fflush(stdin);
f=fopen("birthday.dat","rb");
if(f==NULL)
{
printf("Invalid detail\n");
return;
}
int found=0;
char m;
while(1)
{
fread(&t,sizeof(struct Date),1,f);
if(feof(f)) break;
if(strcasecmp(t.nm,nm)==0)
{
printf("Name : %s\nDate : %s\nEmail : %s\n",t.nm,t.date,t.email);
found=1;
}
}
fclose(f);
if(found==0)
{
printf("Invalid nm \n");
return ;
}
printf("Press enter to continue....................");
getchar();
fflush(stdin);
}

void showFullList()
{
FILE *f;
int newPage,pageSize;
int sNo;
struct Date t;
f=fopen("birthday.dat","rb");
if(f==NULL)
{
printf("Date(List Module)\n");
print('-',110);
printf("%10s  %-35s  %-10s  %-35s\n","S.No.","Name","Date","Email");
print('-',110);
printf("No student added\n");
print('-',110);
printf("Press enter to continue....................\n");
getchar();
fflush(stdin);
return ;
}
newPage=1;
pageSize=5;
sNo=0;
while(1)
{
if(newPage==1)
{
printf("Date(List Module)\n");
print('-',110);
printf("%10s  %-35s  %-10s  %-35s\n","S.No.","Name","Date","Email");
print('-',110);
newPage=0;
}

fread(&t,sizeof(struct Date),1,f);
if(feof(f)) break;
sNo++;
printf("%10d  %-35s  %-10s  %-35s\n",sNo,t.nm,t.date,t.email);
if(sNo%pageSize==0)
{
print('-',110);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
newPage=1;
}
}
if(sNo==0)
{
printf("No student added\n");
print('-',80);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
}
if(sNo%pageSize!=0)
{
print('-',110);
printf("Press enter to continue...................\n");
getchar();
fflush(stdin);
}
fclose(f);
}
void showListByMonth()
{
FILE *f;
struct Date t;
char nm[56];
char email[101];
char date[12];
int month;
printf("Date (search by month module)\n");
printf("Enter month :  ");
scanf("%d",&month);
fflush(stdin);
f=fopen("birthday.dat","rb");
if(f==NULL)
{
printf("Invalid detail\n");
return;
}
int found=0;
char m;
char x[11];
int fMonth;
int fDay;
char y[3];
int e=0;
int g;
while(1)
{
fread(&t,sizeof(struct Date),1,f);
if(feof(f)) break;
strcpy(x,t.date);
e=0;
while(x[e]!='/') e++;
e++;
g=0;
while(x[e]!='/')
{
y[g]=x[e];
e++;
g++;
}
fMonth=atoi(y);
if(fMonth==month)
{
printf("Name : %s\nDate : %s\nEmail : %s\n",t.nm,t.date,t.email);
found=1;
}
}
fclose(f);
if(found==0)
{
printf("Invalid month \n");
return ;
}
printf("Press enter to continue....................");
getchar();
fflush(stdin);
}
int main()
{
int ch;
while(1)
{
printf("1. Add birthday\n");
printf("2. Get birthday date list by nm\n");
printf("3. Get list\n");
printf("4. Get birthday date list by month\n");
printf("5. Exist\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
add();
}else if(ch==2)
{
showListByName();
}else if(ch==3)
{
showFullList();
}else if(ch==4)
{
showListByMonth();
}
else if(ch==5)
{
break;
}else
{
printf("Invalid choice \n");
return 0;
}
}
return 0;
}
