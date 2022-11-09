#include<stdio.h>
#include<stdlib.h>
#include<string.h>//需要用到strcmp函数 
#include<Windows.h>
#include<conio.h>//用于密码登录的头文件 

#define LEN 15
#define YYT 5//姓名和学号的最大字符数 
#define N 50//最大学生人数

int n=0,t=1; 

//函数声明
int caidan(void);
int zengjia(void);  
int chazhao(void);
int shanchu(void) ; 
int xianshi(void);
int xuigai(void);   
int shuaxin(void);
int tuichu(void); 
int mima(void);
struct student
{
	char StuID[LEN];
	char Stuname[LEN];
	int Stucla;
	char Stusex[YYT];
	char Stuzy[LEN];
	float score[2]; //各科成绩 
}stu[N]; 
int caidan(void)//菜单 
{
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*----------------------虞笙yyds----------------------\n");	
	printf("*                 学生信息管理系统                  *\n");
	printf("*****************************************************\n");
	printf("********************系统功能菜单*********************\n");
	printf("----------------------     --------------------------\n");
	printf("*****************************************************\n");
	printf("**    1、*增*加*学*生      *     2、*查*询*学*生   **\n");
	printf("*****************************************************\n");
	printf("**    3、*删*除*学*生      *     4、*修*改*学*生   **\n");
	printf("*****************************************************\n");
	printf("**    5、*显*示*信*息      *     6、*刷 新 信 息   **\n");
	printf("*****************************************************\n");
	printf("**                  0、 退 出 系 统                **\n");
	printf("*****************************************************\n");
	printf("**            如有漏洞 *技术不佳* 敬请谅解         **\n");
	printf("*****************************************************\n");
	printf("----------------------     --------------------------\n");
	int num;
		while(t)//t是全局变量，控制总程序 
	{
		printf("您好，请输入菜单编号：");
		scanf("%d",&num); 
		switch(num)
		{
			case 1: zengjia(); break;
			case 2: chazhao(); break;
			case 3: shanchu(); break;
			case 4: xuigai(); break;
			case 5: xianshi(); break;
			case 6: shuaxin(); break;
			case 0: tuichu(); break;
			default:printf("输入有误，请重新输入！");	
	}
	
	
	} 
	
	system("pause");	
	return 0;
} 
int zengjia(void)
{
	int i=n,j,flag,m=0;
	printf("\n请输入待增加的学生人数：\n");
	scanf("%d",&m);
	if(m>0){
	do{
		flag=1;
		while(flag)
		{
			flag=0;
			printf("请输入第%d位学生的学号：\n",i+1);
			
			scanf("%s",stu[i].StuID);
			//判断学号是否重复
			for(j=0;j<i;j++){
				if(strcmp(stu[i].StuID,stu[j].StuID)==0){
					printf("该学号已经存在，请重新输入！\n");	
					flag=1;
					break;			
				}	 
			}
		}
		printf("请输入第%d位学生姓名:\n",i+1);
		scanf(" %s",stu[i].Stuname); 
		printf("请输入第%d位学生班级:\n",i+1);
		scanf("%d",&stu[i].Stucla); 
		printf("请输入第%d位学生性别:\n",i+1);	
		scanf(" %s",&stu[i].Stusex);
		printf("请输入第%d位学生的专业:\n",i+1);
		scanf(" %s",&stu[i].Stuzy);
		printf("请输入第%d位学生的入学成绩:\n",i+1);
		scanf("%f",&stu[i].score[1]);
		printf("请输入第%d位学生的综合成绩:\n",i+1);
		scanf("%f",&stu[i].score[2]);
		i++;
		}while(i<n+m);//只要当前学生人数还没到达添加后的总人数，就得继续添加		
	}
	n+=m;
	printf("添加完成！！！\n");
	system("pause");
} 
int chazhao(void)
{
	int i,num,flag;
	char s1[LEN+1];
	printf("*****************************\n");
	printf("**-------1.按学号查询------**\n");
	printf("**-------2.按姓名查询------**\n");
	printf("**-------3.退出本菜单------**\n");
	printf("*****************************\n");
	while(1)
	{
		flag=0;
		printf("请输入子菜单：");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
			printf("请输入需要查找学生的学号：\n");
			scanf("%s",s1);
			for(i=0;i<n;i++)
			{
				if(strcmp(stu[i].StuID,s1)==0)
				{
					flag=1;
					printf("学号\t\t姓名\t\t性别\t\t班级\t\t专业\t\t入学成绩\t\t综合成绩\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%s\t\t%.2f\t\t%.2f\n",stu[i].StuID,stu[i].Stuname,stu[i].Stusex,stu[i].Stucla,stu[i].Stuzy,stu[i].score[0],stu[i].score[1]);
				}	
			}break;	
			case 2:
			printf("请输入需要查找学生的姓名：\n");
			scanf("%s",s1);
			for(i=0;i<n;i++)
			{
				if(strcmp(stu[i].Stuname,s1)==0)
				{
					flag=1;
					printf("学号\t\t姓名\t\t性别\t\t班级\t\t专业\t\t入学成绩\t\t综合成绩\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%s\t\t%.2f\t\t%.2f\n",stu[i].StuID,stu[i].Stuname,stu[i].Stusex,stu[i].Stucla,stu[i].Stuzy,stu[i].score[0],stu[i].score[1]);
				}	
			}break;		
			case 3: return 0;
			default: printf("请在1--3之间输入\n");
		}
		if(flag==0)
		printf("找不到该学生!\n请重新输入！"); 
	} 
}
int shanchu(void)
{
	int i,j,flag;
	char s1[LEN];
	printf("请输入需要删除的学生学号：\n");
	scanf("%s",s1);
	flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(s1,stu[i].StuID)==0)
		{
			flag=1;
			for(j=i;j<n-1;j++)
			{
				stu[j]=stu[j+1];//直接把后面的学生都往前移动一位 
			}
		}
		if(flag==1) break;//说明已经找到了需要删除的学生，结束循环 
	} 
	 if(0==flag)
	 {
	 	printf("该学号不存在！！！\n");
	 }
	
	if(1==flag)
	{	
		printf("删除成功\n");
		n--;		
	}
	system("pause");
}		
int xianshi(void)
{
	int i;
	
	if(n==0)
	{
		printf("您好，现在没有学生信息，请先增加学生信息或者刷新再来试试!\n");
	}
	else
	{
		printf("现在共有%d名学生：\n",n);
		printf("学号\t\t姓名\t\t性别\t\t班级\t\t专业\t\t入学成绩\t\t综合成绩\n");
		for(i=0;i<n;i++)
		{
			printf("%s\t\t%s\t\t%c\t\t%d\t\t%s\t\t%.2f\t\t%.2f\n",stu[i].StuID,stu[i].Stuname,stu[i].Stusex,stu[i].Stucla,stu[i].Stuzy,stu[i].score[0],stu[i].score[1]);	
		}
	}
		
	system("pause");	
}
int xuigai(void) 
{
	int i,flag;
	char ID[LEN],name[LEN],sex[YYT],zy[LEN];
	int cla;
	float score;
	printf("请输入需要修改的学生姓名：\n");
	getchar();
	gets(name);
	
	while(1)
	{	
		flag=0;
		for(i=0;i<n;i++)
		{
			if(strcmp(name,stu[i].Stuname)==0)
			{
				flag=1;
				int num;//用于switch函数的子菜单 
				printf("***************************************************\n");
				printf("*----1.修改学号--------  -  -----2.修改性别-------*\n");
				printf("*----3.修改班级--------  -  -----4.修改专业--*\n");
				printf("*----5.修改入学成绩----  -  -----6.修改综合成绩---*\n");
				printf("*-------------------7.退出本菜单------------------*\n");
				printf("***************************************************\n\n");
				printf("请输入子菜单：");
				scanf("%d",&num);
				switch(num)
				{
					case 1:	
					printf("请输入新的学号:\n");
					getchar();
					gets(ID);
					strcpy(stu[i].StuID,ID);break;
					case 2:
					getchar();	
					printf("请输入新的性别:\n");
					getchar();
					gets(sex);
					scanf("%s",&sex);
					strcpy(stu[i].Stusex,sex);break;
					case 3:
					printf("请输入新的班级:\n");
					scanf("%d",&cla);
					stu[i].Stucla=cla;break;
					case 4:
					printf("请输入新专业:\n");
					getchar();
					gets(zy);
					scanf("%s",&zy);
					strcpy(stu[i].Stuzy,zy);break;
					case 5:
					printf("请输入新的入学成绩:\n");
					scanf("%f",&score);
					stu[i].score[0]=score;break;
					case 6:
					printf("请输入新的综合成绩:\n");
					scanf("%f",&score);
					stu[i].score[1]=score;break;
					case 7:
					return 0;break; 
					default:
					printf("请在1--7之间选择！\n");
				}
				if(num>0&&num<7)
				printf("修改成功，记得保存哟！！！\n");
				break;//找到学生，结束循环;	
			}
		}	
		if(flag==0)
		{
			printf("没有找到该学生，请重新输入需要修改信息的学生姓名：\n");
			gets(name);
		}
	}
	system("pause");	
}
int shuaxin(void) 
{
	int i,k=0; 
	FILE *fp;
	char filename[LEN+1];
	printf("请输入需要刷新的文件名：\n");
	getchar(); 
	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)//打开文件 
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	for(i=0;i<N;i++) 
	{
		if(fread(&stu[i],sizeof(struct student),1,fp)==1)
		k++;
	}	
	n=k; 
	if(k==0)
	printf("刷新失败！！！\n");
	else
	printf("刷新成功！！！\n"); 
	fclose(fp);
	system("pause");
	
}	
int tuichu(void) 
{
	int h; 
	printf("即将退出，确认请按1，取消请按0\n"); 
	scanf("%d",&h);
	if(h==1)
	{
		t=0;
		printf("成功退出，感谢使用！\n");	
	}
		if(h==0)
	{
		printf("退出已取消！\n");
		system("pause");	
	}
}
int mima(void) 
{
	
	int i,k;
	char *ch;
	char a[7];
	char b[7];
	FILE *fp;
	if((fp=fopen("stu.dat","a+"))==NULL)
	{
		printf("\n\n\t      打开文件失败...");
		getch();
		exit(0);
	}
	if((ch=fgets(a,7,fp))==NULL)
	{
		printf("欢迎您使用我的小程序*请设置密码！\n\n");
		printf("请输入密码:");
		for(k=0;k<7;k++)
		{
			if((a[k]=getch())=='\r')
			{
				a[k]='\0';
				break;
			}
			if(a[k]=='\b'&& k>0)
	        {
	            printf("\b \b");
	            k=k-2;
	            continue;
	        }
	        printf("*");
		} 
	}
	printf("\n请确认密码:");
	for(k=0;k<7;k++)
	{
		if((b[k]=getch())=='\r')
		{
			b[k]='\0';
			break;
		}
		if(b[k]=='\b'&& k>0)
        {
            printf("\b \b");
            k=k-2;
            continue;
        }
        printf("*");
	} 
	if(strcmp(a,b)==0)
	{
		printf("\n\n密码正确...");
		
		if(ch==NULL)
		fputs(a,fp);
		fclose(fp);
		getch();
		system("cls");
		return 0;
	}
	else
	printf("\n\n与预设密码不一致...");       
	getch();
	exit(0);
	return 0;
}
