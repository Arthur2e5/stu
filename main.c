#include <stdio.h>
#define DB_LEN 50
// 声明函数 结构体
void insert();
void modify();
void delete();
void list();
void save();
void read();
int count=0;
struct stu {
	int id;
	char name[20];
	char sex[2];
	long date;
	char tel[16];
} s[DB_LEN];


//主函数开始
int main()
{
	int i;
        read();
	do {
		printf("欢迎使用学生信息管理系统\n");
		printf("请输入数字:\n");
		printf("1:\t插入\n");
		printf("2:\t修改\n");
		printf("3:\t删除\n");
		printf("4:\t查询\n");
		printf("5:\t退出\n");
		scanf("%d",&i);
		switch (i) {
			case 1 :
				insert();
				break;
			case 2 :
				modify();
				break;
			case 3 :
				delete();
				break;
			case 4 :
				list();
				break;
			case 5 :
				break;
			default :
				printf("输入错误,请重新输入!");
				break;
		}
	}
	while (i!=5);
        save();
        printf("save ok");
        return 0;
}
//主函数结束

//插入函数
void insert()
{
	int i;
	if (count>DB_LEN)
	{
		printf("空间已满");
		return;
	}
	printf("请输入学号:");
	scanf("%d",&i);
	s[count].id=i;
	printf("请输入学生姓名：");
	scanf("%s",&s[count].name);
	printf("请输入学生性别：");
	scanf("%s",&s[count].sex);
	printf("请输入学生出生日期：");
	scanf("%d",&s[count].date);
	printf("请输入学生电话：");
	scanf("%s",&s[count].tel);
	printf("输入成功");
	count++;
	return;
}

//查询函数
void list()
{
	void listone();
	void listall();
	int flag;
	printf("1为查询单个学生的信息，2为列出所有学生的信息");
	scanf("%d",&flag);
	switch (flag) {
		case 1 : listone();
			break;
		case 2 : listall();
			break;
		default : printf("输入错误！");
	}
}

//列出单个学生函数
void listone()
{
	int i,id;
	printf("请输入需要查询的学生学号");
	scanf("%d",&id);
	for (i=0;i<=DB_LEN;i++)
	{
		if(s[i].id==id)
		{
			printf("学号：%15d\n",s[i].id);
			printf("姓名：%15s\n",s[i].name);
			printf("性别：%15s\n",s[i].sex);
			printf("出生日期：%11d\n",s[i].date);
			printf("电话号码：%11s\n",s[i].tel);
			return;
		}
	}
	printf("无结果！");
}

//列出所有学生函数
void listall()
{
	int i;
	printf("==============================================\n");
	printf("| 学号 | 姓名 | 性别 | 出生日期 |  电话号码  |\n");
	for (i=0;i<count;i++) printf("|%6d|%6s|%6s|%10d|%12s|\n",s[i].id,s[i].name,s[i].sex,s[i].date,s[i].tel);
	printf("==============================================\n");
	return;
}

//修改函数
void modify()
{
	int i,id;
	printf("请输入需要修改的学生学号");
	scanf("%d",&id);
	for (i=0;i<=DB_LEN;i++)
	{
		if(s[i].id==id)
		{
			printf("请输入学生姓名：");
			scanf("%s",&s[i].name);
			printf("请输入学生性别：");
			scanf("%s",&s[i].sex);
			printf("请输入学生出生日期：");
			scanf("%d",&s[i].date);
			printf("请输入学生电话：");
			scanf("%s",&s[i].tel);
			printf("修改成功");
			return;
		}
	}
	printf("无结果！");
}

//删除函数
void delete()
{
	int i,id,f;
	struct s *p = NULL;
	printf("请输入需要删除的学生学号");
	scanf("%d",&id);
	for (i=0;i<=DB_LEN;i++)
	{
		if(s[i].id==id)
		{
			for (f=i;f<count;f++)
			{
				s[f]=s[f+1];
			}
			count--;
			printf("delete ok");
			return;
		}
	}
	printf("no result");
}

//保存函数
void save()
{
	int n;
	FILE *fp;
	fp=fopen("data.txt","r+");
	for(n=0;n<DB_LEN;n++)
	fwrite(&s[n],sizeof(struct stu),1,fp);
	fwrite(&count,4,1,fp);
	fclose(fp);
}

//读取函数
void read()
{
	FILE *fp;
	int n;
	if((fp=fopen("data.txt","r+"))==NULL)
	fp=fopen("data.txt","w+");
	for(n=0;n<DB_LEN;n++)
	fread(&s[n],sizeof(struct stu),1,fp);fread(&count,4,1,fp);
	fclose(fp);
}
