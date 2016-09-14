#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person                               //定义结构体
{
	char num[10];   //学号
	char name[15]; //姓名
	int age;      //年龄
	int en;      //英语成绩
	int ji;      //专业成绩
}person;
person per[100];  //定义100
char filename[20];                                      //定义全局变量
  logon()                                            //登陆函数 使系统更显完善
{
 printf("\n\n\n\t\t\t  学生信息管理系统\n\n");
 printf("\t\t\t     版本号：2.0\n\n");
 printf("\n\n\n\n\t\t\t    2012年3月10日\n\n");
 printf("\t\t\t   C区**栋514寝\n");
 printf("\n\n\t\t\t     Ace_cm_liu\n");
 printf("\n\n\t\t\t    导演兼制作\n");
 system("pause");
}
int menu_filename()
   {
	  system("cls");
	  printf("请输入你要操作的文件名:");
	  scanf("\t%s",filename);
    }
    //*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
int menu_select()                              //菜单选择系统函数
{
	 char c;
	  do{
		system("cls");
		printf("\t\t ╭═════════■□■□═══╮\n");
		printf("\t\t│         学生信息管理系统         │\n");
        printf("\t\t╰═══■□■□══════════╯\n");
		printf("\t\t   ┌─────────────—┐\n");
		printf("\t\t   │ 1. 添加记录    2. 显示记录 │\n");
		printf("\t\t   │                            │\n");
		printf("\t\t   │ 3. 信息查询    4. 数据计算 │\n");
		printf("\t\t   │                            │\n");
		printf("\t\t   │ 5. 修改记录    6. 删除记录 │\n");
		printf("\t\t   │                            │\n");
		printf("\t\t   │ 0. 退出程序                │\n");
		printf("\t\t   └─────────────—┘\n");
		printf("\t\t请您选择(0-6):");
		c=getchar();
	 }while(c<'0'||c>'6');
		return (c-'0');                                      //字符减去’0‘得到的是数字整型//
}

	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

