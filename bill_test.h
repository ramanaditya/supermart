

#include<time.h>

struct bill
{
	int bill_id;
	int b_total;
	struct 
	{
		int p_id;
		char p_name[20];
		int p_rate;
		int p_quantity;
		int p_total;
	}prod;
}bil;

int calcbill()
{
	int choice,chk,id,quantity,total,m_total,f_total,d_total,e_total,med_total;
	char name[20];
	time_t mytime;
	mytime = time(NULL);
	FILE *fp,*fp7,*fp_temp,*fp_bill_temp,*fp_bill;
	chk=1; total=0; m_total=0,f_total=0,d_total=0,e_total=0,med_total=0;
	fp_bill_temp = fopen("bill_temp.dat","w");
	bil.bill_id++;
	do
	{
		printf("\n1.Male fashion\n2.Female fashion\n3.Daily uses\n4.electronics\n5.Medicines\n0. Total\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : disp_male_menu();
					 total=0;
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
				 				bil.prod.p_id = m_item.prod_id;
				 				strcpy(bil.prod.p_name,m_item.prod_name);
				 				bil.prod.p_rate = m_item.prod_rate;
				 				bil.prod.p_quantity = quantity;
				 				bil.prod.p_total = (m_item.prod_rate)*(quantity);
				 				total = total + bil.prod.p_total;
				 				//total = total +((m_item.prod_rate)*(quantity));
				 				//bil.prod.p_total = total;
				 				fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
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
				 				//total = total +((f_item.prod_rate)*(quantity));
				 				bil.prod.p_id = f_item.prod_id;
				 				strcpy(bil.prod.p_name,f_item.prod_name);
				 				bil.prod.p_rate = f_item.prod_rate;
				 				bil.prod.p_quantity = quantity;
				 				
				 				bil.prod.p_total = (f_item.prod_rate)*(quantity);
				 				total = total + bil.prod.p_total;

								//bil.prod.p_total = total;
								fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
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
				 				//total = total +((daly.prod_rate)*(quantity));
				 				bil.prod.p_id = daly.prod_id;
				 				strcpy(bil.prod.p_name,daly.prod_name);
				 				bil.prod.p_rate = daly.prod_rate;
				 				bil.prod.p_quantity = quantity;
				 				bil.prod.p_total = (daly.prod_rate)*(quantity);
				 				total = total + bil.prod.p_total;
				 				
								//bil.prod.p_total = total;
								fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
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
				 				//total = total +((ele_item.prod_rate)*(quantity));
				 				bil.prod.p_id = ele_item.prod_id;
				 				strcpy(bil.prod.p_name,ele_item.prod_name);
				 				bil.prod.p_rate = ele_item.prod_rate;
				 				bil.prod.p_quantity = quantity;
				 				bil.prod.p_total = (ele_item.prod_rate)*(quantity);
				 				total = total + bil.prod.p_total;
				 				
								//bil.prod.p_total = total;
								fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
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
				 				//total = total +((care_item.prod_rate)*(quantity));
				 				bil.prod.p_id = care_item.prod_id;
				 				strcpy(bil.prod.p_name,care_item.prod_name);
				 				bil.prod.p_rate = care_item.prod_rate;
				 				bil.prod.p_quantity = quantity;
				 				bil.prod.p_total = (care_item.prod_rate)*(quantity);
				 				total = total + bil.prod.p_total;
				 				
								//bil.prod.p_total = total;
								fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
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
	}
	while(choice!=0);
	total= m_total+f_total+d_total+e_total+med_total;
		
		//fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);
	fclose(fp_bill_temp);
		//fp_bill_temp=fopen("bill_temp.dat", "a");
		//bil.b_total=total;	
		//fwrite(&bil,sizeof(struct bill),1,fp_bill_temp);	
		//fclose(fp_bill_temp);
		/*fp_bill_temp = fopen("bill_temp.dat","r");
		fread(&bil,sizeof(struct bill),1,fp_bill_temp);
			printf("\nBill iD= %d",bil.bill_id);
		fclose(fp_bill_temp);


		*/
	printf("\n");
	//disp_menu();
		//UNAME=strupr(uname);
	//upper_string(uname);
	

	//printf("%s",uname);
	
	//scanf("%s",name);
	printf("                 ********************************\n                 SIR M VISHESHWARYA SUPERMARKET ©\n               ************************************\n");
	printf("\nName of the customer : ");
	scanf("%s",name);
	printf("\nDate : ");
	printf("%s",ctime(&mytime));
	fp_bill_temp = fopen("bill_temp.dat","r");
	printf("\n\nprod_name\t\trate\tquant\ttotal\n\n");
	while(fread(&bil,sizeof(struct bill),1,fp_bill_temp))
	{
		printf("\n%-18s\t%d\t%d\t%d\t",bil.prod.p_name,bil.prod.p_rate,bil.prod.p_quantity,bil.prod.p_total);
	}
	printf("\n\n\t\t\tTotal bill : %d\n ",total);
	fclose(fp_bill_temp);


	/*	
	fp_bill_temp = fopen("bill_temp.dat","r");
	fread(&bil,sizeof(struct bill),1,fp_bill_temp);
	printf("Bill Total : %d\n",bil.b_total);
	fclose(fp_bill_temp);
	

		
	fp_bill= fopen("bill.dat", "w");
	fp_bill_temp = fopen("bill_temp.dat","r");
	while(fread(&bil,sizeof(struct bill),1,fp_bill_temp))
	{
		fwrite(&bil,sizeof(struct bill),1,fp_bill);
	}
	fclose(fp_bill);
	fclose(fp_bill_temp);
	*/	

	
	return 0;
}

/*
int printbill()
{	
	FILE *fp_bill;
	fp_bill = fopen("bill.dat","r");
	fread(&bil,sizeof(struct bill),1,fp_bill);
			printf("\nBill iD= %d",bil.bill_id);
	fclose(fp_bill);
	fp_bill = fopen("bill.dat","r");
	printf("\n\n\n");
	//printf(ctime(&mytime));
	printf("\nprod_name\trate\tquant\ttotal");
	while(fread(&bil,sizeof(struct bill),1,fp_bill))
	{
		printf("\n%s\t%d\t%d\t%d\t",bil.prod.p_name,bil.prod.p_rate,bil.prod.p_quantity,bil.prod.p_total);
	}
	printf("\nTotal bill : %d\n ",total);
	fclose(fp_bill);
	
	return 0;
}
*/