//defining structure electronics section
struct electronics_sec
{
	int prod_id;
	char prod_name[20];
	int prod_rate;
	int prod_quantity;
}ele_item;

//for displaying the product.
int disp_e_prod()
{
	FILE *fp;
	fp=fopen("electronics_db.dat","r");
	printf("\n\n-----Electronics Menu-----\n");
	while(fread(&ele_item,sizeof(struct electronics_sec),1,fp))
	{
		printf("\nproduct id : %d\t",ele_item.prod_id);
		printf("name : %s\t",ele_item.prod_name);
		printf("rate : %d\t",ele_item.prod_rate);
		printf("stock quantity : %d",ele_item.prod_quantity);
	}	
	fclose(fp);
	return 0;
}



//for editing the database
int edit_e_prod()
{
	FILE *fp, *fp_temp;
	int choice=1,entry;
	while(choice==1)
	{
		
	
		fp = fopen("electronics_db.dat","a+");
		fp_temp = fopen("temp.dat","w");
		if(fp==NULL)
		{
			printf("file cannot be openned\n");
		}
		fp = fopen("electronics_db.dat","r");
		printf("\nEnter product id of product to be edidted :\t\n");
		scanf("%d",&entry);

		while(fread(&ele_item,sizeof(struct electronics_sec),1,fp))
		{

			if(ele_item.prod_id==entry)
			{
				printf("enter the new rate :\t");
				scanf("%d",&ele_item.prod_rate);
				printf("enter the new quantity :\t");
				scanf("%d",&ele_item.prod_quantity);
				fwrite(&ele_item,sizeof(struct electronics_sec),1,fp_temp);
				
			}
			else
			{
				fwrite(&ele_item,sizeof(struct electronics_sec),1,fp_temp);
			}

		}
		fclose(fp);
		fclose(fp);
		fclose(fp_temp);

		fp = fopen("electronics_db.dat","w");
		fp_temp = fopen("temp.dat","r");
		while(fread(&ele_item,sizeof(struct electronics_sec),1,fp_temp))
		{
			fwrite(&ele_item,sizeof(struct electronics_sec),1,fp);
		}
		fclose(fp);
		fclose(fp_temp);
		printf("\npress 1 to edit more electronics product :\t\n");
		scanf("%d",&choice);

	}
	return 0;
	

}



/*
1. Mini Speakers
2. Earphones-Wired
3. Earphones-Wireless
4. Power Banks-10000 mAh
5. Memory Cards-32 GB
6. Flash Drives-32 GB
7. Routers
8. Portable Hard Drivers-1 TB
*/
int reset_e_database()
{
	FILE *fp;
	int i;
	fp = fopen("electronics_db.dat","w");
	for(i=0;i<8;i++)
	{
		printf("enter the product id:\t");
		scanf("%d",&ele_item.prod_id);
		printf("Enter the product name:\t");
		scanf("%s",ele_item.prod_name);
		printf("enter the rate of the product:\t");                                            
		scanf("%d",&ele_item.prod_rate);
		printf("enter the stock quantity:\t");
		scanf("%d",&ele_item.prod_quantity);
		fwrite(&ele_item,sizeof(struct electronics_sec),1,fp);	
	}
	fclose(fp);
	return 0;
}

int disp_e_menu()
{
	printf("\n-----Electronics Menu-----\n1.Mini Speakers\t2.Earphones-Wired\n3.Earphones-Wireless\t\t4.Power Banks-10000 mAh\n5.Memory Cards-32 GB\t\t6.Flash Drives-32 GB\n7.Routers\t\t8.Portable Hard Drivers-1 TB\n0.Go back to precious menu\n");
	return 0;
}



