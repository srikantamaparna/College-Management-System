#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
/*----------STUDENT OPERATIONS PROTOTYPES---------*/
void adds();
void sdeletes();
void updates();
void searchs();
void views();
void student();
/*------------STUDENT STRUCTURE----------*/
struct student
{
    char id[20];
    char name[50];
    char mobile[20];
    char course[50];
    char branch[50];
};
/*-----------gotoxysu() PROTOTYTPE----------*/
void gotoxysu(int,int);
/*----------------------------------------------------STUDENT DATA SECTION-----------------------------------------------------*/
void studentmenu()
{
  int choice;
  system("cls");
  gotoxysu(64,1);
  printf("<----------:WELCOME TO STUDENT SECTION:---------->");
  gotoxysu(64,3);
  printf("==================================================");
  gotoxysu(64,5);
  printf("	      MANAGE STUDENT DATA");
  gotoxysu(64,7);
  printf("==================================================");
  gotoxysu(64,10);
  printf("1. Add Student(s) Details");
  gotoxysu(64,12);
  printf("2. Delete Student(s) Details");
  gotoxysu(64,14);
  printf("3. Modify Student(s) Details");
  gotoxysu(64,16);
  printf("4. Search Student(s) Details");
  gotoxysu(64,18);
  printf("5. Display Student(s) Details");
  gotoxysu(64,20);
  printf("6. Go To Home");
  gotoxysu(64,22);
  printf("7. Exit");
  gotoxysu(64,24);
  printf("==================================================");
  gotoxysu(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    adds();
    break;
  case 2:
    sdeletes();
    break;
  case 3:
    updates();
    break;
  case 4:
    searchs();
    break;
  case 5:
    views();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxysu(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void adds()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");
    fp = fopen("student.txt","ab+");
    if(fp == NULL){
        gotoxysu(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxysu(69,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxysu(69,6);
        printf("-----------------------------------------------------");
        gotoxysu(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxysu(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxysu(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxysu(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxysu(69,17);
        printf("MOBILE NUMBER\t\t: ");
       	gets(std.mobile);
        fflush(stdin);
        gotoxysu(69,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      gotoxysu(69,22);
        printf("Want to add of another record?");
        gotoxysu(69,23);
        printf("if YES enter 'y' ");
        gotoxysu(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxysu(69,1);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void views()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :STUDENT VIEW RECORD: >\n");
    gotoxysu(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxysu(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tMOBILE No.");
    gotoxysu(29,11);
    printf("----------------------------------------------------------------------------------------------------");
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxysu(31,j);
        printf("%-11d%-25s%-22s%-15s%-15s%-11s",i,std.name,std.id,std.course,std.branch,std.mobile);
        i++;
        j++;
    }
    fclose(fp);
    gotoxysu(69,j+3);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void searchs()
{
    int p=0;
    FILE *fp;
    struct student std;
    char stid[20];
    system("cls");
    gotoxysu(69,3);
    printf("< :SEARCH STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxysu(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){

            gotoxysu(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxysu(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxysu(60,15);
            printf("COURSE\t\t: %s",std.course);
            gotoxysu(60,17);
            printf("BRANCH\t\t: %s",std.branch);
            gotoxysu(60,19);
            printf("MOBILE No.\t\t: %s",std.mobile);

            p=1;
        }
    }
    fclose(fp);
    gotoxysu(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxysu(60,21);
            printf("=====================================================");
    gotoxysu(69,23);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void sdeletes()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :DELETE STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxysu(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("temp.txt","student.txt");
    gotoxysu(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxysu(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxysu(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxysu(60,18);
    printf("=====================================================");
    gotoxysu(69,20);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void updates()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxysu(69,3);
    printf("< :MODIFY STUDENT RECORD: >");
    gotoxysu(60,5);
    printf("-----------------------------------------------------");
    gotoxysu(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        gotoxysu(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxysu(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxysu(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxysu(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxysu(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxysu(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxysu(60,19);
            printf("MOBILE No.\t\t: ");
            gets(std.mobile);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxysu(60,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxysu(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxysu(69,23);
    printf("Press any key to continue.");
    getch();
    studentmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxysu(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void menu()
{
  int choice;
  system("cls");
  gotoxysu(69,3);
  printf("1)STUDENT RECORDS");
  gotoxysu(69,5);
  printf("2)COURSES");
  gotoxysu(69,7);
  printf("3)STAFF");
  gotoxysu(69,9);
  printf("4)HOSTEL");
  gotoxysu(69,11);
  printf("5)TRANSPORT");
  gotoxysu(69,13);
  printf("6)LIBRARY");
  gotoxysu(69,15);
  printf("7)PLACEMENT");
  gotoxysu(69,17);
  printf("8)EVENT MANAGEMENT");
  gotoxysu(69,19);
  printf("9)ATTENDANCE");
  gotoxysu(69,21);
  printf("10)GRADING");
  gotoxysu(69,23);
  printf("13)Exit");
  gotoxysu(69,25);
  printf("Enter your choice:");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
    case 1:
        studentmenu();
        break;
    case 2:
        course();
        break;
    case 3:
        staffmenu();
        break;
    case 4:
        hmenu();
        break;
    case 5:
        tmenu();
        break;
    case 6:
        lmenu();
        break;
    case 7:
        cmenu();
        break;
    case 8:
        eventtype();
        break;
    case 9:
        atmenu();
        break;
    case 10:
        gmenu();
        break;
    case 13:
        exit(0);
        break;
    default:
          gotoxysu(69,5);
          printf("Invalid Choice.");
  }
}
void main()
{
    gotoxysu(67,1);
    printf("<--:College Management System:-->");
    gotoxysu(67,7);
    printf("Press any key to continue.");
    getch();
    menu();
}
/*----------EMPLOYEE OPERATIONS PROTOTYPES---------*/
void sadd();
void stdelete();
void supdate();
void ssearch();
void sview();
void staffmenu();
/*-----------gotoxy1() PROTOTYTPE----------*/
void gotoxy1(int,int);
/*------------STAFF STRUCTURE----------*/
struct staff
{
    char id[10];
    char name[50];
    char dept[50];
    float sal;
    char mobile[20];
};
/*----------------------------------------------------STAFF DATA SECTION-----------------------------------------------------*/
void staffmenu()
{
   int choice;
  system("cls");
  gotoxy1(64,1);
  printf("<----------:WELCOME TO EMPLOYEE SECTION:---------->");
  gotoxy1(64,3);
  printf("==================================================");
  gotoxy1(64,5);
  printf("	      MANAGE EMPLOYEE DATA");
  gotoxy1(64,7);
  printf("==================================================");
  gotoxy1(64,10);
  printf("1. Add Employee(s) Details");
  gotoxy1(64,12);
  printf("2. Delete Employee(s) Details");
  gotoxy1(64,14);
  printf("3. Modify Employee(s) Details");
  gotoxy1(64,16);
  printf("4. Search Employee(s) Details");
  gotoxy1(64,18);
  printf("5. Display Employee(s) Details");
  gotoxy1(64,20);
  printf("6. Go To Home");
  gotoxy1(64,22);
  printf("7. Exit");
  gotoxy1(64,24);
  printf("==================================================");
  gotoxy1(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    sadd();
    break;
  case 2:
    stdelete();
    break;
  case 3:
    supdate();
    break;
  case 4:
    ssearch();
    break;
  case 5:
    sview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxy1(69,5);
        printf("Invalid Choice.");
  }
}
/*-------------------------------------------------------------------------ADD-----------------------------------------*/
void sadd()
{
    FILE *fp;
    struct staff st;
    char another ='y';
    system("cls");
    fp = fopen("staff.txt","ab+");
    if(fp == NULL){
        gotoxy1(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy1(69,3);
        printf("<---------------:ADD EMPLOYEE DETAILS:--------------->");
        gotoxy1(69,6);
        printf("-----------------------------------------------------");
        gotoxy1(69,9);
        printf("NAME OF THE EMPLOYEE\t: ");
        gets(st.name);
        gotoxy1(69,11);
        printf("STAFF ID\t\t\t: ");
        gets(st.id);
        gotoxy1(69,13);
        printf("ENTER DEPARTMENT\t\t: ");
        gets(st.dept);
        gotoxy1(69,15);
        printf("ENTER SALARY\t\t: ");
        scanf("%f",&st.sal);
		fflush(stdin);
        gotoxy1(69,17);
        printf("MOBILE No.\t\t\t: ");
        gets(st.mobile);
        fflush(stdin);
        gotoxy1(69,20);
        printf("-----------------------------------------------------");
        fwrite(&st,sizeof(st),1,fp);
        gotoxy1(69,22);
        printf("Want to add of another record?");
        gotoxy1(69,23);
        printf("if YES enter 'y' ");
        gotoxy1(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy1(69,1);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*---------------------------------------------DELETE----------------------------------------------------------------*/
void stdelete()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct staff st;
    system("cls");
    gotoxy1(69,3);
    printf("< :DELETE EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(69,7);
    printf("Enter Employee ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy1(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&st,sizeof(st),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(st.id))!=0)
            fwrite(&st,sizeof(st),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("staff.txt");
    rename("temp.txt","staff.txt");
    gotoxy1(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxy1(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxy1(69,14);
        printf("No Employee Found With ID:%s",stid);
    }
    gotoxy1(60,18);
    printf("=====================================================");
    gotoxy1(69,20);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*---------------------------------------------UPDATE/MODIFY---------------------------------------------*/
void supdate()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct staff st;
    system("cls");
    gotoxy1(69,3);
    printf("< :MODIFY EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(64,7);
    printf("Enter Employee ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxy1(60,9);
    printf("=====================================================");
    while(fread(&st,sizeof(st),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((st.id)))== 0){
        	p=1;
            gotoxy1(60,11);
            printf("EMPLOYEE NAME\t: ");
            gets(st.name);
            gotoxy1(60,13);
            printf("EMPLOYEE ID\t\t: ");
            gets(st.id);
            gotoxy1(60,15);
            printf("DEPARTMENT\t\t: ");
            gets(st.dept);
            gotoxy1(60,17);
            printf("SALARY\t\t: ");
            scanf("%f",&st.sal);
            fflush(stdin);
            gotoxy1(60,19);
            printf("MOBILE No.\t\t: ");
            gets(st.mobile);
            fseek(fp,-sizeof(st),SEEK_CUR);
            fwrite(&st,sizeof(st),1,fp);
            break;
        }
    }
    if(!p){
		gotoxy1(69,15);
    	printf("Employee Not Found With Id %s",stid);
	}
    gotoxy1(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxy1(69,23);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*--------------------------------------------------SEARCH---------------------------------------------------*/
void ssearch()
{
    int p=0;
    FILE *fp;
    struct staff st;
    char stid[20];
    system("cls");
    gotoxy1(69,3);
    printf("< :SEARCH EMPLOYEE RECORD: >");
    gotoxy1(60,5);
    printf("-----------------------------------------------------");
    gotoxy1(69,7);
    printf("Enter Employee ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxy1(60,9);
        	printf("=====================================================");
    while(fread(&st,sizeof(st),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((st.id)))== 0){

            gotoxy1(60,11);
            printf("EMPLOYEE NAME\t: %s",st.name);
            gotoxy1(60,13);
            printf("EMPLOYEE ID\t\t: %s",st.id);
            gotoxy1(60,15);
            printf("DEPARTMENT\t\t: %s",st.dept);
            gotoxy1(60,17);
            printf("SALARY\t\t: %f",st.sal);
            gotoxy1(60,19);
            printf("MOBILE No.\t\t: %s",st.mobile);

            p=1;
        }
    }
    fclose(fp);
    gotoxy1(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With Name: %s\n",stid);
      gotoxy1(60,21);
            printf("=====================================================");
    gotoxy1(69,23);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*-------------------------------VIEW--------------------------*/
void sview()
{
    FILE *fp;
    int i=1,j;
    struct staff st;
    system("cls");
    gotoxy1(62,3);
    printf("< :EMPLOYEE VIEW RECORD: >\n");
    gotoxy1(25,5);
    printf("--------------------------------------------------------------------------------------------------------------");
   gotoxy1(30,8);
    printf("S.No \t EMPLOYEE NAME\t\tEMPLOYEE ID \t DEPARTMENT\t\tSALARY\t\tMOBILE No.");
    gotoxy1(25,11);
    printf("--------------------------------------------------------------------------------------------------------------");
    fp = fopen("staff.txt","rb+");
    if(fp == NULL){
        gotoxy1(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&st,sizeof(st),1,fp) == 1){
        gotoxy1(31,j);
        printf("%-11d%-22s%-20s%-17s%-19f%-13s",i,st.name,st.id,st.dept,st.sal,st.mobile);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy1(69,j+3);
    printf("Press any key to continue.");
    getch();
    staffmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxy1(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------COURSEs() PROTOTYPE-----------*/
void course();
/*-----------GOTOXYC() PROTOTYTPE----------*/
void gotoxyc(int,int);
/*-------------------------------------COURSES SECTION---------------------------------------------------------------*/
void course()
{
	system("cls");
    gotoxyc(69,1);
    printf("< :HERE ARE OUR PROGRAMS: >");
    gotoxyc(40,3);
    printf("========================================================================================");
    gotoxyc(70,5);
    printf("Bachelor of Technology (B.Tech)");
    gotoxyc(40,7);
    printf("========================================================================================");
    gotoxyc(63,9);
    printf("BRANCH\t\t\t\t\t\t\tFEES\n");
    gotoxyc(40,10);
    printf("----------------------------------------------------------------------------------------");
    gotoxyc(43,12);
    printf("Computer Science and Engineering (CSE)\t\t\t\t\t100000");
    gotoxyc(43,14);
    printf("Computer Science and Engineering - Artificial Intelligence (CSE-AI)\t\t150000");
    gotoxyc(43,16);
    printf("Computer Science and Engineering - Internet of Things (CSE-IOT)\t\t130000");
    gotoxyc(43,18);
    printf("Electronics and Communication Engineering (ECE)\t\t\t\t75000");
    gotoxyc(43,20);
    printf("Electrical and Electronics Engineering (EEE)\t\t\t\t\t50000");
    gotoxyc(43,22);
    printf("Civil Engineering\t\t\t\t\t\t\t\t48000");
    gotoxyc(40,24);
    printf("----------------------------------------------------------------------------------------");
    gotoxyc(69,27);
    fflush(stdin);
    printf("Press Any Key To Continue");
    getch();
    menu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyc(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxyh() PROTOTYTPE----------*/
void gotoxyh(int ,int );
/*----------HOSTEL OPERATIONS PROTOTYPES---------*/
void hmenu();
void hadd();
void hview();
void hsearch();
void hmodify();
void hdelete();
void hrules();
void hfood_menu();
/*------------HOSTEL STRUCTURE----------*/
struct hstudent {
    char name[50];
    char id[20];
    char mobile[20];
	float sfee;
    float ffee;
    float tfee;
};
/*----------------------------------------------------HOSTEL STUDENT DATA SECTION-----------------------------------------------------*/
void hmenu()
{
    int choice;
  system("cls");
  gotoxyh(64,1);
  printf("<----------:WELCOME TO HOSTEL SECTION:---------->");
  gotoxyh(64,3);
  printf("==================================================");
  gotoxyh(64,5);
  printf("	      MANAGE HOSTEL DATA");
  gotoxyh(64,7);
  printf("==================================================");
  gotoxyh(64,10);
  printf("1. Add Hostel Student(s) Details");
  gotoxyh(64,12);
  printf("2. Delete Hostel Student(s) Details");
  gotoxyh(64,14);
  printf("3. Modify Hostel Student(s) Details");
  gotoxyh(64,16);
  printf("4. Search Hostel Student(s) Details");
  gotoxyh(64,18);
  printf("5. Display Hostel Student(s) Details");
  gotoxyh(64,20);
  printf("6. HOSTEL RULES");
  gotoxyh(64,22);
  printf("7. FOOD MENU");
  gotoxyh(64,24);
  printf("8. GO TO HOME");
  gotoxyh(64,26);
  printf("9. EXIT");
  gotoxyh(64,28);
  printf("==================================================");
  gotoxyh(64,31);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    hadd();
    break;
  case 2:
    hdelete();
    break;
  case 3:
    hmodify();
    break;
  case 4:
    hsearch();
    break;
  case 5:
    hview();
    break;
  case 6:
    hrules();
    break;
  case 7:
    hfood_menu();
    break;
  case 8:
  	main();
  	break;
  case 9:
	exit(1);
  default:
        gotoxyh(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void hadd()
{
    FILE *fp;
    struct hstudent std;
    char another ='y';
    system("cls");
	fp = fopen("hostel.txt","ab+");
    if(fp == NULL){
        gotoxyh(10,5);
        printf("Error opening file");
        exit(0);
    }
    fflush(stdin);
    while(another == 'y')
    {
         gotoxyh(66,3);
        printf("<---------------:ADD HOSTEL STUDENT DETAILS:--------------->");
        gotoxyh(66,6);
        printf("------------------------------------------------------------");
        gotoxyh(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyh(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyh(69,13);
        printf("MOBILE NUMBER\t\t: ");
       	gets(std.mobile);
       	gotoxyh(69,15);
        printf("SEAT FEE\t\t\t: ");
       	scanf("%f",&std.sfee);
        gotoxyh(69,17);
        printf("FOOD FEE\t\t\t: ");
       	scanf("%f",&std.ffee);
       	std.tfee=std.sfee+std.ffee;
        gotoxyh(66,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
        gotoxyh(69,22);
        printf("Want to add of another record?");
        gotoxyh(69,23);
        printf("if YES enter 'y' ");
        gotoxyh(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyh(69,1);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void hview()
{
     FILE *fp;
    int i=1,j;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :HOSTEL STUDENT VIEW RECORD: >\n");
    gotoxyh(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxyh(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t MOBILE No.\t  TOTAL FEE (seat+food)");
    gotoxyh(29,11);
    printf("----------------------------------------------------------------------------------------------------");
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyh(31,j);
        printf("%-11d%-25s%-22s%-19s%-15f",i,std.name,std.id,std.mobile,std.tfee);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyh(69,j+3);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void hsearch()
{
	 int p=0;
    FILE *fp;
    struct hstudent std;
    char stid[20];
    system("cls");
    gotoxyh(69,3);
    printf("< :SEARCH HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyh(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
            gotoxyh(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyh(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyh(60,15);
            printf("MOBILE No.\t\t: %s",std.mobile);
            gotoxyh(60,17);
            printf("TOTAL FEE\t\t: %f",std.tfee);
            p=1;
        }
    }
    fclose(fp);

    if(p==0){
    gotoxyh(69,14);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
	}
      gotoxyh(60,19);
            printf("=====================================================");
    gotoxyh(69,21);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void hmodify()
{
    int p=0;
    char stid[20];
    FILE *fp;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :MODIFY HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyh(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyh(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyh(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            fflush(stdin);
            gotoxyh(60,15);
            printf("MOBILE No.\t\t: ");
            gets(std.mobile);
            fflush(stdin);
            gotoxyh(60,17);
            printf("SEAT FEE\t\t: ");
            scanf("%f",&std.sfee);
            gotoxyh(60,19);
            printf("FOOD FEE\t\t: ");
            scanf("%f",&std.ffee);
            std.tfee=std.sfee+std.ffee;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyh(69,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyh(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxyh(69,23);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void hdelete()
{
	int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct hstudent std;
    system("cls");
    gotoxyh(69,3);
    printf("< :DELETE HOSTEL STUDENT RECORD: >");
    gotoxyh(60,5);
    printf("-----------------------------------------------------");
    gotoxyh(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("hostel.txt","rb+");
    if(fp == NULL){
        gotoxyh(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyh(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("hostel.txt");
    rename("temp.txt","hostel.txt");
    gotoxyh(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyh(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyh(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyh(60,18);
    printf("=====================================================");
    gotoxyh(69,20);
    printf("Press any key to continue.");
    getch();
    hmenu();
}
/*-----------------------------------------------------HOSTEL RULES------------------------------------------------*/
void hrules()
{
	system("cls");
	gotoxyh(71,1);
	printf("<: HOSTEL RULES :>");
	gotoxyh(38,3);
	printf("========================================================================================================");
    gotoxyh(50,5);
	printf("1. You have to pay hostel charge every month within first 10 days.");
    gotoxyh(50,7);
	printf("**After 10 day you have to pay 20tk for each day & 200tk for each month.");
    gotoxyh(50,9);
	printf("2. You have to back in hostel in due time. \n\n\t\t\t\t\t\t\t\tsummer: last time 7.00pm\n\n\t\t\t\t\t\t\t\twinter: last time 6.00pm.");
    gotoxyh(50,15);
	printf("3. Before 6 month you cant leave the hostel.");
    gotoxyh(50,17);
	printf("4. If you want to leave this hostel you have to inform the hostel authority before 2 month.");
    gotoxyh(50,19);
	printf("5. If you have computer or laptop, we have to pay 100tk as fee.");
    gotoxyh(50,21);
	printf("6. Only your two local guardian can come to meet with you.");
    gotoxyh(38,23);
    printf("==========================================================================================================");
	gotoxyh(69,25);
	printf("Press Any Key To Continue...");
	getch();
    hmenu();
}
/*-----------------------------------------------HOSTEL FOOD MENU----------------------------------------------------------------*/
void hfood_menu()
{
	system("cls");
	gotoxyh(69,1);
	printf("<: HOSTEL FOOD MENU :>");
    gotoxyh(65,5);
    printf("\n");
    printf("\t\t\t\t\t| Day |     Breakfast       |          Lunch           |            Dinner         |\n");
    printf("\t\t\t\t\t=====================================================================================\n");
    printf("\t\t\t\t\t| Sat |   Ruti, Vegetable   | Rice, Chicken, Lentil    | Rice, Vegetable, Vorta    |\n");
    printf("\t\t\t\t\t| Sun |   Rice, Vegetable   | Rice, Fish, Lentil       | Rice, Vegetable, Egg      |\n");
    printf("\t\t\t\t\t| Mon |   Ruti, Egg         | Rice, Chicken, Lentil    | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t| Tue |   Khichuri, Egg     | Rice, Meat, Lentil       | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t| Wed |   Rice, Vorta       | Rice, Chicken, Lentil    | Rice, Egg, Lentil         |\n");
    printf("\t\t\t\t\t| Thu |   Ruti, Vegetable   | Rice, Fish, Lentil       | Rice, Vegetable, Egg      |\n");
    printf("\t\t\t\t\t| Fri |   Khichuri, Egg     | Rice, Chicken, Lentil    | Rice, Fish, Lentil        |\n");
    printf("\t\t\t\t\t=====================================================================================\n");
	gotoxyh(69,18);
	printf("Press Any Key To Continue...");
	getch();
    hmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyh(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxyt() PROTOTYTPE----------*/
void gotoxyt(int x, int y);
/*----------TRANSPORT OPERATIONS PROTOTYPES---------*/
void tmenu();
void tadd();
void tview();
void tsearch();
void tmodify();
void tdelete();
void trules();
/*------------TRANSPORT STRUCTURE----------*/
struct transport{
    char name[50];
    char id[20];
    char busno[20];
    char area[50];
    float fee;
};
/*----------------------------------------------------TRANSPORT DATA SECTION-----------------------------------------------------*/
void tmenu() {
    int choice;
  system("cls");
  gotoxyt(64,1);
  printf("<----------:WELCOME TO TRANSPORTATION SECTION:---------->");
  gotoxyt(64,3);
  printf("=========================================================");
  gotoxyt(64,5);
  printf("	      MANAGE TRANSPORTATION DATA");
  gotoxyt(64,7);
  printf("=========================================================");
  gotoxyt(64,10);
  printf("1. Add Student(s) Transport Details");
  gotoxyt(64,12);
  printf("2. Delete Student(s) Transport Details");
  gotoxyt(64,14);
  printf("3. Modify Student(s) Transport Details");
  gotoxyt(64,16);
  printf("4. Search Student(s) Transport Details");
  gotoxyt(64,18);
  printf("5. Display Student(s) Transport Details");
  gotoxyt(64,20);
  printf("6. TRANSPORTATION RULES");
  gotoxyt(64,22);
  printf("7. GO TO HOME");
  gotoxyt(64,24);
  printf("8. EXIT");
  gotoxyt(64,26);
  printf("=========================================================");
  gotoxyt(64,29);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    tadd();
    break;
  case 2:
    tdelete();
    break;
  case 3:
    tmodify();
    break;
  case 4:
    tsearch();
    break;
  case 5:
    tview();
    break;
  case 6:
    trules();
    break;
  case 7:
    main();
    break;
  case 8:
  	exit(1);
  default:
        gotoxyt(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void tadd() {
    FILE *fp;
    struct transport std;
    char another ='y';
    system("cls");
    fp = fopen("transport.txt","ab+");
    if(fp == NULL){
        gotoxyt(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyt(63,3);
        printf("<---------------:ADD STUDENT TRANSPORT DETAILS:--------------->");
        gotoxyt(63,6);
        printf("---------------------------------------------------------------");
        gotoxyt(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyt(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyt(69,13);
        printf("BUS NUMBER\t\t\t: ");
       	gets(std.busno);
       	gotoxyt(69,15);
        printf("AREA OF STUDENT\t\t: ");
       	gets(std.area);
        gotoxyt(69,17);
        printf("TRANSPORT FEE\t\t: ");
       	scanf("%f",&std.fee);
        fflush(stdin);
        gotoxyt(63,20);
        printf("----------------------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyt(69,22);
        printf("Want to add of another record?");
        gotoxyt(69,23);
        printf("if YES enter 'y' ");
        gotoxyt(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyt(69,1);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void tview() {
    FILE *fp;
    int i=1,j;
    struct transport std;
    system("cls");
    gotoxyt(65,3);
    printf("< :STUDENT(s) TRANSPORT RECORD: >\n");
    gotoxyt(25,5);
    printf("--------------------------------------------------------------------------------------------------------------------");
    gotoxyt(27,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \tBUS No.\t\tLOCATION\t    TRANSPORT FEE");
    gotoxyt(25,11);
    printf("--------------------------------------------------------------------------------------------------------------------");
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyt(30,j);
        printf("%-11d%-25s%-22s%-16s%-21s%-11f",i,std.name,std.id,std.busno,std.area,std.fee);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyt(69,j+3);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void tsearch() {
    int p=0;
    FILE *fp;
    struct transport std;
    char stid[20];
    system("cls");
    gotoxyt(69,3);
    printf("< :SEARCH STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyt(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){

            gotoxyt(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyt(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyt(60,15);
            printf("BUS No.\t\t: %s",std.busno);
            gotoxyt(60,17);
            printf("LOCATION\t\t: %s",std.area);
            gotoxyt(60,19);
            printf("TRANSPORT FEE\t: %f",std.fee);

            p=1;
        }
    }
    fclose(fp);
    gotoxyt(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxyt(60,21);
            printf("=====================================================");
    gotoxyt(69,23);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void tmodify() {
    int p=0;
    char stid[20];
    FILE *fp;
    struct transport std;
    system("cls");
    gotoxyt(69,3);
    printf("< :MODIFY STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyt(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyt(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyt(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyt(60,15);
            printf("BUS No.\t\t: ");
            gets(std.busno);
            gotoxyt(60,17);
            printf("LOCATION\t\t: ");
            gets(std.area);
            gotoxyt(60,19);
            printf("TRANSPORT FEE\t: ");
            scanf("%f",&std.fee);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyt(67,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyt(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxyt(69,23);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void tdelete() {
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct transport std;
    system("cls");
    gotoxyt(69,3);
    printf("< :DELETE STUDENT TRANSPORT RECORD: >");
    gotoxyt(60,5);
    printf("-----------------------------------------------------");
    gotoxyt(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("transport.txt","rb+");
    if(fp == NULL){
        gotoxyt(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyt(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("transport.txt");
    rename("temp.txt","transport.txt");
    gotoxyt(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyt(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyt(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyt(60,18);
    printf("=====================================================");
    gotoxyt(69,20);
    printf("Press any key to continue.");
    getch();
    tmenu();
}
/*-----------------------------------------------TRANSPORT RULES and REGULATIONS---------------------------------------------*/
void trules() {
	gotoxyt(69,1);
	printf("<: RULES AND REGULATIONS :>");
	gotoxyt(50,3);
	printf("=================================================================================");
	gotoxyt(56,5);
    printf("1. Students are required to pay transportation fees on a monthly basis.");
    gotoxyt(56,7);
    printf("2. Timely arrival at designated pickup points is mandatory.");
    gotoxyt(56,9);
    printf("3. Any changes in transportation details must be notified in advance.");
    gotoxyt(50,11);
    printf("=================================================================================");
    gotoxyt(69,13);
    printf("Press any key to enter..");
    getch();
    tmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyt(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
  Project Name: Library Management System
*/
// Define Constant KeyWords
#define ENTER 13
#define TAB 9
#define BKSP 8

// System Operation Functions
//void password(void);
void menu(void);
void userPanel(void);
void bookPanel(void);
void endScreen(void);

// User Operation Functions
void addUser(void);
void modifyUser(void);
void listUser(void);
int searchUser(int);
void rentList(void);
void deleteUser(void);

// Book Operation Functions
void addBook(void);
int modifyBook(int);
void listBook(void);
void rentBook(void);
int searchBook(int);
void deleteBook(void);
void gotoxyl(int ,int );
// System Functions
    int passTerminator = 1;
    int bookStock = 0;
    char rentName[255], bookName[255];
// Main Selection menu between User & Book Panel
void lmenu(){
    system("cls");
    fflush(stdin);
    int number;
    gotoxyl(35, 5);
    printf("----------------------------------\n");
    gotoxyl(35, 6);
    printf(">>> Library Management System <<< \n");
    gotoxyl(35, 7);
    printf("----------------------------------\n\n");
    gotoxyl(35, 9);
    printf("> 1. User Management Panel ");
    gotoxyl(35, 11);
    printf("> 2. Book Management Panel ");
    gotoxyl(35, 13);
    printf("> 3. Go To Home");
    gotoxyl(35, 15);
    printf("> 4. Exit");
    gotoxy(35,17);
    printf("> Enter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            userPanel();
            break;
        case 2:
            bookPanel();
            break;
        case 3:
        	main();
        	break;
        case 4:
        	exit(0);
        default:
            printf("\n>>> Invaild Input! <<<");
            Sleep(2000);
            menu();
    }
}
// User Panel sub-functions
void userPanel(){

    system("cls");
    fflush(stdin);

    int number;
    gotoxyl(35, 5);
    printf("-----------------------------------------------\n");
    gotoxyl(35, 6);
    printf(">>> Library Management System - User Panel <<< \n");
    gotoxyl(35, 7);
    printf("-----------------------------------------------\n\n");
    gotoxyl(35, 9);
    printf("> 1. Add User \n");
    gotoxyl(35, 10);
    printf("> 2. Modify User \n");
    gotoxyl(35, 11);
    printf("> 3. List User \n");
    gotoxyl(35, 12);
    printf("> 4. List Rentals \n");
    gotoxyl(35, 13);
    printf("> 5. Search User \n");
    gotoxyl(35, 14);
    printf("> 6. Delete User \n");
    gotoxyl(35, 15);
    printf("> 7. Open Main Menu \n");
    gotoxyl(35, 16);
    printf("> 8. Close the Program... \n\n");
    gotoxyl(35, 18);
    printf("> Enter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addUser();
            break;
        case 2:
            modifyUser();
            break;
        case 3:
            listUser();
            break;
        case 4:
            rentList();
            break;
        case 5:
            searchUser(0);
            break;
        case 6:
            deleteUser();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            userPanel();
    }
}

// Book Panel sub-functions
void bookPanel(){

    system("cls");
    fflush(stdin);

    int number;
    gotoxyl(35, 5);
    printf("-----------------------------------------------\n");
    gotoxyl(35, 6);
    printf(">>> Library Management System - Book Panel <<< \n");
    gotoxyl(35, 7);
    printf("-----------------------------------------------\n\n");
    gotoxyl(35, 9);
    printf("> 1. Add Book \n");
    gotoxyl(35, 10);
    printf("> 2. Modify Book \n");
    gotoxyl(35, 11);
    printf("> 3. List Book \n");
    gotoxyl(35, 12);
    printf("> 4. Rent Book \n");
    gotoxyl(35, 13);
    printf("> 5. Search Book \n");
    gotoxyl(35, 14);
    printf("> 6. Delete Book \n");
    gotoxyl(35, 15);
    printf("> 7. Open Main Menu \n");
    gotoxyl(35, 16);
    printf("> 8. Close the Program... \n");
    gotoxyl(35, 18);
    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addBook();
            break;
        case 2:
            modifyBook(0);
            break;
        case 3:
            listBook();
            break;
        case 4:
            rentBook();
            break;
        case 5:
            searchBook(0);
            break;
        case 6:
            deleteBook();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            bookPanel();
    }
}

// Program end credit screen - Yeah, i made it alone
// Star the Repo on github and follow me :)
void endScreen(){

    system("cls");
    fflush(stdin);
    printf("End screen\n");
    exit(0);
}

// User Functions
// Creates new file if old doesn't exist and saves user records in it
void addUser(){

label1:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255];
    char gender;
    double sid, phone, balance;

    FILE *pF = fopen("user_Records.txt", "ab+");

    if(pF != NULL)
    {
        gotoxyl(35, 5);
        printf("Enter the First Name: ");
        gets(fname) ;
        gotoxyl(35, 6);
        printf("Enter the Last Name: ");
        gets(lname);
        gotoxyl(35, 7);
        printf("Enter Gender [M/F]: ");
        scanf("%c",&gender);
        gotoxyl(35, 8);
        printf("Enter Student ID: ");
        scanf("%lf",&sid);
        gotoxyl(35, 9);
        printf("Enter Phone Number: ");
        scanf("%lf",&phone);
        gotoxyl(35, 10);
        fprintf(pF, "%s %s %c %.0lf %.0lf \n", fname, lname, gender, sid, phone);
        gotoxyl(35, 11);
        printf("\n>>> User Record Added Successfully <<< \n");

    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF);

    fflush(stdin);

    //retry screen
    char input;
    gotoxyl(35, 13);
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label1;
    }
    else if(input=='n' || input=='N')
    {
        gotoxyl(35, 14);
        printf("\nRedirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
    else
    {
        gotoxyl(35, 15);
        printf("\nInvaild input. Redirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
}

// Edit the user details and saves it
void modifyUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    gotoxyl(35, 5);
    printf("Enter the name of the person you want to modify the detail:");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            gotoxyl(35, 6);
            printf("\n---------------------------------------------");
            gotoxyl(35, 7);
            printf(">>> Record Found, Allowing Modifications <<<\n");
            gotoxyl(35, 8);
            printf("\n-----------------------------------------------\n\n");
            gotoxyl(35, 10);
            printf("> Enter First Name: ");
            gets(fname1);
            gotoxyl(35, 11);
            printf("> Enter Last Name: ");
            gets(lname1);
            gotoxyl(35, 12);
            printf("> Enter Gender: ");
            gets(gender1);
            gotoxyl(35, 13);
            printf("> Enter Student ID: ");
            scanf("%lf",&sid1);
            gotoxyl(35, 14);
            printf("> Enter Phone Number: ");
            scanf("%lf",&phone1);
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname1, lname1, gender1, sid1, phone1);
            gotoxyl(35, 15);
            printf("\n\nProcessing your changes....");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        gotoxyl(35, 6);
        printf("-------------------------------\n\n");
        gotoxyl(35, 7);
        printf(">>> Record Not Found <<<\n");
        gotoxyl(35, 8);
        printf("-------------------------------\n\n");
        gotoxyl(35, 10);
        printf("Redirecting to User Panel...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    userPanel();

}

// Lists all the user records from user_Records.txt file
void listUser(){

    system("cls");
    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter=0;
    printf("-------------------------------\n");
    printf(">>> List of Users Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
       strcat(fname, " ");
       strcat(fname, lname);
        printf("-------------------------------\n");
        printf("> Full Name: %s \n", fname);
        printf("> Gender: %s \n", gender);
	    printf("> Student-ID: %.0lf \n", sid);
        printf("> Phone No.: %.0lf \n", phone);
        printf("-------------------------------\n\n\n");
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no user records added yet...\n");
        printf("--------------------------------------\n\n");
    }
    printf("Press any key to get back to User Panel.\n");
    getch();
    userPanel();
}

// this checks if the specified user exists in the records or not
int searchUser(int nameSearcher){

label2:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    double sid, phone;

    int flag=0;
    int compare;
    char find[255];

    (nameSearcher != 3) ? printf("Search by First name of the student: ") : printf("Search by First name of the student who wants to rent book: ");
    gets(find);

    FILE *pF = fopen("user_Records.txt", "r");

     while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        //strcmp(variable, variable1) -- if both the strings are equal then it will return 0 otherwise a random number.
        compare = strcmp(find, fname);

        if(compare == 0)
        {
            if(nameSearcher != 3)
            {
                strcat(fname, " ");
                strcat(fname, lname);
                gotoxyl(35, 5);
                printf("\n---------------------\n");
                gotoxyl(35, 6);
                printf(">>> Record Found <<< \n");
                gotoxyl(35, 7);
                printf("---------------------\n\n");
                gotoxyl(35, 8);
                printf("-------------------------------\n");
                gotoxyl(35, 9);
                printf("> Full Name: %s \n", fname);
                gotoxyl(35, 10);
                printf("> Gender: %s \n", gender);
                gotoxyl(35, 11);
                printf("> Student-ID: %.0lf \n", sid);
                gotoxyl(35, 12);
                printf("> Phone Number: %.0lf \n", phone);
                gotoxyl(35, 13);
                printf("-------------------------------\n\n");

            }
            strcpy(rentName, fname);
            flag=1;
        }
    }

    fclose(pF);

    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    fflush(stdin);

    if(nameSearcher != 3)
    {
        printf("Press any key to redirect back to Panel.");
        getch();
        userPanel();
    }
    else if(nameSearcher == 3 && flag == 1)
    {
        return 5;
    }
}
// deletes the user information from user_Records.txt file
void deleteUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    gotoxyl(35, 5);
    printf("Enter the name of the person you want to delete the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            gotoxyl(35, 5);
            printf("\n---------------------------------------------\n");
            gotoxyl(35, 6);
            printf(">>> Record Deleted <<<\n");
            gotoxyl(35, 7);
            printf("-----------------------------------------------\n\n");
            gotoxyl(35, 8);
            printf("Redirecting to User Panel...");
            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }
    fclose(pF);
    fclose(pT);
    fflush(stdin);
    pF = fopen("user_Records.txt", "w");
    fclose(pF);
    if(flag == 0)
    {
        gotoxyl(35, 5);
        printf("\n\n-------------------------------\n");
        gotoxyl(35, 6);
        printf(">>> Record Not Found <<<\n");
        gotoxyl(35, 7);
        printf("-------------------------------\n\n");
        gotoxyl(35, 8);
        printf("Redirecting to User Panel...");
    }
    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }
    fclose(pF);
    fclose(pT);
    pT = fopen("temporary.txt", "w");
    fclose(pT);
    fflush(stdin);
    Sleep(2000);
    userPanel();
}
// Book Functions
// add the books record in book_Records.txt file
void addBook(){
label3:
    system("cls");
    fflush(stdin);
    char name[255], author[255], publisher[255];
    double bookid, quantity;
    FILE *pF = fopen("book_Records.txt", "ab+");
    if(pF != NULL)
    {
        gotoxyl(35, 5);
        printf("Enter Book Name: ");
        gets(name);
        gotoxyl(35, 6);
        printf("Enter Book Author: ");
        gets(author);
        gotoxyl(35, 7);
        printf("Enter Book Publisher: ");
        gets(publisher);
        fflush(stdin);
        gotoxyl(35, 8);
        printf("Enter Book ID: ");
        scanf("%lf",&bookid);
        gotoxyl(35, 9);
        printf("Enter Book Quantity: ");
        scanf("%lf",&quantity);
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        gotoxyl(35, 11);
        printf("\n>>> Book Record Added Successfully <<< \n");
    }
    else
    {
        printf("Unable to open/locate the file.");
    }
    fclose(pF);
    fflush(stdin);
    char input;
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);
    if(input == 'y' || input=='Y')
    {
        goto label3;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirecting to Book Panel.");
        Sleep(2000);
        bookPanel();
    }
    else
    {
        printf("\nInvaild input. Redirecting to Book Panel.");
        Sleep(2000);
        bookPanel();
    }
}
// edits the book details according to you and saves it again
int modifyBook(int rentModifier){
    system("cls");
    fflush(stdin);
    char name[255], author[255], publisher[255];
    double bookid, quantity;
    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;
    int flag=0;
    int compare;
    char find[255];
    if (rentModifier != 5)
    {
        gotoxyl(10, 5);
        printf("Enter the name of the book you want to see the detail: ");
        gets(find);
        fflush(stdin);
    }
    else
    {
        strcpy(find, bookName);
    }
    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");
    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        if(compare == 0)
        {
            if(rentModifier != 5)
            {
                gotoxyl(35, 6);
                printf("\n---------------------------------------------\n");
                gotoxyl(35, 7);
                printf("\n>>> Record Found, Allowing Modifications <<<\n");
                gotoxyl(35, 8);
                printf("\n-----------------------------------------------\n\n");
                gotoxyl(35, 10);
                printf("> Enter Book Name: ");
                gets(name1);
                gotoxyl(35, 11);
                printf("> Enter Authour: ");
                gets(author1);
                gotoxyl(35, 12);
                printf("> Enter Publisher: ");
                gets(publisher1);
                fflush(stdin);
                gotoxyl(35, 13);
                printf("> Enter Book ID: ");
                scanf("%lf",&bookid1);
                gotoxyl(35, 14);
                printf("> Enter Quantity: ");
                scanf("%lf",&quantity1);
                gotoxyl(35, 15);
                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name1, author1, publisher1, bookid1, quantity1);
                gotoxyl(35, 16);
                printf("\n\nProcessing your changes....");
            }
            else
            {
                quantity = bookStock;
                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
            }
            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }
    fclose(pF);
    fclose(pT);
    fflush(stdin);
    pF = fopen("book_Records.txt", "w");
    fclose(pF);
    if(flag == 0)
    {
        gotoxyl(35, 5);
        printf("\n\n-------------------------------\n");
        gotoxyl(35, 6);
        printf(">>> Record Not Found <<<\n");
        gotoxyl(35, 7);
        printf("-------------------------------\n\n");
        gotoxyl(35, 9);
        printf("Redirecting to Book Panel...");
    }
    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");
    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }
    fclose(pF);
    fclose(pT);
    pT = fopen("temporary.txt", "w");
    fclose(pT);
    if(rentModifier != 5)
    {
        Sleep(2000);
        bookPanel();
    }
}
// lists all the book record from the book_Records.txt file
void listBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double quantity, bookid;
    int counter=0;

    FILE *pF = fopen("book_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> List of Books Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        printf("-------------------------------\n");
        printf("> Book Name: %s \n", name);
        printf("> Auhtor: %s \n", author);
        printf("> Publisher: %s\n", publisher);
        printf("> Book ID: %.0lf \n", bookid);
        printf("> Quantity: %.0lf \n", quantity);
        printf("-------------------------------\n\n\n");
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no book records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to Book Panel.\n");
    getch();
    bookPanel();
}

// Book Rental function
// first it checks whether the user is already registered in the user_Records.txt or not
// second it checks whether the book exists in the book_Records.txt or not
// third it checks if the book quantity is atleast 1, throws error if the book is OUT OF STOCK -- it also reduces book quantity by 1 from book_Recprds.txt
// fourth it registers the user name & book name in a new file rent_Records.txt and saves it :)
void rentBook(){

    int terminator=1, nameFound, bookFound;

label5:

    fflush(stdin);

    // check if user exists
    nameFound = searchUser(3);

    if(nameFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? bookPanel() : terminator++;
        goto label5;
    }
    else if(nameFound == 5)
    {
        printf("\nUser Found in Records! \nPlease wait... \n");
        terminator = 1;
        Sleep(2000);
    }

label6:

    fflush(stdin);

    // check if book exists
    bookFound = searchBook(3);

    if(bookFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? bookPanel() : terminator++;
        goto label6;
    }
    else if(bookFound == 5)
    {
        // check if book quantity is > 0
        if(bookStock > 0)
        {
            printf("\nBook Found & In-Stock! \nPlease wait... \n");
        }
        else
        {
            printf("\nSorry, Out of Stock! \nPlease wait... ");
            Sleep(2000);
            (terminator == 3) ? bookPanel() : terminator++;
            goto label6;
        }
    }

    fflush(stdin);

    /* printf("\n---------------------------------------------\n");
    printf("User Searcher: %d \n", nameFound);
    printf("Book Searcher: %d \n", bookFound);
    printf("User Name: %s \n", rentName);
    printf("Book Name: %s \n", bookName);
    printf("---------------------------------------------\n\n"); */

    if(nameFound == 5 && bookFound == 5)
    {
        // Adding record in rent_Records.txt file
        FILE *pF = fopen("rent_Records.txt", "ab+");

        if(pF != NULL)
        {
            fprintf(pF, "%s %s \n", rentName, bookName);
        }
        else
        {
            printf("Unable to open/locate the file.");
        }

        fclose(pF);

        // reducing quantity of book by 1
        bookStock--;
        modifyBook(5);

        printf("---------------------------------------------\n");
        printf(">>> Rent Record Added Successfully <<< \n");
        printf("---------------------------------------------\n");

        printf("\nRedirecting to Book Panel...\n");
        Sleep(3500);
        bookPanel();
    }
}

// lists all the username & booknames which are rented to someone in registered files
void rentList(){

    system("cls");
    fflush(stdin);

    char rentListUser[255], rentListBook[255];
    int counter = 0;

    FILE *pF = fopen("rent_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> List of Books Rental <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s \n", rentListUser, rentListBook) != EOF)
    {
        printf("> Rent User: %s \n", rentListUser);
        printf("> Rent Book(s): %s \n\n", rentListBook);

        counter++;
    }

    fclose(pF);
    fflush(stdin);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no rent records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("\nPress any key to get back to User Panel.\n");
    getch();
    userPanel();
}

// searches for the book details by book name from the txt file
int searchBook(int bookSearcher){

label4:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    int flag=0;
    int compare;

    char find[255];

    (bookSearcher != 3) ? printf("Serach the book by Author name or Book name: ") : printf("Serach the book by Author name or Book name: ");
    gets(find);

    FILE *pF = fopen("book_Records.txt", "r");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        compare = strcmp(find, author);

        if(compare == 0)
        {
            if(bookSearcher != 3)
            {
                printf("\n-------------------------\n");
                printf(">>> Record Found <<< \n");
                printf("-------------------------\n\n");

                printf("-------------------------------\n");
                printf("> Book Name: %s \n", name);
                printf("> Auhtor: %s \n", author);
                printf("> Publisher: %s\n", publisher);
                printf("> Book ID: %.0lf \n", bookid);
                printf("> Quantity: %.0lf \n", quantity);
                printf("-------------------------------\n\n");
            }
            strcpy(bookName, name);
            bookStock = quantity;
            flag=1;
        }
    }

    fclose(pF);

    fflush(stdin);

    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    if(bookSearcher != 3)
    {
        printf("Press any key to redirect to Book Panel.");
        getch();
        bookPanel();
    }
    else if(bookSearcher == 3 && flag == 1)
    {
        return 5;
    }
}
// deletes the book records from .txt file
void deleteBook(){
    system("cls");
    fflush(stdin);
    char name[255], author[255], publisher[255];
    double bookid, quantity;
    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;
    int flag=0;
    int compare;
    char find[255];
    printf("Enter the name of the book you want to delete the detail: ");
    gets(find);
    fflush(stdin);
    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");
    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Deleted <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirecting to Book Panel...");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }
    fclose(pF);
    fclose(pT);
    fflush(stdin);
    pF = fopen("book_Records.txt", "w");
    fclose(pF);
    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to Book Panel...");
    }
    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");
    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }
    fclose(pF);
    fclose(pT);
    pT = fopen("temporary.txt", "w");
    fclose(pT);
    Sleep(2000);
    bookPanel();
}
void gotoxyl(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxysu() PROTOTYTPE----------*/
void gotoxyat(int,int);
/*----------STUDENT ATTENDANCE OPERATIONS PROTOTYPES---------*/
void atmenu();
void atadd();
void atview();
void atsearch();
void atmodify();
void atdelete();
/*------------STUDENT ATTENDANCE STRUCTURE----------*/
struct atstudent
{
    char name[20];
    char id[20];
    char course[20];
    char branch[20];
    int total;
    int present;
    float percentage;
};
/*----------------------------------------------------STUDENT ATTENDANCE DATA SECTION-----------------------------------------------------*/
void atmenu()
{
  int choice;
  system("cls");
  gotoxyat(64,1);
  printf("<----------:WELCOME TO ATTENDANCE SECTION:---------->");
  gotoxyat(64,3);
  printf("==================================================");
  gotoxyat(64,5);
  printf("	      MANAGE STUDENT ATTENDANCE DATA");
  gotoxyat(64,7);
  printf("==================================================");
  gotoxyat(64,10);
  printf("1. Add Student(s) Attendance");
  gotoxyat(64,12);
  printf("2. Delete a Student(s) Details");
  gotoxyat(64,14);
  printf("3. Modify a Student(s) Details");
  gotoxyat(64,16);
  printf("4. Search for a Particular Student(s) Attendance");
  gotoxyat(64,18);
  printf("5. Display All Students Attendance Percentage");
  gotoxyat(64,20);
  printf("6. Go To Home");
  gotoxyat(64,22);
  printf("7. Exit");
  gotoxyat(64,24);
  printf("==================================================");
  gotoxyat(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    atadd();
    break;
  case 2:
    atdelete();
    break;
  case 3:
    atupdate();
    break;
  case 4:
    atsearch();
    break;
  case 5:
    atview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxyat(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD RECORD----------------------------------------------------------*/
void atadd()
{
    FILE *fp;
    struct atstudent std;
    char another ='y';
    system("cls");

    fp = fopen("attendance.txt","ab+");
    if(fp == NULL){
        gotoxyat(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyat(69,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxyat(69,6);
        printf("-----------------------------------------------------");
        gotoxyat(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyat(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyat(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxyat(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxyat(69,17);
        fflush(stdin);
        printf("TOTAL WORKING DAYS\t\t: ");
        scanf("%d",&std.total);
        gotoxyat(69,19);
        printf("STUDENT ATTENDED\t\t: ");
        scanf("%d",&std.present);
        std.percentage=(std.present*100)/std.total;
        fwrite(&std,sizeof(std),1,fp);
        gotoxyat(69,21);
        printf("-----------------------------------------------------");
        gotoxyat(69,23);
        printf("Want to add of another record?");
        gotoxyat(69,24);
        printf("if YES enter 'y' ");
        gotoxyat(69,25);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyat(69,1);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void atview()
{
    FILE *fp;
    int i=1,j;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :ATTENDANCE PROGRESS: >\n");
    gotoxyat(25,5);
    printf("-------------------------------------------------------------------------------------------------------------------------");
   gotoxyat(30,8);
    printf("S.No \t STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tATTENDANCE PERCENTAGE");
    gotoxyat(25,11);
    printf("-------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyat(31,j);
        printf("%-11d%-25s%-22s%-15s%-20s%-11f",i,std.name,std.id,std.course,std.branch,std.percentage);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyat(69,j+3);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void atsearch()
{
    int p=0;
    FILE *fp;
    struct atstudent std;
    char stid[20];
    system("cls");
    gotoxyat(69,3);
    printf("< :SEARCH STUDENT ATTENDANCE: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyat(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){

            gotoxyat(60,11);
            printf("STUDENT NAME\t  : %s",std.name);
            gotoxyat(60,13);
            printf("REGISTRATION NUMBER\t  : %s",std.id);
            gotoxyat(60,15);
            printf("COURSE\t\t  : %s",std.course);
            gotoxyat(60,17);
            printf("BRANCH\t\t  : %s",std.branch);
            gotoxyat(60,19);
            printf("ATTENDANCE PERCENTAGE : %f",std.percentage);

            p=1;
        }
    }
    fclose(fp);
    gotoxyat(69,16);
    if(p==0)
      printf("Sorry, Data Not Found With ID: %s\n",stid);
      gotoxyat(60,21);
            printf("=====================================================");
    gotoxyat(69,23);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void atupdate()
{
	int p=0;
   char stid[20];
    FILE *fp;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :MODIFY STUDENT ATTENDANCE: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyat(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyat(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyat(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyat(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxyat(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxyat(60,19);
            printf("TOTAL WORKING DAYS\t: ");
            scanf("%d",&std.total);
            gotoxyat(60,21);
        	printf("ATTENDED DAYS\t: ");
        	scanf("%d",&std.present);
        	std.percentage=(std.present*100)/std.total;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0){
    gotoxyat(69,15);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
	}
     gotoxyat(60,23);
    printf("=====================================================");

    fclose(fp);
    gotoxyat(69,25);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void atdelete()
{
    int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct atstudent std;
    system("cls");
    gotoxyat(69,3);
    printf("< :DELETE STUDENT ATTENDANCE REPORT: >");
    gotoxyat(60,5);
    printf("-----------------------------------------------------");
    gotoxyat(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("attendance.txt","rb+");
    if(fp == NULL){
        gotoxyat(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyat(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("attendance.txt");
    rename("temp.txt","attendance.txt");
    gotoxyat(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyat(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyat(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyat(60,18);
    printf("=====================================================");
    gotoxyat(69,20);
    printf("Press any key to continue.");
    getch();
    atmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyat(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxyg() PROTOTYTPE----------*/
void gotoxyg(int ,int );
/*----------GRADING OPERATIONS PROTOTYPES---------*/
void gmenu();
void gadd();
void gview();
void gsearch();
void gmodify();
void gdelete();
/*------------STUDENT GRADING STRUCTURE----------*/
struct gstudent
{
    char name[20];
    char id[20];
    char course[20];
    char branch[20];
    float percentage;
    char grade;
};
/*----------------------------------------------------STUDENT GRADING SECTION-----------------------------------------------------*/
void gmenu()
{
    int choice;
    system("cls"); //clrscr()
     gotoxyg(64,1);
  printf("<----------:WELCOME TO GRADING SECTION:---------->");
  gotoxyg(64,3);
  printf("==================================================");
  gotoxyg(62,5);
  printf("	      MANAGE STUDENT PROGRESS CARD");
  gotoxyg(64,7);
  printf("==================================================");
  gotoxyg(64,10);
  printf("1. Add Student(s) Marks Details");
  gotoxyg(64,12);
  printf("2. Delete Student(s) Marks Details");
  gotoxyg(64,14);
  printf("3. Modify Student(s) Marks Details");
  gotoxyg(64,16);
  printf("4. Search Student(s) Marks Details");
  gotoxyg(64,18);
  printf("5. Display Student(s) Marks Details");
  gotoxyg(64,20);
  printf("6. Go To Home");
  gotoxyg(64,22);
  printf("7. Exit");
  gotoxyg(64,24);
  printf("==================================================");
  gotoxyg(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
    switch(choice)
    {
    case 1:
        gadd();
        break;

    case 2:
        gdelete();
        break;

    case 3:
       gmodify();
        break;

    case 4:

        gsearch();
        break;


    case 5:
    	gview();
        break;


    case 6:
        main();
        break;
	case 7:
        exit(0);
    default:
        gotoxyg(69,5);
        printf("Invalid Choice.");
    }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void gadd()
{
    FILE *fp;
    struct gstudent std;
    char another ='y';
    system("cls");

    fp = fopen("grade.txt","ab+");
    if(fp == NULL){
        gotoxyg(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyg(69,3);
        printf("<---------------:ADD STUDENT MARKS DETAILS:--------------->");
        gotoxyg(69,6);
        printf("-----------------------------------------------------");
        gotoxyg(69,9);
        printf("NAME OF THE STUDENT\t: ");
        gets(std.name);
        gotoxyg(69,11);
        printf("REGISTRATION NUMBER\t: ");
        gets(std.id);
        gotoxyg(69,13);
        printf("COURSE\t\t\t: ");
       	gets(std.course);
       	gotoxyg(69,15);
        printf("BRANCH\t\t\t: ");
       	gets(std.branch);
        gotoxyg(69,17);
        printf("ENTER PERCENTAGE\t\t: ");
        scanf("%f",&std.percentage);
        if(std.percentage>=85.0)
			std.grade=65;
		else if(std.percentage>=75.0)
			std.grade=66;
		else if(std.percentage>=65.0)
			std.grade=67;
		else if(std.percentage>=55.0)
			std.grade=68;
		else
			std.grade=69;
        gotoxyg(69,20);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyg(69,22);
        printf("Want to add of another record?");
        gotoxyg(69,23);
        printf("if YES enter 'y' ");
        gotoxyg(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyg(69,1);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void gview()
{
    FILE *fp;
    int i=1,j;
    struct gstudent std;
    system("cls");
    gotoxyg(64,3);
    printf("< :STUDENT(s) PROGRESS RECORD: >\n");
    gotoxyg(20,5);
    printf("------------------------------------------------------------------------------------------------------------------------");
   gotoxyg(25,8);
    printf("S.No \t   STUDENT NAME\t\tREGISTRATION NUMBER \t COURSE\t\tBRANCH\t\tPERCENTAGE\tGRADE");
    gotoxyg(20,11);
    printf("------------------------------------------------------------------------------------------------------------------------");
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyg(26,j);
        printf("%-9d%-25s%-22s%-15s%-16s%-18f%-10c",i,std.name,std.id,std.course,std.branch,std.percentage,std.grade);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyg(69,j+3);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void gsearch()
{
   int p=0;
    FILE *fp;
    struct gstudent std;
    char stid[20];
    system("cls");
    gotoxyg(69,3);
    printf("< :SEARCH STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(69,7);
    printf("Enter Student ID to Search: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyg(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){

            gotoxyg(60,11);
            printf("STUDENT NAME\t: %s",std.name);
            gotoxyg(60,13);
            printf("REGISTRATION NUMBER\t: %s",std.id);
            gotoxyg(60,15);
            printf("COURSE\t\t: %s",std.course);
            gotoxyg(60,17);
            printf("BRANCH\t\t: %s",std.branch);
            gotoxyg(60,19);
            printf("PERCENTAGE\t\t: %f",std.percentage);
            gotoxyg(60,21);
            printf("GRADE\t\t: %c",std.grade);
            p=1;
        }
    }
    fclose(fp);
    gotoxyg(69,16);
    if(p==0){
	gotoxyg(69,16);
      printf("Sorry, Data Not Found With ID: %s\n",stid);
  }
    gotoxyg(60,23);
    printf("=====================================================");
    gotoxyg(69,25);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void gmodify()
{
	int p=0;
    char stid[20];
    FILE *fp;
    struct gstudent std;
    system("cls");
    gotoxyg(69,3);
    printf("< :MODIFY STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(64,7);
    printf("Enter Student ID to Modify Details: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyg(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(stid),strlwr((std.id)))== 0){
        	p=1;
            gotoxyg(60,11);
            printf("STUDENT NAME\t: ");
            gets(std.name);
            gotoxyg(60,13);
            printf("REGISTRATION NUMBER\t: ");
            gets(std.id);
            gotoxyg(60,15);
            printf("COURSE\t\t: ");
            gets(std.course);
            gotoxyg(60,17);
            printf("BRANCH\t\t: ");
            gets(std.branch);
            gotoxyg(60,19);
            printf("PERCENTAGE\t\t: ");
            scanf("%f",&std.percentage);
            if(std.percentage>=85.0)
				std.grade=65;
			else if(std.percentage>=75.0)
				std.grade=66;
			else if(std.percentage>=65.0)
				std.grade=67;
			else if(std.percentage>=55.0)
				std.grade=68;
			else
				std.grade=69;
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxyg(60,15);
    	printf("Student Data Not Found With ID %s",stid);
	}
    gotoxyg(60,21);
    printf("=====================================================");

    fclose(fp);
    gotoxyg(69,23);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void gdelete()
{
     int p=0;
    char stid[20];
    FILE *fp,*ft;
    struct gstudent std;
    system("cls");
    gotoxyg(69,3);
    printf("< :DELETE STUDENT PROGRESS RECORD: >");
    gotoxyg(60,5);
    printf("-----------------------------------------------------");
    gotoxyg(69,7);
    printf("Enter Student ID to Delete: ");
    fflush(stdin);
    gets(stid);
    fp = fopen("grade.txt","rb+");
    if(fp == NULL){
        gotoxyg(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyg(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(stid),strlwr(std.id))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("grade.txt");
    rename("temp.txt","grade.txt");
    gotoxyg(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyg(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyg(69,14);
        printf("No Student Found With ID:%s",stid);
    }
    gotoxyg(60,18);
    printf("=====================================================");
    gotoxyg(69,20);
    printf("Press any key to continue.");
    getch();
    gmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyg(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxyp() PROTOTYTPE----------*/
void gotoxyp(int ,int );
/*----------PLACEMENT OPERATIONS PROTOTYPES---------*/
void cmenu();
void cadd();
void cview();
void csearch();
void cmodify();
void cdelete();
/*------------PLACEMENT STRUCTURE----------*/
struct company
{
    char name[20];
    char package[10];
    int count;
};
/*----------------------------------------------------PLACEMENT DATA SECTION-----------------------------------------------------*/
void cmenu()
{
  int choice;
  system("cls");
  gotoxyp(64,1);
  printf("<----------:WELCOME TO PLACEMENT SECTION:---------->");
  gotoxyp(64,3);
  printf("==================================================");
  gotoxyp(64,5);
  printf("	      MANAGE PLACEMENT DATA");
  gotoxyp(64,7);
  printf("==================================================");
  gotoxyp(64,10);
  printf("1. Add Company(ies) Details");
  gotoxyp(64,12);
  printf("2. Delete Company(ies) Details");
  gotoxyp(64,14);
  printf("3. Modify Compnany(ies) Details");
  gotoxyp(64,16);
  printf("4. Search Company(ies) Details");
  gotoxyp(64,18);
  printf("5. Display Company(ies) Details");
  gotoxyp(64,20);
  printf("6. Go To Home");
  gotoxyp(64,22);
  printf("7. Exit");
  gotoxyp(64,24);
  printf("==================================================");
  gotoxyp(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    cadd();
    break;
  case 2:
    cdelete();
    break;
  case 3:
    cmodify();
    break;
  case 4:
    csearch();
    break;
  case 5:
    cview();
    break;
  case 6:
    main();
    break;
  case 7:
  	exit(1);
  default:
        gotoxyp(69,5);
        printf("Invalid Choice.");
  }
}
/*----------------------------------------------ADD----------------------------------------------------------*/
void cadd()
{
    FILE *fp;
    struct company std;
    char another ='y';
    system("cls");

    fp = fopen("company.txt","ab+");
    if(fp == NULL){
        gotoxyp(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxyp(64,3);
        printf("<---------------:ADD STUDENT DETAILS:--------------->");
        gotoxyp(64,6);
        printf("-----------------------------------------------------");
        gotoxyp(64,9);
        printf("NAME OF THE COMPANY\t: ");
        gets(std.name);
        gotoxyp(64,11);
        printf("PACKAGE OFFERED\t\t: ");
        gets(std.package);
        gotoxyp(64,13);
        printf("No.of SELECTIONS\t: ");
        scanf("%d",&std.count);
        gotoxyp(64,16);
        printf("-----------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      	gotoxyp(64,18);
        printf("Want to add of another record?");
        gotoxyp(64,19);
        printf("if YES enter 'y' ");
        gotoxyp(64,20);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxyp(69,1);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void cview()
{
    FILE *fp;
    int i=1,j;
    struct company std;
    system("cls");
    gotoxyp(65,3);
    printf("< :COMPANIES DETAILS: >");
    gotoxyp(32,5);
    printf("------------------------------------------------------------------------------------------");
    gotoxyp(40,8);
    printf("S.No \t   COMPANY NAME\t\tPACKAGE OFFERED \t STUDENTS SELECTED");
    gotoxyp(32,11);
    printf("------------------------------------------------------------------------------------------");
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxyp(40,j);
        printf("%-13d%-24s%-25s%-20d",i,std.name,std.package,std.count);
        i++;
        j++;
    }
    fclose(fp);
    gotoxyp(65,j+3);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void csearch()
{
	int p=0;
    FILE *fp;
    struct company std;
    char cname[20];
    system("cls");
    gotoxyp(69,3);
    printf("< :SEARCH COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(69,7);
    printf("Enter name of company : ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxyp(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(cname),strlwr(std.name)) == 0){
            gotoxyp(60,11);
            printf("COMPANY NAME\t: %s",std.name);
            gotoxyp(60,13);
            printf("PACKAGE OFFERED\t: %s",std.package);
            gotoxyp(60,15);
            printf("STUDENTS SELECTED\t: %d",std.count);
			p=1;
        }
    }
    fclose(fp);

    if(p==0){
    gotoxyp(69,13);
      printf("Sorry, Company Not Found With Name: %s\n",cname);
  	}
      gotoxyp(60,18);
            printf("=====================================================");
    gotoxyp(69,23);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void cmodify()
{
    int p=0;
    char cname[20];
    FILE *fp;
    struct company std;
    system("cls");
    gotoxyp(69,3);
    printf("< :MODIFY COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(64,7);
    printf("Enter Company Name to Modify Details: ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxyp(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(cname),strlwr(std.name)) == 0){
            p=1;
            gotoxyp(60,11);
            printf("COMPANY NAME\t: ");
            gets(std.name);
            gotoxyp(60,13);
            printf("PACKAGE OFFERED\t: ");
            gets(std.package);
            gotoxyp(60,15);
            printf("No.of SELECTIONS\t: ");
            scanf("%d",&std.count);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
   if(p==0)
    {
    	gotoxyp(67,12);
    	printf("Company Data Not Found With Name %s",cname);
	}
    gotoxyp(60,17);
            printf("=====================================================");

    fclose(fp);
    gotoxyp(69,20);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*--------------------------------------------DELETE------------------------------------------*/
void cdelete()
{
    int p=0;
    char cname[20];
    FILE *fp,*ft;
    struct company std;
    system("cls");
    gotoxyp(69,3);
    printf("< :DELETE COMPANY RECORD: >");
    gotoxyp(60,5);
    printf("-----------------------------------------------------");
    gotoxyp(69,7);
    printf("Enter Company to Delete: ");
    fflush(stdin);
    gets(cname);
    fp = fopen("company.txt","rb+");
    if(fp == NULL){
        gotoxyp(69,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxyp(69,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(strlwr(cname),strlwr(std.name))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        {
            p=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove("company.txt");
    rename("temp.txt","company.txt");
    gotoxyp(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxyp(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxyp(69,14);
        printf("No Company Found With Name:%s",cname);
    }
    gotoxyp(60,18);
    printf("=====================================================");
    gotoxyp(69,20);
    printf("Press any key to continue.");
    getch();
    cmenu();
}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxyp(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*-----------gotoxye() PROTOTYTPE----------*/
void gotoxye(int ,int );
/*----------EVENT OPERATIONS PROTOTYPES---------*/
void eventtype();
void techev();
void nontechev();
void eadd();
void eview();
void esearch();
void emodify();
void edelete();
/*------------EVENT STRUCTURE----------*/
struct event
{
    char name[20];
    char timing[10];
    float fee;
    char location[20];
    char branch[200];
};
int r;
/*----------------------------------------------------EVENT DATA SECTION-----------------------------------------------------*/
void eventtype()
{
	int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("==================================================");
  gotoxye(64,5);
  printf("	      MANAGE EVENTS DATA");
  gotoxye(64,7);
  printf("==================================================");
  gotoxye(64,10);
  printf("1. TECHNICAL EVENT MANAGEMENT");
  gotoxye(64,12);
  printf("2. NON-TECHNICAL EVENT MANAGEMENT");
  gotoxye(64,14);
  printf("3. GO TO HOME");
	gotoxye(64,16);
	printf("4. EXIT");
	gotoxye(64,19);
	printf("==================================================");
	gotoxye(69,21);
    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    	r=1;
        techev();
        break;

    case 2:
    	r=0;
        nontechev();
        break;
    case 3:
        main();
        break;
    case 4:
        exit(1);
	default:
        gotoxye(10,17);
        printf("Invalid Choice.");
	}
}
/*---------------------------------TECHNICAL EVENT SECTION------------------------------*/
void techev()
{

	int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO TECHNICAL EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("===========================================================");
  gotoxye(64,5);
  printf("	      MANAGE TECHNICAL EVENTS DATA");
  gotoxye(64,7);
  printf("===========================================================");
  gotoxye(64,10);
  printf("1. Add Event(s) Details");
  gotoxye(64,12);
  printf("2. Delete Event(s) Details");
  gotoxye(64,14);
  printf("3. Modify Event(s) Details");
  gotoxye(64,16);
  printf("4. Search Event(s) Details");
  gotoxye(64,18);
  printf("5. Display Event(s) Details");
  gotoxye(64,20);
  printf("6. Go Back");
  gotoxye(64,22);
  printf("7. Exit");
  gotoxye(64,24);
  printf("===========================================================");
  gotoxye(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    eadd();
    break;
  case 2:
    edelete();
    break;
  case 3:
    emodify();
    break;
  case 4:
    esearch();
    break;
  case 5:
    eview();
    break;
  case 6:
    eventtype();
    break;
  case 7:
  	exit(1);
  default:
        gotoxye(69,5);
        printf("Invalid Choice.");
  }

}
/*----------------------------NON TECHNICAL EVENT-----------------------------*/
void nontechev()
{
		int choice;
  system("cls");
  gotoxye(64,1);
  printf("<----------:WELCOME TO NON TECHNICAL EVENTS SECTION:---------->");
  gotoxye(64,3);
  printf("===========================================================");
  gotoxye(64,5);
  printf("	      MANAGE NON TECHNICAL EVENTS DATA");
  gotoxye(64,7);
  printf("===========================================================");
  gotoxye(64,10);
  printf("1. Add Event(s) Details");
  gotoxye(64,12);
  printf("2. Delete Event(s) Details");
  gotoxye(64,14);
  printf("3. Modify Event(s) Details");
  gotoxye(64,16);
  printf("4. Search Event(s) Details");
  gotoxye(64,18);
  printf("5. Display Event(s) Details");
  gotoxye(64,20);
  printf("6. Go Back");
  gotoxye(64,22);
  printf("7. Exit");
  gotoxye(64,24);
  printf("===========================================================");
  gotoxye(64,27);
  printf("ENTER YOUR CHOICE: ");
  scanf("%d",&choice);
  system("cls");
  switch(choice)
  {
  case 1:
    eadd();
    break;
  case 2:
    edelete();
    break;
  case 3:
    emodify();
    break;
  case 4:
    esearch();
    break;
  case 5:
    eview();
    break;
  case 6:
    eventtype();
    break;
  case 7:
  	exit(1);
  default:
        gotoxye(69,5);
        printf("Invalid Choice.");
  }

}
/*----------------------------------------------ADD----------------------------------------------------------*/
void eadd()
{
    FILE *fp;
    struct event std;
    char another ='y';
    system("cls");
  	if(r==1)
    	fp = fopen("techev.txt","ab+");
	else
		fp = fopen("nontechev.txt","ab+");
	if(fp == NULL){
	        gotoxye(10,5);
    	printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxye(69,3);
        printf("<---------------:ADD EVENT DETAILS:--------------->");
        gotoxye(69,6);
        printf("---------------------------------------------------");
        gotoxye(69,9);
        printf("NAME OF THE EVENT\t: ");
        gets(std.name);
        gotoxye(69,11);
        printf("TIMING[HH:MM]\t: ");
        gets(std.timing);
        gotoxye(69,13);
        fflush(stdin);
        printf("FEE\t\t: ");
       	scanf("%f",&std.fee);
       	fflush(stdin);
       	gotoxye(69,15);
        printf("VENUE\t\t: ");
       	gets(std.location);
        gotoxye(69,17);
        printf("BRANCH\t\t: ");
       	gets(std.branch);
        fflush(stdin);
        gotoxye(69,20);
        printf("---------------------------------------------------");
        fwrite(&std,sizeof(std),1,fp);
      gotoxye(69,22);
        printf("Want to add of another record?");
        gotoxye(69,23);
        printf("if YES enter 'y' ");
        gotoxye(69,24);
        printf("if NO enter 'n'  ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxye(69,1);
    printf("Press any key to continue.");
    getch();
    if(r==1)
    	techev();
    else
    	nontechev();

}
/*-----------------------------------------DISPLAY/VIEW--------------------------------------------------------*/
void eview()
{
	FILE *fp;
    int i=1,j;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :EVENT VIEW RECORD: >\n");
    gotoxye(29,5);
    printf("----------------------------------------------------------------------------------------------------");
   gotoxye(30,8);
    printf("S.No \t EVENT NAME\t\tEVENT TIMING \t   FEE \t\t VENUE\t\tBRANCHES");
    gotoxye(29,11);
    printf("----------------------------------------------------------------------------------------------------");
     if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(31,14);
        printf("Error opening file.");
        exit(1);
    }
    j=14;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxye(31,j);
        printf("%-10d%-24s%-17s%-14f%-18s%-20s",i,std.name,std.timing,std.fee,std.location,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxye(69,j+3);
    printf("Press any key to continue.");
    getch();
    if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------SEARCH---------------------------------------------------------*/
void esearch()
{
	int p=0;
    FILE *fp;
    struct event std;
    char evname[20];
    system("cls");
    gotoxye(69,3);
    printf("< :SEARCH EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(69,7);
    printf("Enter Event Name to Search: ");
    fflush(stdin);
    gets(evname);
    if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(10,6);
        printf("Error opening file");
        exit(1);
    }
    gotoxye(60,9);
        	printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(strlwr(evname),strlwr(std.name)) == 0){
             gotoxye(60,11);
            printf("EVENT NAME\t\t: %s",std.name);
            gotoxye(60,13);
            printf("EVENT TIMING[HH:MM]\t: %s",std.timing);
            gotoxye(60,15);
            printf("FEE\t\t\t: %f",std.fee);
            gotoxye(60,17);
            printf("VENUE\t\t: %s",std.location);
            gotoxye(60,19);
            printf("BRANCH\t\t: %s",std.branch);

            p=1;
        }
    }
    fclose(fp);
    gotoxye(69,16);
    if(p==0){
    gotoxye(69,16);
      printf("Sorry, Data Not Found With Name: %s\n",evname);
  	}
      gotoxye(60,21);
            printf("=====================================================");
    gotoxye(69,23);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------UPDATE/MODIFY------------------------------------------*/
void emodify()
{
	int p=0;
    char evname[20];
    FILE *fp;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :MODIFY EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(64,7);
    printf("Enter Event Name to Modify Details: ");
    fflush(stdin);
    gets(evname);
    if(r==1)
    	fp = fopen("techev.txt","rb+");
    else
    	fp = fopen("nontechev.txt","rb+");
    if(fp == NULL){
        gotoxye(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    gotoxye(60,9);
    printf("=====================================================");
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(strlwr(evname),strlwr(std.name))== 0){
           p=1;
            gotoxye(60,11);
            printf("EVENT NAME\t\t: ");
            gets(std.name);
            gotoxye(60,13);
            printf("EVENT TIMING[HH:MM]\t: ");
            gets(std.timing);
            gotoxye(60,15);
            printf("FEE\t\t\t: ");
            scanf("%f",&std.fee);
            gotoxye(60,17);
            fflush(stdin);
            printf("VENUE\t\t: ");
            gets(std.location);
            gotoxye(60,19);
            printf("BRANCHES\t\t: ");
            gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(p==0)
    {
    	gotoxye(67,15);
    	printf("Event Data Not Found With Name %s",evname);
	}
	gotoxye(60,21);
            printf("=====================================================");

    fclose(fp);
    gotoxye(69,23);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*--------------------------------------------DELETE------------------------------------------*/
void edelete()
{
	int p=0;
    char evname[20];
    FILE *fp,*ft;
    struct event std;
    system("cls");
    gotoxye(69,3);
    printf("< :DELETE EVENT RECORD: >");
    gotoxye(60,5);
    printf("-----------------------------------------------------");
    gotoxye(69,7);
    printf("Enter Event Name to Delete: ");
    fflush(stdin);
    gets(evname);
    strlwr(evname);
    if(r==1){
    	fp = fopen("techev.txt","rb+");
	    	if(fp == NULL){
	        gotoxye(10,6);
	        printf("Error opening file");
	        exit(1);
		    }
	    ft = fopen("temp.txt","wb+");
		    if(ft == NULL){
		        gotoxye(10,6);
		        printf("Error opening file");
		        exit(1);
		    }
	    while(fread(&std,sizeof(std),1,fp) == 1){
	        if(strcmp(evname,strlwr(std.name))!=0)
	            fwrite(&std,sizeof(std),1,ft);
	        else
	        	p=1;
	    }
	    fclose(fp);
	    fclose(ft);
	    remove("techev.txt");
	    rename("temp.txt","techev.txt");

	}
    else{
    	fp = fopen("nontechev.txt","rb+");
	    	if(fp == NULL){
	        gotoxye(10,6);
	        printf("Error opening file");
	        exit(1);
	    	}
    	ft = fopen("temp1.txt","wb+");
		    if(ft == NULL){
		        gotoxye(10,6);
		        printf("Error opening file");
		        exit(1);
		    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(evname,strlwr(std.name))!=0)
            fwrite(&std,sizeof(std),1,ft);
        else
        	p=1;
    }
    fclose(fp);
    fclose(ft);
    remove("nontechev.txt");
    rename("temp1.txt","nontechev.txt");

	}
	gotoxye(60,10);
    printf("=====================================================");
    if(p==1)
    {
    	gotoxye(69,14);
        printf("	Deletion sucessful..");
    }
    else
    {
		gotoxye(69,14);
        printf("No Event Found With Name:%s",evname);
    }
    gotoxye(60,18);
    printf("=====================================================");
    gotoxye(69,20);
    printf("Press any key to continue.");
    getch();
   if(r==1)
    	techev();
    else
    	nontechev();

}
/*-------------------------------------------------GOTXY-----------------------------------------------*/
void gotoxye(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

