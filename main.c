#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaring main functions
void login();
void Secretary_fun();
void Main_coach_fun();
void Physical_fitness_coach_fun();
void Assistant_coach_fun();

//Declaring sub functions
void payment();
void registration();

void genReporting();
void trackFitness();

//structure to store player data in system
struct RegiSystem
{
int playerid;
char gender;
char fname[50];
char lname[50];
}Prosp_plyr[20];

struct payment
{
char firstname[50];
char lastname[50];
int id;
float amtpaid;
}player[50];

struct progress
{
char firstname[50];
char lastname[50];
int id;
char notes[500];
int won;
 int rank;
 }plyr[50];
 
 struct fitness
 {
 char firstname[50];
 char lastname[50];
 int id;
 char activity[200];
 char healthconds[500];
 }ply[50];
 
 //main
 
 int main()
 {
 login();
 return 0;
 }
 
 //login function
 void login()
 {
 char UserName[50];
 char PassWord[50];
 char Usect[]="PLewis";
 char Psect[]="sectGPTTC";
 char Umain[]="MWilson";
 char Pmain[]="mCoach";
 char Ufit[]="MBrown";
 char Pfit[]="FitCoach";
 char Uassist[]="MWilliams";
 char Passist[]="AsstCoach";
 
 system("cls");
 printf("**********GREATER PORTMORE TABLE TENNIS 
CLUB*************\n\n\n");
 printf("Please Enter Username: ");
 scanf("%s", UserName);
 printf("Please Enter Password: ");
 
 scanf("%s", PassWord);
 //if...else statement to test if the input is the correct username.
 
 
 
 if (strcmp(Usect,UserName)==0&&strcmp(Psect,PassWord)==0)
 {
 system("cls");
 
 printf("*********************Welcome Miss Lewis!
****************\n\n\n");
 Secretary_fun();
 
 
 }
 if (strcmp(Umain,UserName)==0&&strcmp(Pmain,PassWord)==0){
 system("cls");
 printf("*******************Welcome Mr. Wilson!!
***************\n\n");
 Main_coach_fun();
 }
 if(strcmp(Ufit,UserName)==0&&strcmp(Pfit,PassWord)==0){
 system("cls");
 printf("********************Welcome Mr. Brown!!
***************\n\n");
 Physical_fitness_coach_fun();
 }
 if (strcmp(Uassist,UserName)==0&&strcmp(Passist,PassWord)==0){
 system("cls");
 printf("*********************Welcome Miss Williams!!
************\n\n");
 Assistant_coach_fun();
 } else{
 printf("Username or Password incorrect please try again\n\n");
 system("pause");
 system("cls");
 login();
 
 }
 
 
 }
 
 
 //main functions
 void Secretary_fun()
 {
 int chc;
 
 
 printf("*********Secretary Section*********\n\n");
 printf("1. Registration.\n");
 printf("2. Payments.\n");
 printf("3. Print reports\n");
 printf("4. logout\n");
 printf("Choose a number ");
 scanf("%d", &chc);
 switch(chc)
 {
 case 1:
 registration();
 break;
 case 2:
 payment();
 break;
 case 3:
 genReporting();
 break;
 case 4:
 login();
 break;
 
 default:
 printf("Incorrect option please try again :)\n ");
 system("pause");
 system("cls");
 Secretary_fun();
 
 
 }
 
 }
 
 void Main_coach_fun()
 {
 int ch, x, num,i;
 char notes[500];
 FILE*ptr;
 printf("******Main Coach Section*********\n\n");
 printf("1. Begin input of player information\n");
 printf("2. Print Report\n");
 printf("3. Logout\n");
 scanf("%d",&ch);
 
 system("cls");
 
 switch (ch)
 {
 case 1:
 ptr=fopen("progress.txt","w");
 printf("Enter the number of records you want to enter\n");
 scanf("%d",&num);
 for(x=0;x<num;x++)
 {
 
 printf("Enter player ID\n");
 scanf("%d",&plyr[x].id);
 printf("Enter player first name\n");
 scanf("%s",plyr[x].firstname);
 printf("Enter player Last Name\n");
 scanf("%s",plyr[x].lastname);
 printf("Enter number of Tournaments won\n");
 scanf("%d",&plyr[x].won);
 printf("Enter player's rank\n");
 scanf("%d",&plyr[x].rank);
 printf("Enter notes on Player\n");
 fflush(stdin);
 gets(notes);
 strcpy(plyr[x].notes,notes);
 
 }
 for(i=0;i<num;i++)
 {
 fprintf(ptr,"%d %s %s %d %d\n 
%s\n\n",plyr[i].id,plyr[i].firstname,plyr[i].lastname,plyr[i].won,plyr[i].rank
,plyr[i].notes);
 }
 
 fclose(ptr);
 system("pause");
 system("cls");
 Main_coach_fun();
 break;
 case 2:
 genReporting();
 case 3:
 login();
 default:
 printf("Incorrect option please try again\n\n");
 system("pause");
 system("cls");
 Main_coach_fun();
 }
 
 
 
 }
 
 void Physical_fitness_coach_fun()
 {//physical fitness programs;keeping track of physical activities by 
players
 
 int chc;
 printf("***************Physical Fitness Coach 
Section*******************\n\n");
 printf("1. Enter activity of player\n");
 printf("2. Generate report.\n");
 printf("3. Logout\n");
 printf("Choice: ");
 scanf("%d",&chc);
 
 switch(chc)
 {
 case 1:
 trackFitness();
 break;
 case 2:
 genReporting();
 break;
 case 3:
 system("cls");
 system("pause");
 login();
 default:
 printf("Incorrect option please try again\n");
 system("pause");
 system("cls");
 Physical_fitness_coach_fun();
 }
 
 
 
 }
 
 void Assistant_coach_fun()
 {
 
 int chc;
 printf("***********Assistant Coach Section*********\n\n");
 printf("1. Print reports\n");
 printf("2. logout\n");
 printf("Choice: ");
 
 scanf("%d",&chc);
 switch (chc)
 {
 case 1:
 genReporting();
 break;
 case 2:
 login();
 
 break;
 default:
 printf("Incorrect Option Please try again\n");
 system("pause");
 system("cls");
 Assistant_coach_fun();
 
 
 }
 
 
 }
 
 /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////
 
 //sub functions down here
 
 
 
 void registration()
 {
 system("cls");
 
 FILE *fp;
 fp = fopen("listing.txt", "w+");
 int x;
 int i;
 printf("\n*********************Registering 
section.*******************\n\n");
 printf("\nHow many players to add? ");
 fflush(stdin);
 scanf("%d", &i);
 for (x=0;x<i;x++)
 {
 
 
 printf("\n\nEnter Player First Name ");
 scanf("%s",Prosp_plyr[x].fname);
 printf("Enter Player Last Name ");
 scanf("%s",Prosp_plyr[x].lname);
 printf("What is the player id no.? ");
 scanf("%d", &Prosp_plyr[x].playerid);
 printf("\nWhat is the gender? ");
 fflush(stdin);
 scanf("%c", &Prosp_plyr[x].gender);
 
 
 
 
 }
 
 for (x=0;x<i;x++)
 {
 fprintf(fp, "%d %c %s %s\n",Prosp_plyr[x].playerid, 
Prosp_plyr[x].gender, Prosp_plyr[x].fname, Prosp_plyr[x].lname);
 
 }
 fclose(fp);
 system("pause");
 system("cls");
 Secretary_fun();
 
 }
 
 
 
 
 
 void genReporting()
 {
 system("cls");
 FILE*fp;
 FILE*filpay;
 FILE*fitPr;
 FILE*ptr;
 int choice,x,i;
 char notes[500];
 char activity[200];
 char healthconds[200];
 
 x=0;
 printf("********Reporting section********\n\n");
 printf("1. Registration report\n");
 printf("2. Payment report\n");
 printf("3. Fitness report\n");
 printf("4. Progress report\n");
 scanf("%d",&choice);
 
 switch (choice)
 {
 
 case 1:
 
 fp=fopen("listing.txt","r");
 
 
 fscanf(fp,"%d %c %s 
%s",&Prosp_plyr[x].playerid,&Prosp_plyr[x].gender,Prosp_plyr[x].fname,Prosp_pl
yr[x].lname);
 while(!feof(fp))
 {
 x++;
 fscanf(fp,"%d %c %s 
%s",&Prosp_plyr[x].playerid,&Prosp_plyr[x].gender,Prosp_plyr[x].fname,Prosp_pl
yr[x].lname);
 
 }
 
 
 system("cls");
 printf("***************Registration Report**********\n\n");
 printf("ID number Gender First Name\t Last Name\n\n");
 for(i=0;i<x;i++)
 {
 printf("%d \t %c\t %s \t %s 
\n",Prosp_plyr[i].playerid,Prosp_plyr[i].gender,Prosp_plyr[i].fname,Prosp_plyr
[i].lname);
 }
 fclose(fp);
 system("pause");
 system("cls");
 login();
 
 break;
 
 case 2:
 
 filpay=fopen("payment.txt","r");
 fscanf(filpay,"%d %s %s 
%f",&player[x].id,player[x].firstname,player[x].lastname,&player[x].amtpaid);
 
 while(!feof(filpay))
 {
 
 x++;
 fscanf(filpay,"%d %s %s 
%f",&player[x].id,player[x].firstname,player[x].lastname,&player[x].amtpaid);
 }
 system("cls");
 printf("***********Payment Report********\n\n");
 printf("ID number\t First Name\t Last Name\t Amount Paid\n");
 for(i=0;i<x;i++)
 {
 printf("%d\t\t %s\t\t%s\t 
%f\n",player[i].id,player[i].firstname,player[i].lastname,player[i].amtpaid);
 }
 system("pause");
 system("cls");
 login();
 break;
 case 3:
 fitPr=fopen("fitness.txt","r");
 fscanf(fitPr,"%d%s
%s",&ply[x].id,ply[x].firstname,ply[x].lastname);
 
 fgets(activity,200,fitPr);
 
 fgets(healthconds,200,fitPr);
 strcpy(ply[x].activity,activity);
 strcpy(ply[x].healthconds,healthconds);
 while(!feof(fitPr)){
 
 x++;
 
 fscanf(fitPr,"%d%s
%s",&ply[x].id,ply[x].firstname,ply[x].lastname);
 fgets(activity,200,fitPr);
 
 fgets(healthconds,200,fitPr);
 strcpy(ply[x].activity,activity);
 strcpy(ply[x].healthconds,healthconds);
 
 
 }
 system("cls");
 printf("*****FITNESS REPORT********\n\n");
 printf("ID number First Name Last Name\n\n ");
 for(i=0;i<x;i++){
 printf("%d %s 
%s\n",ply[i].id,ply[i].firstname,ply[i].lastname);
 
 
 
 printf("Physical Activity: %s\n",ply[i].activity);
 
 printf("Health Conditions: %s\n",ply[i].healthconds);
 }
 fclose(fitPr);
 system("pause");
 system("cls");
 login();
 break;
 case 4:
 system("cls");
 printf("ID number First Name\t Last Name\t Tournaments Won\t 
Rank\n\n");
 ptr=fopen("progress.txt","r");
 fscanf(ptr,"%d %s %s %d %d 
",&plyr[x].id,plyr[x].firstname,plyr[x].lastname,&plyr[x].won,&plyr[x].rank);
 fgets(notes,500,ptr);
 strcpy(plyr[x].notes,notes);
 while(!feof(ptr))
 {
 
 
 
 x++;
 fscanf(ptr,"%d %s %s %d %d",&plyr[x].id,plyr[x].firstname,plyr[x].lastname,&plyr[x].won,&plyr[x].rank);
 fgets(notes,500,ptr);
 strcpy(plyr[x].notes,notes);
 
 }
 
 
 
 for(i=0;i<x;i++)
 {
 printf("%d \t %s\t %s\t %d\t\t\t %d\n\n Notes: %s\n\n 
",plyr[i].id,plyr[i].firstname,plyr[i].lastname,plyr[i].won,plyr[i].rank,plyr[
i].notes);
 }
 fclose(ptr);
 system("pause");
 system("cls");
 login();
 break;
 default:
 printf("Incorrect option please try again\n\n");
 system("pause");
 system("cls");
 genReporting();
 break;
 }
 
 
 }
 
 void trackFitness()
 {
 system("cls");
 int num,x,i;
 char activity[200];
 char healthconds[200];
 FILE *fitPR;
 fitPR = fopen("fitness.txt", "w");
 printf("*********Tracking Fitness************\n\n");
 printf("Enter the number of records you want to enter\n");
 scanf("%d",&num);
 for(x=0;x<num;x++){
 
 printf("Enter the Player ID. ");
 scanf("%d", &ply[x].id);
 printf("First Name: ");
 scanf("%s",ply[x].firstname);
 printf("Last Name: ");
 scanf("%s",ply[x].lastname);
 printf("Enter the activity made by player.\n");
 fflush(stdin);
 gets(activity);
 printf("Enter any serious health conditions\n");
 fflush(stdin);
 gets(healthconds);
 strcpy(ply[x].activity,activity);
 strcpy(ply[x].healthconds,healthconds);
 }
 
 for(i=0;i<num;i++){
 
 fprintf(fitPR,"%d %s %s %s\n 
%s\n",ply[i].id,ply[i].firstname,ply[i].lastname,ply[i].activity,ply[i].health
conds);
 
 }
 
 fclose(fitPR);
 
 
 
 
 system("pause");
 system("cls");
 Physical_fitness_coach_fun();
 }
 
 //payment function
 void payment()
 {
 system("cls");
 int num,x,i;
 FILE*filpay;
 filpay=fopen("payment.txt","w");
 printf("********Payments********\n\n");
 printf("Enter the amount of records to add\n\n");
 fflush(stdin);
 scanf("%d",&num);
 for(x=0;x<num;x++){
 printf("First name: ");
 fflush(stdin);
 scanf("%s",player[x].firstname);
 printf("Last name: ");
 fflush(stdin);
 scanf("%s",player[x].lastname);
 printf ("\nID#: ");
 scanf("%d",&player[x].id);
 printf("Amount Paid: $");
 scanf("%f",&player[x].amtpaid);
 
 
 
 
 
 
 }
 for(i=0;i<num;i++){
 fprintf(filpay,"%d %s %s 
%f\n",player[i].id,player[i].firstname,player[i].lastname,player[i].amtpaid);
 }
 
 fclose(filpay);
 system("cls");
 Secretary_fun();
 
 }
