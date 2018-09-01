struct daily
{
	int prod_id;
	char prod_name[20];
	int prod_rate;
	int prod_quantity;
}daly;

int reset_daily_database()
{
	FILE *fp;
	int i;
	fp = fopen("daily_db.dat","w");
	/* 
		0:House care
		1:stationary
		2:personal care
		3:Grains
		4:pulses
		5:cereal
		6:snacks
		7:vegetable
		8:fruit
		9:spices
	 */
	for(i=0;i<5;i++)
	{
		printf("enter the product id : ");
		scanf("%d",&daly.prod_id);
		printf("enter the product name : ");
		scanf("%s",daly.prod_name);
		printf("enter the rate of the product : ");                                            
		scanf("%d",&daly.prod_rate);
		printf("enter the stock quantity : ");
		scanf("%d",&daly.prod_quantity);
		fwrite(&daly,sizeof(struct daily),1,fp);	
	}
	fclose(fp);
	return 0;
}

int disp_daily_list()
{	
	printf(" \n\n-----DAILY PRODUCTS MENU----- \n1:House Care\t\t 2:Stationary\n 3:Personal Care\t\t 4:Grains\n 5:Pulses  \t\t 6:Cereal\n 7:Snacks\t\t 8:Vegetable\n 9:Fruit    \t\t10:Spices\n");
	return 0;
}

int disp_daily_prod()
{
	FILE *fp;
	fp = fopen("daily_db.dat","r");
	printf(" \n\n-----DAILY PRODUCTS MENU----- \n");
	while(fread(&daly,sizeof(struct daily),1,fp))
	{
		printf("\nproduct id : %d\t",daly.prod_id);
		printf("name : %s\t",daly.prod_name);
		printf("rate : %d\t",daly.prod_rate);
		printf("stock quantity : %d\t",daly.prod_quantity);
	}	
	fclose(fp);
	return 0;
}

int edit_daily_prod()
{
	FILE *fp, *fp_temp;
	int choice=1,entry;
	while(choice==1)
	{
		
	
		fp = fopen("daily_db.dat","a+");
		fp_temp = fopen("temp.dat","w");
		if(fp==NULL)
		{
			printf("file cannot be openned\n");
		}
		fp = fopen("daily_db.dat","r");
		printf("\nenter product id of product to be edidted :\t");
		scanf("%d",&entry);

		while(fread(&daly,sizeof(struct daily),1,fp))
		{
			if(daly.prod_id==entry)
			{
				printf("enter the new rate :\t");
				scanf("%d",&daly.prod_rate);
				printf("enter the new quantity :\t");
				scanf("%d",&daly.prod_quantity);
				fwrite(&daly,sizeof(struct daily),1,fp_temp);
				
			}
			else
			{
				fwrite(&daly,sizeof(struct daily),1,fp_temp);
			}

		}
		fclose(fp);
		fclose(fp);
		fclose(fp_temp);

		fp = fopen("daily_db.dat","w");
		fp_temp = fopen("temp.dat","r");
		while(fread(&daly,sizeof(struct daily),1,fp_temp))
		{
			fwrite(&daly,sizeof(struct daily),1,fp);
		}
		fclose(fp);
		fclose(fp_temp);
		printf("press 1 to edit more daily use product :\t\n");
		scanf("%d",&choice);

	}
return 0;
}
