int calc_bill()
{
	int choice,chk,id,quantity,total,m_total,f_total,d_total,e_total,med_total;
	FILE *fp,*fp_temp;
	chk=1;
	total=0;
	m_total=f_total=d_total=e_total=med_total=0;
	do
	{
		printf("\n1.Male fashion\n2.Female fashion\n3.Daily uses\n4.electronics\n5.Medicines\n0. Total\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : disp_male_menu();
					 do
				 	{
				 		printf("\nenter product id :");
				 		scanf("%d",&id);
					 	printf("\nenter quantity : ");
					 	scanf("%d",&quantity);

					 	fp = fopen("male_db.dat","a+");
					 	fp = fopen("male_db.dat","r");
					 	fp_temp = fopen("temp.dat","w");
					 	while(fread(&m_item,sizeof(struct male_fashion),1,fp))
					 	{
					 		if(m_item.prod_id==id)
				 			{
				 				total = total +((m_item.prod_rate)*(quantity));
				 				m_item.prod_quantity = m_item.prod_quantity - quantity;
				 				fwrite(&m_item,sizeof(struct male_fashion),1,fp_temp);
				 			}
					 		else
							{
								fwrite(&m_item,sizeof(struct male_fashion),1,fp_temp);			//writting rest of the product to temporary file
							}

					 	}
					 	fclose(fp);
					 	fclose(fp);
					 	fclose(fp_temp);
					 	fp = fopen("male_db.dat","w");
						fp_temp = fopen("temp.dat","r");
						while(fread(&m_item,sizeof(struct male_fashion),1,fp_temp))
						{
							fwrite(&m_item,sizeof(struct male_fashion),1,fp);
						}
						fclose(fp);
						fclose(fp_temp);
						printf("\npress 1 to add more male items : ");
						scanf("%d",&chk);
					 }while(chk==1);
					 //disp_male_prod();
					 m_total=total;
					 //printf("total : %d\n",m_total);
					 break; 
		
			case 2 : disp_female_menu();
					 total = 0;
					 do
					 {
					 	printf("\nenter product id :");
					 	scanf("%d",&id);
					 	printf("\nenter quantity : ");
				 		scanf("%d",&quantity);

					 	fp = fopen("female_db.dat","a+");
					 	fp = fopen("female_db.dat","r");
					 	fp_temp = fopen("temp.dat","w");
					 	while(fread(&f_item,sizeof(struct female_fashion),1,fp))
					 	{
					 		if(f_item.prod_id==id)
				 			{
				 				total = total +((f_item.prod_rate)*(quantity));
				 				f_item.prod_quantity = f_item.prod_quantity - quantity;
					 			fwrite(&f_item,sizeof(struct female_fashion),1,fp_temp);
					 		}
					 		else
							{
								fwrite(&f_item,sizeof(struct female_fashion),1,fp_temp);			//writting rest of the product to temporary file
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
						printf("\npress 1 to add more female items : ");
						scanf("%d",&chk);
					 }while(chk==1);
					 //disp_female_prod();
					 f_total=total;
					 //printf("total : %d\n",f_total);
					 break;		 

			case 3 : disp_daily_list();
					 total = 0;
					 do
					 {
					 	printf("\nenter product id :");
					 	scanf("%d",&id);
					 	printf("\nenter quantity : ");
				 		scanf("%d",&quantity);

					 	fp = fopen("daily_db.dat","a+");
					 	fp = fopen("daily_db.dat","r");
					 	fp_temp = fopen("temp.dat","w");
					 	while(fread(&daly,sizeof(struct daily),1,fp))
					 	{
					 		if(daly.prod_id==id)
				 			{
				 				total = total +((daly.prod_rate)*(quantity));
				 				daly.prod_quantity = daly.prod_quantity - quantity;
					 			fwrite(&daly,sizeof(struct daily),1,fp_temp);
					 		}
					 		else
							{
								fwrite(&daly,sizeof(struct daily),1,fp_temp);			//writting rest of the product to temporary file
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
						printf("\npress 1 to add more daily uses items : ");
						scanf("%d",&chk);
					 }while(chk==1);
					 //disp_daily_prod();
					 d_total=total;
					 //printf("total : %d\n",d_total);
					 break;	

			case 4 : disp_e_menu();
					 total = 0;
					 do
					 {
					 	printf("\nenter product id :");
					 	scanf("%d",&id);
					 	printf("\nenter quantity : ");
				 		scanf("%d",&quantity);

					 	fp = fopen("electronics_db.dat","a+");
					 	fp = fopen("electronics_db.dat","r");
					 	fp_temp = fopen("temp.dat","w");
					 	while(fread(&ele_item,sizeof(struct electronics_sec),1,fp))
					 	{
					 		if(ele_item.prod_id==id)
				 			{
				 				total = total +((ele_item.prod_rate)*(quantity));
				 				ele_item.prod_quantity = ele_item.prod_quantity - quantity;
					 			fwrite(&ele_item,sizeof(struct electronics_sec),1,fp_temp);
					 		}
					 		else
							{
								fwrite(&ele_item,sizeof(struct electronics_sec),1,fp_temp);			//writting rest of the product to temporary file
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
						printf("\npress 1 to add more electronics items : ");
						scanf("%d",&chk);
					 }while(chk==1);
					 //disp_e_prod();
					 e_total=total;
					 //printf("total : %d\n",e_total);
					 break;	

			case 5 : disp_medical_list();
					 total = 0;
					 do
					 {
					 	printf("\nenter product id :");
					 	scanf("%d",&id);
					 	printf("\nenter quantity : ");
				 		scanf("%d",&quantity);

					 	fp = fopen("medical_db.dat","a+");
					 	fp = fopen("medical_db.dat","r");
					 	fp_temp = fopen("temp.dat","w");
					 	while(fread(&care_item,sizeof(struct medical_sec),1,fp))
					 	{
					 		if(care_item.prod_id==id)
				 			{
				 				total = total +((f_item.prod_rate)*(quantity));
				 				care_item.prod_quantity = care_item.prod_quantity - quantity;
					 			fwrite(&care_item,sizeof(struct medical_sec),1,fp_temp);
					 		}
					 		else
							{
								fwrite(&care_item,sizeof(struct medical_sec),1,fp_temp);			//writting rest of the product to temporary file
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
						printf("\npress 1 to add more medical items : ");
						scanf("%d",&chk);
					 }while(chk==1);
					 //disp_prod();
					 med_total=total;
					 //printf("total : %d\n",med_total);
					 break;	

			default :printf("\n"); break;	 
		}
	}while(choice!=0);

	total= m_total+f_total+d_total+e_total+med_total;
	printf("Total bill : %d\n ", total);
	return 0;
}