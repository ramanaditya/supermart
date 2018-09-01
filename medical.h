//defining structure medical section
struct medical_sec
{
	int prod_id;
	char prod_name[20];
	int prod_rate;
	int prod_quantity;
}care_item;

//for displaying the product.
int disp_prod()
{
	FILE *fp;
	fp=fopen("medical_db.dat","r");
	printf("\n\n-----Medical Menu-----\n");
	while(fread(&care_item,sizeof(struct medical_sec),1,fp))
	{
		printf("\nproduct id : %d\t",care_item.prod_id);
		printf("name : %s\t",care_item.prod_name);
		printf("rate : %d\t",care_item.prod_rate);
		printf("stock quantity : %d\t",care_item.prod_quantity);
	}	
	fclose(fp);
	return 0;
}



//for editing the database
int edit_prod()
{
	FILE *fp, *fp_temp;
	int choice=1,entry;
	while(choice==1)
	{
		printf("\n\nEnter product id of product to be edidted :\t\n");
	
		fp = fopen("medical_db.dat","a+");
		fp_temp = fopen("temp.dat","w");
		if(fp==NULL)
		{
			printf("file cannot be openned\n");
		}

		scanf("%d",&entry);
		fp=fopen("medical_db.dat","r");
		while(fread(&care_item,sizeof(struct medical_sec),1,fp))
		{

			if(care_item.prod_id==entry)
			{
				printf("enter the new rate :\t");
				scanf("%d",&care_item.prod_rate);
				printf("enter the new quantity :\t");
				scanf("%d",&care_item.prod_quantity);
				fwrite(&care_item,sizeof(struct medical_sec),1,fp_temp);
				
			}
			else
			{
				fwrite(&care_item,sizeof(struct medical_sec),1,fp_temp);
			}

		}
		fclose(fp);
		fclose(fp);
		fclose(fp_temp);

		fp = fopen("medical_db.dat","w");
		fp_temp = fopen("temp.dat","r");
		while(fread(&care_item,sizeof(struct medical_sec),1,fp_temp))
		{
			fwrite(&care_item,sizeof(struct medical_sec),1,fp);
		}
		fclose(fp);
		fclose(fp_temp);
		printf("\npress 1 to edit more product :\t\n");
		scanf("%d",&choice);

	}
	return 0;
	

}



/*
1. vitamins
2. cough syrup
3. health suppliments
4. Antibiotics
5. Condoms
*/
int reset_database()
{
	FILE *fp;
	int i;
	fp = fopen("medical_db.dat","w");
	for(i=0;i<5;i++)
	{
		printf("enter the product id:\t");
		scanf("%d",&care_item.prod_id);
		printf("Enter the product name:\t");
		scanf("%s",care_item.prod_name);
		printf("enter the rate of the product:\t");                                            
		scanf("%d",&care_item.prod_rate);
		printf("enter the stock quantity:\t");
		scanf("%d",&care_item.prod_quantity);
		fwrite(&care_item,sizeof(struct medical_sec),1,fp);	
	}
	fclose(fp);
	return 0;
}

int disp_medical_list()
{
	printf("\n\n-----Medical Menu-----\n");
	printf("1. vitamins\t\t2. cough syrup\n3. health suppliments\t\t4. Antibiotics\n5. Pain Reliever\n");
	return 0;
}



