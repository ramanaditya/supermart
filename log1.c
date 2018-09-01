#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include"fashion.h"
#include"daily.h"
#include"medical.h"
#include"electronics.h"	
#include"bill_test.h"
#include"menu.h"
#include"menu1.h"
void upper_case(char []);
struct username
{
	char name[100];
}username[100];
struct pass
{
	char passwd[100];
}pass[100];


void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}


int main()
{
	FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7;
	char ch,che,che1,che2,uname[100],UNAME[100],password[100],d[10],e=' ';
	int choice,i=0,j=0,p=0,u=0,choice1,ukey,pkey,ver_manager,ver_owner,ans,ureg=0,answer;
	int M_choice,r_choice,s_choice;
	time_t mytime;
	mytime = time(NULL);
	system("clear");
	

	start:
	
	printf("\n\t\t");
	printf("     %s",ctime(&mytime));
	fp=fopen("menu1.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	
	
	scanf("%d",&choice);
	fclose(fp);
	switch(choice)
	{
		case 1: system("clear");
				goto login;
				break;
		case 2: system("clear");
				printf("\n\tEnter the 4 digit verification code to SIGNUP : "); 
				scanf("%d",&ans);
				if(ans==9876)
				{
					goto reg;
				}
				else
				{
					printf("\n\t\t\t Incorrect Code ");
					printf("\n\t\t\tTRY AGAIN LATER");
					goto start;
				}
				break;
		case 0: exit(0);
		default:printf("...Invalid selection...\n Please select the choice again");
				goto start;
				break;
	}
	



	login:
	/* Testing the SIGNUP
	fp1=fopen("log_db.dat","r");
	fp2=fopen("log_db1.dat","r");
	while((fread(&username,sizeof(struct username),1,fp1))&&(fread(&pass,sizeof(struct pass),1,fp2)))
	{
		printf("%s\t",username[i].name);
		printf("%s\n",pass[i].passwd);
		
	}
	fclose(fp1);
	fclose(fp2);
	*/
	
	fp5=fopen("menu3.txt","r");
	while((che1=fgetc(fp5))!=EOF)
	{
		printf("%c",che1);
	}
	scanf("%s",uname);
	fclose(fp5);
	printf("\n\t      Enter your Password : ");
	scanf("%s",password);

	fp1=fopen("log_db.dat","r");
	fp2=fopen("log_db1.dat","r");
	while((!feof(fp1))&&(!feof(fp2)))
	{
		fread(&username,sizeof(struct username),1,fp1);
		fread(&pass,sizeof(struct pass),1,fp2);
		for(i=0,j=0;i<100,j<100;i++,j++)
		{
			ukey=strcmp(username[i].name,uname);
			pkey=strcmp(pass[j].passwd,password);
			if((ukey==0)&&(pkey==0))
			{
				u=1;
				fp4=fopen("menu2.txt","r");
				while((che=fgetc(fp4))!=EOF)
				{
					printf("%c",che);
				}
				printf("\n\n");

				{
					delay(1000);
					{	
						printf("\n\n\t\t\t");
						printf("%s",ctime(&mytime));
						printf("\n");
						goto main;
					}
				}
				fclose(fp4);		
			}
		}
	}
	if(u==0)
	{
		system("clear");
		printf("\n\n\n\n\n\t\tUsername or Password is Incorrect\n");
		printf("\n\n\n\t\tPlease try again with valid Username\n");
		
		delay(2000);
		{
			system("clear");
			goto start;
		}
	}	
	fclose(fp1);
	fclose(fp2);
	exit(0);
	



	reg:
	printf("\n\t\t\t...Welcome to the registration page...\n");
	fp1=fopen("log_db.dat","a+");
	fp2=fopen("log_db1.dat","a+");
	for(i=0;i<100;i++)
	{
		while((!feof(fp1))&&(!feof(fp2)))
		{
			fread(&username,sizeof(struct username),1,fp1);
			fread(&pass,sizeof(struct pass),1,fp2);
			printf("\t\t\tEnter your username : ");
			scanf("%s",uname);
			if(strcmp(username[i].name,uname)==0)
			{
				printf("\nUsername already exists\nPlease select other username\n");
				goto reg;
			}
			else
			{
				strcpy(username[i].name,uname);
				break;
			}
		}
		printf("\t\t\tEnter your password : ");
		scanf("%s",pass[i].passwd);
		fwrite(&username[i],sizeof(struct username),1,fp1);
		fwrite(&pass[i],sizeof(struct pass),1,fp2);
		fclose(fp1);
		fclose(fp2);
		system("clear");
		printf("\n\t\t...You have successfully signed up...\n");
		printf("\t\t\tDo you want to login\n");
		printf("\t\t\t\tPress \n\n\t\t\t\t1. Yes\n\n\t\t\t\t2. No\t");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: system("clear");
					goto login;
					break;
			case 2: exit(0);
		}
	}

	fclose(fp);
	exit(0);

	


	main:
	do
	{
		system("clear");
		printf("\n\t\t\t");
		printf("%s",ctime(&mytime));
		disp_menu();
		upper_case(uname);
		printf("%s",uname);
		disp_menu1();
		scanf("%d",&M_choice);
		switch(M_choice)
		{
			case 1 : calcbill();
					 printf("\n\tTHANK YOU FOR SHOPPING WITH US");
					 printf("\n\t    PLEASE COME BACK AGAIN\n\n\n");
					 printf("\n\nFor more billing press 1 or to exit press 0 : ");
					 scanf("%d",&ans);
					 if(ans==1)
					 {
					 	printf("\n");
					 	goto main;
					 }
					 else
					 {
					 	exit(0);
					 }
					 break;
			case 2 : goto manager;
					ch2:
					do
						 {
						 	 printf("\n1.male fashion\t2.female fashion\t3.daily use\n4.medical\t5.electronics\n");
						 	 printf("enter the stock to be edited else '0' to exit : ");
							 scanf("%d",&s_choice);
							 switch(s_choice)
							 {
							 	case 1 : disp_male_menu();
							 			 disp_male_prod();
							 			 edit_male_prod();
						 				 break;
							 	case 2 : disp_female_menu();
							 			 disp_female_prod();
							 			 edit_female_prod();
							 			 break;
							 	case 3 : disp_daily_list();
							 			 disp_daily_prod();
							 			 edit_daily_prod();
						 				 break;
							 	case 4 : disp_medical_list();
							 			 disp_prod();
							 			 edit_prod();
							 			 break;
							 	case 5 : disp_e_menu();
							 			 disp_e_prod();
							 			 edit_e_prod();
						 				 break;
							 	default : printf("enter valid case choice\n");	 
							 }
						 }while(s_choice!=0);
						 
					break;
			case 3 : goto owner;
					ch3:
					do
					 {	
					 	 printf("\n1.male fashion\t2.female fashion\t3.daily use\n4.medical\t5.electronics\n");
					 	 printf("enter the stock to reset else '0' to exit : ");
						 scanf("%d",&r_choice);
						 switch(r_choice)
						 {
						 	case 1 : reset_male_database();
					 				 break;
						 	case 2 : reset_female_database();
						 			 break;
						 	case 3 : reset_daily_database();
					 				 break;
						 	case 4 : reset_database();
						 			 break;
						 	case 5 : reset_e_database();
					 				 break;
						 	default : printf("enter valid choice\n");
						 }
					 }while(r_choice!=0);
	
					break;
			case 4 : disp_male_prod();
					 disp_female_prod();
	 				 disp_daily_prod();
	 				 disp_prod();
	 				 disp_e_prod();
	 				 printf("\n\n\t\t\tPress 1 to go back : ");
 					 scanf("%d",&answer);
	 				 if(answer==1)
	 				 {
	 				 	goto main;
	 				 }
	 				 else
 				 		break;
	 		case 5 : goto start;
			default : exit(0);
		}
	}while(M_choice!=0);


	manager:
	{
		printf("\n\t\tTo edit the Stock Details\n");
		printf("\t\tEnter the 4 digit verification code : ");
		system("clear");
		scanf("%d",&ver_manager);
		if(ver_manager==1234)
		{
			goto ch2;
			
		}
		else
			printf("\t\tVerification Code didn't match\n");
			goto main;
	}


	



	owner:
	{
		printf("\n\t\tTo Reset the Database\n");
		printf("Enter the 4 digit verification code : ");
		system("clear");
		scanf("%d",&ver_owner);
		if(ver_owner==4321)
		{
			goto ch3;	 
		}
		else
		{
			printf("\t\tVerification Code didn't match\n");
			goto main;
		}
	}
	return 0;
}




void upper_case(char string[]) 
{
   int c = 0;
 
   while (string[c] != '\0') {
      if (string[c] >= 'a' && string[c] <= 'z') 
      {
         string[c] = string[c] - 32;
      }
      c++;
   }
}