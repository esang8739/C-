#include<stdio.h>
#include<stdlib.h>
#include<string.h>//��Ҫ�õ�strcmp���� 
#include<Windows.h>
#include<conio.h>//���������¼��ͷ�ļ� 

#define LEN 15
#define YYT 5//������ѧ�ŵ�����ַ��� 
#define N 50//���ѧ������

int n=0,t=1; 

//��������
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
	float score[2]; //���Ƴɼ� 
}stu[N]; 
int caidan(void)//�˵� 
{
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*----------------------����yyds----------------------\n");	
	printf("*                 ѧ����Ϣ����ϵͳ                  *\n");
	printf("*****************************************************\n");
	printf("********************ϵͳ���ܲ˵�*********************\n");
	printf("----------------------     --------------------------\n");
	printf("*****************************************************\n");
	printf("**    1��*��*��*ѧ*��      *     2��*��*ѯ*ѧ*��   **\n");
	printf("*****************************************************\n");
	printf("**    3��*ɾ*��*ѧ*��      *     4��*��*��*ѧ*��   **\n");
	printf("*****************************************************\n");
	printf("**    5��*��*ʾ*��*Ϣ      *     6��*ˢ �� �� Ϣ   **\n");
	printf("*****************************************************\n");
	printf("**                  0�� �� �� ϵ ͳ                **\n");
	printf("*****************************************************\n");
	printf("**            ����©�� *��������* �����½�         **\n");
	printf("*****************************************************\n");
	printf("----------------------     --------------------------\n");
	int num;
		while(t)//t��ȫ�ֱ����������ܳ��� 
	{
		printf("���ã�������˵���ţ�");
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
			default:printf("�����������������룡");	
	}
	
	
	} 
	
	system("pause");	
	return 0;
} 
int zengjia(void)
{
	int i=n,j,flag,m=0;
	printf("\n����������ӵ�ѧ��������\n");
	scanf("%d",&m);
	if(m>0){
	do{
		flag=1;
		while(flag)
		{
			flag=0;
			printf("�������%dλѧ����ѧ�ţ�\n",i+1);
			
			scanf("%s",stu[i].StuID);
			//�ж�ѧ���Ƿ��ظ�
			for(j=0;j<i;j++){
				if(strcmp(stu[i].StuID,stu[j].StuID)==0){
					printf("��ѧ���Ѿ����ڣ����������룡\n");	
					flag=1;
					break;			
				}	 
			}
		}
		printf("�������%dλѧ������:\n",i+1);
		scanf(" %s",stu[i].Stuname); 
		printf("�������%dλѧ���༶:\n",i+1);
		scanf("%d",&stu[i].Stucla); 
		printf("�������%dλѧ���Ա�:\n",i+1);	
		scanf(" %s",&stu[i].Stusex);
		printf("�������%dλѧ����רҵ:\n",i+1);
		scanf(" %s",&stu[i].Stuzy);
		printf("�������%dλѧ������ѧ�ɼ�:\n",i+1);
		scanf("%f",&stu[i].score[1]);
		printf("�������%dλѧ�����ۺϳɼ�:\n",i+1);
		scanf("%f",&stu[i].score[2]);
		i++;
		}while(i<n+m);//ֻҪ��ǰѧ��������û������Ӻ�����������͵ü������		
	}
	n+=m;
	printf("�����ɣ�����\n");
	system("pause");
} 
int chazhao(void)
{
	int i,num,flag;
	char s1[LEN+1];
	printf("*****************************\n");
	printf("**-------1.��ѧ�Ų�ѯ------**\n");
	printf("**-------2.��������ѯ------**\n");
	printf("**-------3.�˳����˵�------**\n");
	printf("*****************************\n");
	while(1)
	{
		flag=0;
		printf("�������Ӳ˵���");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
			printf("��������Ҫ����ѧ����ѧ�ţ�\n");
			scanf("%s",s1);
			for(i=0;i<n;i++)
			{
				if(strcmp(stu[i].StuID,s1)==0)
				{
					flag=1;
					printf("ѧ��\t\t����\t\t�Ա�\t\t�༶\t\tרҵ\t\t��ѧ�ɼ�\t\t�ۺϳɼ�\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%s\t\t%.2f\t\t%.2f\n",stu[i].StuID,stu[i].Stuname,stu[i].Stusex,stu[i].Stucla,stu[i].Stuzy,stu[i].score[0],stu[i].score[1]);
				}	
			}break;	
			case 2:
			printf("��������Ҫ����ѧ����������\n");
			scanf("%s",s1);
			for(i=0;i<n;i++)
			{
				if(strcmp(stu[i].Stuname,s1)==0)
				{
					flag=1;
					printf("ѧ��\t\t����\t\t�Ա�\t\t�༶\t\tרҵ\t\t��ѧ�ɼ�\t\t�ۺϳɼ�\n");
					printf("%s\t\t%s\t\t%c\t\t%d\t\t%s\t\t%.2f\t\t%.2f\n",stu[i].StuID,stu[i].Stuname,stu[i].Stusex,stu[i].Stucla,stu[i].Stuzy,stu[i].score[0],stu[i].score[1]);
				}	
			}break;		
			case 3: return 0;
			default: printf("����1--3֮������\n");
		}
		if(flag==0)
		printf("�Ҳ�����ѧ��!\n���������룡"); 
	} 
}
int shanchu(void)
{
	int i,j,flag;
	char s1[LEN];
	printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
	scanf("%s",s1);
	flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(s1,stu[i].StuID)==0)
		{
			flag=1;
			for(j=i;j<n-1;j++)
			{
				stu[j]=stu[j+1];//ֱ�ӰѺ����ѧ������ǰ�ƶ�һλ 
			}
		}
		if(flag==1) break;//˵���Ѿ��ҵ�����Ҫɾ����ѧ��������ѭ�� 
	} 
	 if(0==flag)
	 {
	 	printf("��ѧ�Ų����ڣ�����\n");
	 }
	
	if(1==flag)
	{	
		printf("ɾ���ɹ�\n");
		n--;		
	}
	system("pause");
}		
int xianshi(void)
{
	int i;
	
	if(n==0)
	{
		printf("���ã�����û��ѧ����Ϣ����������ѧ����Ϣ����ˢ����������!\n");
	}
	else
	{
		printf("���ڹ���%d��ѧ����\n",n);
		printf("ѧ��\t\t����\t\t�Ա�\t\t�༶\t\tרҵ\t\t��ѧ�ɼ�\t\t�ۺϳɼ�\n");
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
	printf("��������Ҫ�޸ĵ�ѧ��������\n");
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
				int num;//����switch�������Ӳ˵� 
				printf("***************************************************\n");
				printf("*----1.�޸�ѧ��--------  -  -----2.�޸��Ա�-------*\n");
				printf("*----3.�޸İ༶--------  -  -----4.�޸�רҵ--*\n");
				printf("*----5.�޸���ѧ�ɼ�----  -  -----6.�޸��ۺϳɼ�---*\n");
				printf("*-------------------7.�˳����˵�------------------*\n");
				printf("***************************************************\n\n");
				printf("�������Ӳ˵���");
				scanf("%d",&num);
				switch(num)
				{
					case 1:	
					printf("�������µ�ѧ��:\n");
					getchar();
					gets(ID);
					strcpy(stu[i].StuID,ID);break;
					case 2:
					getchar();	
					printf("�������µ��Ա�:\n");
					getchar();
					gets(sex);
					scanf("%s",&sex);
					strcpy(stu[i].Stusex,sex);break;
					case 3:
					printf("�������µİ༶:\n");
					scanf("%d",&cla);
					stu[i].Stucla=cla;break;
					case 4:
					printf("��������רҵ:\n");
					getchar();
					gets(zy);
					scanf("%s",&zy);
					strcpy(stu[i].Stuzy,zy);break;
					case 5:
					printf("�������µ���ѧ�ɼ�:\n");
					scanf("%f",&score);
					stu[i].score[0]=score;break;
					case 6:
					printf("�������µ��ۺϳɼ�:\n");
					scanf("%f",&score);
					stu[i].score[1]=score;break;
					case 7:
					return 0;break; 
					default:
					printf("����1--7֮��ѡ��\n");
				}
				if(num>0&&num<7)
				printf("�޸ĳɹ����ǵñ���Ӵ������\n");
				break;//�ҵ�ѧ��������ѭ��;	
			}
		}	
		if(flag==0)
		{
			printf("û���ҵ���ѧ����������������Ҫ�޸���Ϣ��ѧ��������\n");
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
	printf("��������Ҫˢ�µ��ļ�����\n");
	getchar(); 
	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)//���ļ� 
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	for(i=0;i<N;i++) 
	{
		if(fread(&stu[i],sizeof(struct student),1,fp)==1)
		k++;
	}	
	n=k; 
	if(k==0)
	printf("ˢ��ʧ�ܣ�����\n");
	else
	printf("ˢ�³ɹ�������\n"); 
	fclose(fp);
	system("pause");
	
}	
int tuichu(void) 
{
	int h; 
	printf("�����˳���ȷ���밴1��ȡ���밴0\n"); 
	scanf("%d",&h);
	if(h==1)
	{
		t=0;
		printf("�ɹ��˳�����лʹ�ã�\n");	
	}
		if(h==0)
	{
		printf("�˳���ȡ����\n");
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
		printf("\n\n\t      ���ļ�ʧ��...");
		getch();
		exit(0);
	}
	if((ch=fgets(a,7,fp))==NULL)
	{
		printf("��ӭ��ʹ���ҵ�С����*���������룡\n\n");
		printf("����������:");
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
	printf("\n��ȷ������:");
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
		printf("\n\n������ȷ...");
		
		if(ch==NULL)
		fputs(a,fp);
		fclose(fp);
		getch();
		system("cls");
		return 0;
	}
	else
	printf("\n\n��Ԥ�����벻һ��...");       
	getch();
	exit(0);
	return 0;
}
