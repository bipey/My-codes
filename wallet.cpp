#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

	char id[40]="9876543211",logid[40];
	char pw[40],logpw[40];
	float balance,amount;
	char fname[30],lname[30];
	
int login();
int signup();
int menu();
int load();
int send();
int bank();
int bill();
int kyc();
int logout();
int exitmenu();
/*===========================================================================
===============================================================================*/
int main()
{
	system("cls");
	printf("\n\t\t\tDigital wallet\n");
		printf("\n\t\t==========================================\n");
	int log;
	printf("\t\tDo you have an user id?\n\t\tIf yes then press 1 to sign in.\n\t\tIf not then please press 2 to sign up\n	");
	printf("\n\t\t==========================================\n");
	printf("\nselect your option:");
	scanf("%d",&log);
	system("cls");
	switch(log){
		case 1:
			login();
			break;
			case 2:
				signup();
	default:
		main();
	}
	return 0;
}
/*============================================================================
===============================================================================*/
login(){
	FILE *fp;
	fp=fopen("bank.txt","a+");
printf("\n\n");
	printf("\t\tEnter your id:");
	scanf("%s",id);
	printf("\t\tEnter your password:");
	scanf("%s",pw);
	system("cls");
	if(strcmp(id,"9876543211")==0&&strcmp(pw,"1@bk")==0){
		fprintf(fp,"%s\n%s\n",id,pw);
	system("cls");
	strcpy(fname,"abc");
	printf("\n\t\t\t\twelcome %s",fname);
	menu();
	}
	else if(strcmp(id,logid)==0&&strcmp(pw,logpw)==0){
			fprintf(fp,"%s\n%s\n",id,pw);
	fclose(fp);
			printf("\t\t\t\tWelcome %s",fname);
			//	balance=0.0;
				menu();	
	}
	else{
	printf("\t\tYour id doesnt match\n\n");
	printf("press any key to continue....");
	getch();
	system("cls");
		login();
	}
return 0;}
/*==========================================================================
=============================================================================*/
signup(){
	FILE *fptr;
	fptr=fopen("signup.txt","a+");
	char otp[6];
	printf("\t\tEnter your first name: ");
	scanf("%s",fname);
		printf("\t\tEnter your last name: ");
	scanf("%s",lname);
	//fprintf(fptr,"fname=%s\n lname=%s\n",fname,lname);
//	fclose(fptr);
	logid:
	printf("\t\tEnter your mobile number:");
	scanf("%s",logid);
	
	if(strcmp(logid,id)==0){
		printf("\n\t\tSorry the user is already registered\nPlease try with the another number\n");
		printf("press any key to continue");
			getch();
		system("cls");
	signup();
}else{
	if(logid[10]!='\0'|| logid[9]=='\0' || logid[8]=='\0')
{
printf("\n\t\tInvalid mobile number\n");
getch();
system("cls");
goto logid;
}
else{
	goto logpw;}
	logpw:
		printf("\t\tEnter your password:");
	scanf("%s",logpw);
		if(logpw[4]!='\0'|| logpw[3]=='\0' || logpw[2]=='\0'){
			printf("\n\t\tInvalid password\n\t\tPlease press any key to try again...");	
			goto logpw;
		}
		else{
			otp:
				printf("\nWe have sent yoou an otp in your mobile number.Please enter it for confirmation.\n");
				scanf("%s",&otp);
				if(strcmp(otp,"abcd")==0){
		fprintf(fptr,"\n\nfname=%s\n lname=%s\nlogid=%s\nlogpw=%s",fname,lname,logid,logpw);
						fclose(fptr);
					getch();
					printf("Press any key too continue...");
					system("cls");
					login();
				}
				else{
				printf("Sorry wrong otp.Please try again");
				goto otp;
				}
}		}

return 0;
}
/*=================================================================
==================================================================*/
int menu()
{
int option;
		printf("\n\n\t\t\tYour balance is RS.%.1f\n",balance);
		printf("\n\t\t==========================================\n");
	printf("\t\t1>>Load wallet		2>>Send Money\n\t\t3>> Bank Transfer	4>>Bill payment\n\t\t5>>Kyc			6>>logout");
		printf("\n\t\t==========================================\n");
		printf("\t\tPlease select your option:");
		scanf("%d",&option);
		printf("Press any key to continue...");
		getch();
		system("cls");
		switch(option){
			case 1:
				load();
				break;
			case 2:
				send();
				break;
			case 3:
				bank();
				break;
			case 4:
				bill();
				break;
			case 5:
				kyc();
				break;
			case 6:
				logout();
				break;
		}
return 0;
}
/*=========================================================================
===========================================================================*/
int load(){
	char destid[30];
		printf("\n\t\tPlease make sure that to use this feature your bank account and the wallet id should be connected using the same mobile number");
destid:
	printf("\n\n\t\tEnter the bank acount number from where you want to load your wallet: ");
	scanf("%s",&destid);
	if(destid[16]!='\0'|| destid[15]=='\0' || destid[14]=='\0'){
	printf("\t\tInvalid account number.Please enter a valid account");
	goto destid;
	}
	else{
	printf("\n\t\tEnter the amount:");
	scanf("%f",&amount);
	printf("\n\n\t\tTo verify the transaction we have sent you otp on your mobile number\nplease enter to verify\n\n");
otp:
	int otp;
	printf("OTP:");
	scanf("%d",&otp);
	if(otp==1111){
					balance=balance+amount;
					system("cls");
					
				printf("\t\tDear %s, your account has been debited by Rs.%f from account number %s",fname,amount,destid);
				getch();
					printf("Press any key too continue...");
					system("cls");
				exitmenu();
				}
				else{
				printf("\t\tSorry wrong otp.Please try again");
				goto otp;
				}
	}
}
/*=======================================================================
==========================================================================*/
int send(){
	char destid[30];
	destid:
	printf("\t\tEnter wallet id of destination account:");
	scanf("%s",destid);
	if(destid[10]!='\0'|| destid[9]=='\0' || destid[8]=='\0'){
		printf("\n\t\tPlease enter a valid id\n\n");
		goto destid;}
		else{
			char pin[30];
			amount:
			printf("\t\tPlease enter the amount you want to transfer:");
			scanf("%f",&amount);
			if(amount<=balance){
				pin:
				printf("\t\tPlease enter your pin:");
				scanf("%s",pin);
				system("cls");
				if(strcmp(pw,pin)==0){
					balance=balance-amount;
					system("cls");
					printf("\t\tyour amount has been credited by Rs.%f to %s\n\n",amount,destid);
						getch();
					system("cls");
					exitmenu();
				}
				else{
					
					printf("\t\tPlease enter the correct pin\n");
					goto pin;
				}
			}
			else{
			printf("\t\tSorry you dont have sufficent balance.please enter the correct amount");
			goto amount;
		}
					}
}
/*==============================================================================
================================================================================*/
int bank(){
	char destid[30];
	destid:
	printf("\n\n\t\tEnter bank account number of destination account:");
	scanf("%s",destid);
	if(destid[16]!='\0'|| destid[15]=='\0' || destid[14]=='\0'){
		printf("\n\t\tPlease enter a valid account number\n\n");
		goto destid;}
		else{
			char pin[30];
			amount:
			printf("\n\t\tPlease enter the amount you want to transfer:");
			scanf("%f",&amount);
			if(amount<=balance){
				pin:
				printf("\n\t\tPlease enter your pin:");
				scanf("%s",pin);
				if(strcmp(pw,pin)==0){
					balance=balance-amount;
					system("cls");
						printf("\t\tyour amount has been credited by Rs.%f to bank account %s",amount,destid);
					exitmenu();
				}
				else{
					printf("Please enter the correct pin\n");
					goto pin;
				}
			}
			else{
			printf("\t\tSorry you dont have sufficent balance.please enter the correct amount");
			goto amount;
		}
					}
}