void add()                                      //成绩的录入与添加函数
  {
	FILE *fp;
	int i=0,n=0;
	char sign='y';                              //首先定义sing='y'
	system("cls");                                //清屏函数  系统中调用
	while(sign!='n'&&sign!='N')                    //其实只有当输入N或n时才跳出循环
      {
	    printf("             ----学生纪录添加----\n");
	    printf("学号：\n");
	    scanf("\t%s",per[i].num);
	    printf("姓名:\n");
	    scanf("\t%s",per[i].name);
	    printf("年龄：\n");
	    scanf("\t%d",&per[i].age);
	    printf("英语：\n");
	    scanf("\t%d",&per[i].en);
	    printf("专业：\n");
	    scanf("\t%d",&per[i].ji);
        printf("是否继续添加?(y/n)");
	    scanf("\t%c",&sign);
	    i++;
	    n=n+1;
	    system( "cls ");
   }system("pause");                                     //等待命令

   if((fp=fopen(filename,"a"))==NULL)                    //以2进制形式进行文件尾追加//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;                                         //如果文件出现错误 就返回
	   }
		for(i=0;i<n;i++)
		if(fwrite(&per[i],sizeof(person),1,fp)!=1)      //以2进制形式写入文件中//一次写入一个数组//
	    printf("file write error\n");
	    fclose(fp);                                       //关闭文件
	    system("pasue");
  }
     //*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
  void scan()                        //显示记录  进行全面信息浏览
   {
	void amend();                         //声明修改函数//
	char sign='y';
	FILE *fp;
    int i=0,n;
    system("cls");
      if((fp=fopen(filename,"r"))==NULL)             //以2进制方式读取文件信息//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
    while(!feof(fp))                              //一直读取知道文件尾结束
	{
		fread(&per[i],sizeof(person),1,fp);  //以2进制方式将文件信息读到数组内存中//一次读取一个//
		 i++;
     }
    fclose(fp);
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
     printf("        学号            姓名           年龄    英语    专业\n");
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    for(n=0;n<i-1;n++)                             //循环全部输出
     printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[n].num,per[n].name,per[n].age,per[n].en,per[n].ji);
	 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	 system("pause");
	 system("cls");
	 printf("是否需要修改?(y/n)");
	 scanf("\t%c",&sign);
	if(sign!='n'&&sign!='N')                    //选择是否在浏览后进行修改//
	 amend();
	 system("pause");

  }

     //*********************************************************************//
	 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                    //数据查询//
  void query()                     //学生信息的不同方式查询
   {
	FILE *fp;
	int i=0,n=0;
	int m;
	system("cls");
	printf("\t\n请选择查询方式:\n");
    printf("\t┌──────┐\n");
	printf("\t│1--模糊查询 │\n");
    printf("\t│2------姓名 │\n");
    printf("\t│3------学号 │\n");
    printf("\t│4------返回 │\n");
    printf("\t└──────┘\n");
	printf("请输入你要查询的方式\n");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3&&m!=4)
		{
			printf("输入错误请重新查询\n");
	        scanf("%d",&m);
	    }
      if((fp=fopen(filename,"r"))==NULL)                 //以2进制方式读取文件信息//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

    while(!feof(fp))
	{
		fread(&per[i],sizeof(person),1,fp);                      //以2进制方式将文件信息读到数组内存中//一次读取一个//
	    i++;n=n+1;
     }

       if(m==1)                                                 //模糊查询
      {
	    char s[3];                                             //定义输入的文字所占的字节 /一个汉字占2个字节 外加一结尾符此处小心溢出
		int i=0;
		system("cls");
        printf("\t请输入想查询的姓:");
		scanf("%s",s);
		for(i=0;i<n-1;i++)                                               //文件信息已经读取到数组中 此处进行循环用于下一语句的查找
		{

		  if(per[i].name[0]==s[0]&&per[i].name[1]==s[1])              //比较per[i].name与所输入的前俩个字符是否相同//
		    {
		        printf("\t学号: %s\n",per[i].num);
		        printf("\t姓名: %s\n",per[i].name);
		        printf("\t年龄: %d\n",per[i].age);
		        printf("\t英语: %d\n",per[i].en);
		        printf("\t计算机: %d\n",per[i].ji);
	     	    printf("\t                     \n");
	        }
		}
	 }

	if(m==2)                                            //姓名查询
	   {
		char s[20];
		int i=0;
		printf("\t请输入想查询的姓名:");
		scanf("\t%s",s);
		while(strcmp(per[i].name,s)!=0&&i<n) i++;            //比较per[i].name与所输入姓名是否相同//
		if(i==n)
		{
			printf("\t通讯录中没有此人!\n");
			system("pause");
			return;
		}
		  printf("\t学号: %s\n",per[i].num);
		  printf("\t姓名: %s\n",per[i].name);
		  printf("\t年龄: %d\n",per[i].age);
		  printf("\t英语: %d\n",per[i].en);
		  printf("\t计算机: %d\n",per[i].ji);
	     }
	if(m==3)                                                            //学号查询
		{
		  char s[15];
		  int i=0;
		  printf("请输入想查询的学号：");
		  scanf("\t%s",s);
		 while(strcmp(per[i].num,s)!=0&&i<n)i++;                       //比较per[i].name与所输入学号是否相同//
			if(i==n)
			{
				printf("\t通讯录中没有此人!\n");
				system("pause");
			    return;
			}
			printf("\t学号: %s\n",per[i].num);
		    printf("\t姓名: %s\n",per[i].name);
		    printf("\t年龄: %d\n",per[i].age);
		    printf("\t英语: %d\n",per[i].en);
		    printf("\t计算机: %d\n",per[i].ji);
		  }
		  fclose(fp);
		  system("pause");
  }
	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                         //数据统计//
 void date()
  {
	FILE *fp;
	struct person temp;                               //定义临时数组用于交换时存放数组信息用于后面的交换//
	int sum;                                         //总分
	int s[100];
    int i=0,n=0;
	int j,k,t;
	int m;
	system("cls");
	printf("\t\n选择排序方式:\n");
    printf("\t┌──────┐\n");
    printf("\t│1------英语 │\n");
    printf("\t│2----计算机 │\n");
	printf("\t│3----  总分 │\n");
    printf("\t│4------返回 │\n");
    printf("\t└──────┘\n");
	printf("请输入你要排序的方式\n");
	scanf("%d",&m);
	system("cls");
	while(m!=1&&m!=2&&m!=3&&m!=4)
		{
			printf("输入错误请重新输入\n");
	        scanf("%d",&m);
	    }
     if((fp=fopen(filename,"r"))==NULL)                 //以2进制方式读取文件信息//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

   while(!feof(fp))                               //一直进行读取直至文件尾//
	 {
	   fread(&per[i],sizeof(person),1,fp);
	   i++;n=n+1;
      }
   if(m==1)
	  {
	  for(i=0;i<n-1;i++)                           //采用冒泡法进行排序//
	  {
		 k=i;
	    for(j=i+1;j<n;j++)
	    if(per[j].en>per[k].en)                              //排序//比较大小//
	    k=j;
		temp=per[k];per[k]=per[i];per[i]=temp;                  //当符合条件时进行数据交换//
		}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("        学号            姓名           年龄    英语    专业\n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				for(i=0;i<n-1;i++)
	        printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji);
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		fclose(fp);
		}

	if(m==2)
	  {
		for(i=0;i<n-1;i++)
		 {
			  k=i;
	       for(j=i+1;j<n;j++)
			if(per[j].ji>per[k].ji)
			  k=j;
		    temp=per[k];per[k]=per[i];per[i]=temp;
		  }
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("        学号            姓名           年龄    英语    专业\n");
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	    for(i=0;i<n-1;i++)
	        printf("\t%s \t%s \t\t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji);
	        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		  fclose(fp);
	    }
	if(m==3)
	  {
		for(i=0;i<n-1;i++)
	       {
			 sum=0;
			 sum=per[i].en+per[i].ji;
			 s[i]=sum;                                           // 第一个数组用于数组间信息操作//
	        }
	        for(i=0;i<n-1;i++)
		      {
			    k=i;
	            for(j=i+1;j<n;j++)
				  if(s[j]>s[k])
					k=j;
		        t=s[k];s[k]=s[i];s[i]=t;                          //按照总分大小进行排序//
		        temp=per[k];per[k]=per[i];per[i]=temp;            //随之使其数组相应顺序随总分大小一起排序//
		        }
				  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("        学号            姓名           年龄    英语    专业    总分   \n");
	              printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				for(i=0;i<n-1;i++)
	              printf("\t%s \t%s \t\t%d \t%d \t%d \t%d\n",per[i].num,per[i].name,per[i].age,per[i].en,per[i].ji,s[i]);
	              printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				fclose(fp);
      }
      system("pause");
	}

	//*********************************************************************//
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                                 // 数据修改//
void amend()
  {
	FILE *fp;
	int i=0,n=0;
    char s[15];
	int m;
	system("cls");
	printf("\t\n请选择修改方式:\n");
    printf("\t┌──────┐\n");
    printf("\t│1------姓名 │\n");
    printf("\t│2------学号 │\n");
    printf("\t│3------返回 │\n");
    printf("\t└──────┘\n");
	printf("请输入你要修改的方式\n");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3)
		{
			printf("输入错误请重新修改\n");
	        scanf("%d",&m);
	    }
	 if((fp=fopen(filename,"r"))==NULL)                 //以2进制方式读取文件信息//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
	while(!feof(fp))
	{
		fread(&per[i],sizeof(person),1,fp);
		i++;n=n+1;
	}i=0;
	fclose(fp);
	system("cls");
  if(m==1)
	{
	  char s[20];
	  int i=0;
	  printf("\t请输入想修改的姓名:");
	  scanf("\t%s",s);
	  while(strcmp(per[i].name,s)!=0&&i<n) i++;                           //进行比较 找到所需要的信息
		if(i==n)
		 {
			printf("\t通讯录中没有此人!\n");
			return;
		 }
	    else{
	         printf("学号：\n");
	         scanf("\t%s",per[i].num);
	         printf("姓名:\n");
	         scanf("\t%s",per[i].name);
	         printf("年龄：\n");
	         scanf("\t%d",&per[i].age);
	         printf("英语：\n");
	         scanf("\t%d",&per[i].en);
	         printf("专业：\n");
	         scanf("\t%d",&per[i].ji);
	      }
      }
	if(m==2)
	   {
		char s[15];
		int i=0;
		printf("请输入想修改的学号：");
		scanf("\t%s",s);
		while(strcmp(per[i].num,s)!=0&&i<n)i++;
		   if(i==n)
			{
			 printf("\t通讯录中没有此人!\n");
			 return;
			}
			else{
	             printf("学号：\n");
	             scanf("\t%s",per[i].num);
	             printf("姓名:\n");
	             scanf("\t%s",per[i].name);
	             printf("年龄：\n");
	             scanf("\t%d",&per[i].age);
	             printf("英语：\n");
	             scanf("\t%d",&per[i].en);
	             printf("专业：\n");
	             scanf("\t%d",&per[i].ji);
			    }
	    }
	 if((fp=fopen(filename,"w"))==NULL)                            //进行修改后将信心重新写入文件中
	      {
		    printf("cannot open the files\n");
            return;
	       }
		for(i=0;i<n-1;i++)
		  if(fwrite(&per[i],sizeof(person),1,fp)!=1)
	      printf("file write error\n");
		  fclose(fp);
		  printf("信息已经修改成功\n");
		  system("pause");
}
      //*********************************************************************//
	  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                                                        //数据删除//
