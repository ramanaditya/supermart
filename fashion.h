// male database
struct male_fashion
{
	int prod_id;
	char prod_name[20];
	int prod_rate;
	int prod_quantity;
}m_item;

//female database
struct female_fashion
{
	int prod_id;
	char prod_name[20];
	int prod_rate;
	int prod_quantity;
}f_item;

int disp_fashion_menu()
{
	printf("1.Male\n2.Female\n");
	return 0;
}

int disp_male_menu()
{
	printf("\n-----MALE MENU-----\n1.T-shirt\n2.Shirt\n3.Jeans\n4.Pant\n5.footwear\n0.Go back to previous menu\n");
	return 0;
}

int disp_female_menu()
{
	printf("\n-----FEMALE MENU-----\n1.Suit\n2.Lehenga\n3.Saree\n4.Jeans\n5.Footwear\n0.Go back to previous menu\n");
	return 0;
}

//function to reset male database
int reset_male_database()
{
	FILE *fp;
	int i;
	fp = fopen("male_db.dat","w");
	for(i=0;i<5;i++)
	{
		printf("enter the product id:\t");
		scanf("%d",&m_item.prod_id);
		printf("Enter the product name:");
		scanf("%s",m_item.prod_name);
		printf("enter the rate of the product:\t");                                            
		scanf("%d",&m_item.prod_rate);
		printf("enter the stock quantity:\t");
		scanf("%d",&m_item.prod_quantity);
		fwrite(&m_item,sizeof(struct male_fashion),1,fp);	
	}
	fclose(fp);
	return 0;
}

//---function to display male fashion items 
int disp_male_prod()
{
	FILE *fp;
	fp = fopen("male_db.dat","r");
	printf("\n\n-----MALE MENU-----\n");
	while(fread(&m_item,sizeof(struct male_fashion),1,fp))
	{
		printf("\nproduct id : %d\t",m_item.prod_id);
		printf("name : %s\t",m_item.prod_name);
		printf("rate : %d\t",m_item.prod_rate);
		printf("stock quantity : %d\t",m_item.prod_quantity);


	}	
	fclose(fp);
	return 0;
}
//---function to edit male fashion products
int edit_male_prod()
{
	FILE *fp, *fp_temp;
	int choice=1,entry;
	while(choice==1)
	{
		printf("\nenter product id of product to be edidted :\t\n");
		//---opening database file in append mode
		//---opening temporary file in write mode
		fp = fopen("male_db.dat","a+");
		fp = fopen("male_db.dat","r");
		fp_temp = fopen("temp.dat","w");
		if(fp==NULL)
		{
			printf("file cannot be openned\n");
		}

		scanf("%d",&entry);
		//---comparing product id of each product with entry given by user
		while(fread(&m_item,sizeof(struct male_fashion),1,fp))
		{
			if(m_item.prod_id==entry)
			{											
				printf("enter the new rate :\t");
				scanf("%d",&m_item.prod_rate);
				printf("enter the new quantity :\t");
				scanf("%d",&m_item.prod_quantity);
				fwrite(&m_item,sizeof(struct male_fashion),1,fp_temp);			//writting edited product to temporary file
				
			}
			else
			{
				fwrite(&m_item,sizeof(struct male_fashion),1,fp_temp);			//writting rest of the product to temporary file
			}

		}
		fclose(fp);
		fclose(fp);
		fclose(fp_temp);
		//---writting data of temporary file to database file
		fp = fopen("male_db.dat","w");
		fp_temp = fopen("temp.dat","r");
		while(fread(&m_item,sizeof(struct male_fashion),1,fp_temp))
		{
			fwrite(&m_item,sizeof(struct male_fashion),1,fp);
		}
		fclose(fp);
		fclose(fp_temp);
		printf("press 1 to edit more male product :\t\n");
		scanf("%d",&choice);

	}
	return 0;
}


//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------


int reset_female_database()
{
	FILE *fp;
	int i;
	fp = fopen("female_db.dat","w");
	for(i=0;i<5;i++)
	{
		printf("enter the product id:\t");
		scanf("%d",&f_item.prod_id);
		printf("enter the product name:\t");
		scanf("%s",f_item.prod_name);
		printf("enter the rate of the product:\t");                                            
		scanf("%d",&f_item.prod_rate);
		printf("enter the stock quantity:\t");
		scanf("%d",&f_item.prod_quantity);
		fwrite(&f_item,sizeof(struct female_fashion),1,fp);	
	}
	fclose(fp);
	return 0;
}

//function to 
int disp_female_prod()
{
	FILE *fp;
	fp = fopen("female_db.dat","r");
	printf("\n\n-----FEMALE MENU-----\n");
	while(fread(&f_item,sizeof(struct female_fashion),1,fp))
	{
		printf("\nproduct id : %d\t",f_item.prod_id);
		printf("name : %s\t",f_item.prod_name);
		printf("rate : %d\t",f_item.prod_rate);
		printf("stock quantity : %d\t",f_item.prod_quantity);
	}	
	fclose(fp);
	return 0;
}

int edit_female_prod()
{
	FILE *fp, *fp_temp;
	int choice=1,entry;
	while(choice==1)
	{
		printf("\nenter product id of product to be edidted :\t\n");
	
		fp = fopen("female_db.dat","a+");

		fp_temp = fopen("temp.dat","w");
		if(fp==NULL)
		{
			printf("file cannot be openned\n");
		}
		fp = fopen("female_db.dat","r");
		scanf("%d",&entry);

		while(fread(&f_item,sizeof(struct female_fashion),1,fp))
		{
			if(f_item.prod_id==entry)
			{
				printf("enter the new rate :\t");
				scanf("%d",&f_item.prod_rate);
				printf("enter the new quantity :\t");
				scanf("%d",&f_item.prod_quantity);
				fwrite(&f_item,sizeof(struct female_fashion),1,fp_temp);
				
			}
			else
			{
				fwrite(&f_item,sizeof(struct female_fashion),1,fp_temp);
			}

		}
		fclose(fp);
		fclose(fp);
		fclose(fp_temp);

		fp = fopen("female_db.dat","w");
		fp_temp = fopen("temp.dat","r");
		while(fread(&f_item,sizeof(struct female_fashion),1,fp_temp))
		{
			fwrite(&f_item,sizeof(struct female_fashion),1,fp);
		}
		fclose(fp);
		fclose(fp_temp);
		printf("press 1 to edit more female product :\t\n");
		scanf("%d",&choice);

	}
	return 0;
}