/*==============================================================================
================================================================================*/
int bill(){
	int bill,uid;
	char btype[30],pin[30];
	bill:
						printf("\n\t\t====================================================================================\n");
	printf("\n\t\twhich bill you want to pay?\n\n\t\t1>Water bill\t2>Electricity bill\t3>Internet bill");
		printf("\n\t\t====================================================================================\n");
		printf("please enter your choice:");
	scanf("%d",&bill);
	system("cls");
	switch(bill){
		case 1:
			strcpy(btype,"Water");
			goto pay;
			break;
				case 2:
			strcpy(btype,"Electricity");
			goto pay;
			break;
				case 3:
			strcpy(btype,"Internet");
			goto pay;
			break;
			default:
				printf("\n\t\tWrong input.\n Pleae try again");
				goto bill;
	}
	pay:
		printf("\n\t\tEnter your user id:");
		scanf("%d",&uid);
		amount:
		printf("\t\tEnter amount:");
		scanf("%f",&amount);
			if(amount<=balance){
				pin:
				printf("\t\tPlease enter your pin:");
				scanf("%s",pin);
				if(strcmp(pw,pin)==0){
					balance=balance-amount;
					system("cls");
					printf("\n\n\t\t%s bill of Rs.%f has been paid.",btype,amount);
					getch();
					exitmenu();
				}
				else{
					printf("\n\n\t\tPlease enter the correct pin\n");
					goto pin;
				}
			}
			else{
			printf("\n\t\tSorry you dont have sufficent balance.please enter the correct amount");
			goto amount;
					}
				}