void delet()
  {
    FILE *fp;
    char s[10];
	int i=0,n=0;
	  if((fp=fopen(filename,"r"))==NULL)                  //以2进制方式读取文件信息//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }

    while(!feof(fp))
	{
	  fread(&per[i],sizeof(person),1,fp);               //将文件信息读取到数组内存中//
	  i++;n=n+1;
     }
    fclose(fp);
	 if((fp=fopen(filename,"w"))==NULL)                 //以2进制写入方式打开文件//
	  {
		 printf("cannot open the files\n");
		 system("pause");
         return;
	   }
	printf("学生学号：");
	scanf("%s",s);
    for(i=0;i<n-1;i++)
	 if(!(strcmp(per[i].num,s)==0))                    //找到与其匹配的信息进行操作//   如果条件符合就写入否者跳过这组数据此数据就是所需删除的
	  fwrite(&per[i],sizeof(person),1,fp)!=1;             //以2进制方式将信息从内存中写入文件磁盘//
	 fclose(fp);
	 printf("数据删除成功");
	 system("pause");
}
     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
	 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
                             //运用switch语句进行菜单选择//
  int main()
  {
	  int n=0;
	  logon();
	  menu_filename();                                         //引用全局变量文件名
	  for(;;)                                                 //循环使用主界面直到遇到结束命令
	  {
		  switch(menu_select())                               // 函数的调用//
		  {
		  case 1:
			  printf("\t\t *^_^*学生记录添加 *^_^*\n");
			  add();
			  break;
		  case 2:
			  printf("\t\t *^_^*学生信息浏览 *^_^*\n");
			  scan();
			  break;
		  case 3:
			  printf("\t\t *^_^*学生信息查询 *^_^*\n");
			  query();
              break;
		  case 4:
			  printf("\t\t *^_^*数据计算 *^_^*\n");
			  date();
			  break;
		  case 5:
			  printf("\t\t *^_^*数据修改 *^_^*\n");
              amend();
			  break;
		  case 6:
			   printf("\t\t *^_^*数据删除 *^_^*\n");
			   delet();
			   break;
		  case 0:
		        printf("\n\t\t谢谢使用，再见!\n");
		        printf("\n\t\t");
		        system("pause");
		        exit(0);
		  }
	  }
	  system("pause");
  }

           //学生信息管理系统前期功程完成，还有待修改使其功能更加完善代码更加简洁巧妙  thank you!//
                                      // 如果这段代码好用，那它是Ace_cm_liu写的。
                                        //如果不好用，我不知道是谁写的。