/*=========================================================================
==========================================================================*/
int kyc(){
		FILE *kyc;
	kyc=fopen("kyc.txt","w+");
		kyc:
			int year,month,day;
			char fatherf[10],fatherl[10],motherf[10],motherl[10];
			char dnum[30],doc[20];
			printf("\n\t\tPlease fill up the form below\n\n");
				printf("\t\tYour name is %s %s\n",fname,lname);
				dob:
				printf("\n\tDate of birth\n\n");
				printf("\n\tEnter year(in bs):");
		scanf("%d",&year);
				printf("\n\tEnter month:");
		scanf("%d",&month);
		printf("\n\tEnter day:");
		scanf("%d",&day);
		if((year>=1988&&year<=2061)&&(month<=12)&&(day<=32)){
			fprintf(kyc,"Year=%d\nmonth=%d\nday=%d",year,month,day);
			goto details;
		}
		else {
		printf("\nInvalid date of birth\nPlease try again");
		getch();
		system("cls");
		goto dob;}
			details:
			printf("\nFather's first name: ");
			scanf("%s",fatherf);
			printf("\nFather's last name: ");
			scanf("%s",fatherl);
			printf("\nMother's first name: ");
			scanf("%s",motherf);
			printf("\nMother's last name: ");
			scanf("%s",motherl);
			fprintf(kyc,"Name:%s %s\nfather name: %s %s\nMother name: %s %s\n",fname,lname,fatherf,fatherl,motherf,motherl);
		dtype:
			printf("\nDocument type\n1>>Citizenship	2>>Passport\n");
			int dtype;
			scanf("%d",&dtype);
			switch(dtype){
			case 1:
			printf("Enter citizenship number:");
					scanf("%s",dnum);
				strcpy(doc,"Citizenship");
			fprintf(kyc,"Document Type: %s\n%s number:%s",doc,doc,dnum);
					break;
					case 2:
					printf("Enter passport number:");
					scanf("%s",dnum);
					strcpy(doc,"Passport");
					fprintf(kyc,"Document Type: %s\n%s number:%s",doc,doc,dnum);
					break;
					default:
						printf("wrong input\n");
						goto dtype;			
		}
		fclose(kyc);
system("cls");
		printf("\n\n\t\t\t\tyour details\n");
		printf("\t\t=======================================\n");
		printf("\t\tName:%s %s\n",fname,lname);
		printf("\t\tDate of birth: %d/%d/%d\n",year,month,day);
		printf("\t\tfather name: %s %s\n",fatherf,fatherl);
		printf("\t\tMother name: %s %s\n",motherf,motherl);
		printf("\t\tDocument Type: %s\n",doc);
		printf("\t\t%s number:%s",doc,dnum);
			printf("\n\t\t=======================================\n");
			getch();
			system("cls");
exitmenu();
}

/*=========================================================================
========================================================================*/
int logout(){
	int logout;
	logout:
	printf("\t\tDo you want to logout?\n\n\t\t1>>Yes\t\t2>>No\n");
	scanf("%d",&logout);
	system("cls");
	switch(logout){
		case 1:
			main();
			break;
			case 2:
				menu();
				break;
				default:
					printf("\n\tSorry wrong input.");
					logout;
	}
}
/*=============================================================
=============================================================*/
int exitmenu(){
	int exit;
	exitmenu:
	printf("\n\n\t\tTo return back to main menu press 1\n\t\tPress any other key to exit the system\n");
	scanf("%d",&exit);
	system("cls");
	switch(exit){
		case 1:
			menu();
			break;
				default:
				goto end;
					break;
				}
end:
		return 0;
}
/*===========================================================================
=============================================================================*/
