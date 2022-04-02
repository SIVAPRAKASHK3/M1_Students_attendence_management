#include<stdio.h>
#include<string.h>
#include "unity.h"
extern int test_code();
extern char str11[10][10];
extern char dup[10][10];
//#include "name.h"
//#include "students_remark.c"
//#include "name_ordering.c"
//#include "checking.h"
int check(int rollno);
extern int passcheck(char x[]);
extern void an();
char chat_org[200];
char chat[200];
void sample();
void remark();
void cpy();
void display();
void menu(void);
void enter(int roll_no);
extern int add();
int arr[20]={0};
char nam[10][20];
char str[6];
extern void retrive();
int number_of_working_days=0;
int cont=3;
extern void login();
void regist();
char string[5];
extern void attendence_percentage();
extern void attendence_eligibility();
int cal=0;

int main(){
    test_code();
	printf("\t LOGIN \n");
	login();  //169
 return 0;  
}
/**THIS THE LOGIN 
*Get the login pic and chech it matches
*if it is wrong it gives try once again option for 3 times
*/
void login(){
	 //int itr;
     printf("Enter the 5 digit pin \n");
 		scanf("%5s",str);
	 if((passcheck(str)==1)) //passcheck is function that will compare with login code 
       menu();
    else{
    	while(cont<=3){
    	if(cont==0)
    		break;
    	else
    		{	
        printf("Pin is WRONG try once again \n");
        printf("\t \t \t \t \t<-- REMAINING CHANCE %d TIMES.... -->\n",cont);
         cont--;
		login();}}
	}
}

void regist(){
   printf("Enter the pin");
   int itr;
   for(itr=0;itr<5;itr++)
   scanf("%c",&string[itr]);
}
/**
*This the main menu where you choose the choice given to perform your process
 *1.Add Attendence
 * 2.Retrive Total Days Present
 * 3.Attendence Percentage
 *4.Attendence Eligibility
 *5.Students Remarks
*/
void menu(){
printf("\n");
printf(" \t \t \t \t \t \t MAIN MENU  \n \n \t \t \t 1.Add Attendence \n \t \t \t  2.Retrive Total Days Present \n \t \t \t   3.Attendence Percentage \n \t \t \t    4. The Attendence Eligibility \n \t \t \t     5.Student's Remarks \n \t \t \t ");
int n;
scanf("%d",&n);
if(n>=1&&n<=5){
an();
switch(n){
    case 1:
        add();
        break;
    case 2:
        retrive();
        break;
    case 3:
        attendence_percentage(); //188
        break;
    case 4:
        attendence_eligibility(); //217
        break;
    case 5:
        remark();
        break;
    default:
    	printf("Enter the existing option \n");
    	menu();
} 
}
else{
    printf("Enter Exesting numeric option \n");
	menu();
}
}
void cpy(void){
	char ch=' ';
	char ch1=' ';
	strcpy(chat_org,chat);
	printf("Navigate to menu TYPE ? y/n ");
    scanf("%c",&ch1);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
         menu();
    else{
            printf("Thank you");
        }

}
/** Adding the attencdence by entering the roll
*To end the process tyoe -1
*This add is done by calling the enter fuction
*/
int add(){
    int x=0,i;
    char ch1=' ';
    char ch=' ';
    printf("\t \t <---Roll number starts from 1 end at 10 -->\nEnter the roll number \nTo close Attendence type -1 \n");
    for( i=0;i<10;i++){
       scanf("%d",&x);
       if(x==-1){
            break;
                 }
        else if(!check(x))
            {
                printf("Enter the correct value \n");
                arr[20]=NULL;
                add();
            }
       enter(x);
}
    printf("\nDo you want to enter data for another day TYPE ? y/n ");
    number_of_working_days++;
        scanf("%c",&ch1);
        scanf("%c",&ch);
        printf("\n");
    if(ch=='y'||ch=='Y')
        add();
    else{
        printf("To navigate menu TYPE ? y/n ");
       scanf("%c",&ch1);
        scanf("\n%c",&ch);
            if(ch=='y'||ch=='Y')
                menu();
            else
                printf("Thank you");
        }
    }

void enter(int roll_no){
    arr[roll_no-1]++;
}
void output(){
	int i;
    for( i=0;i<10;i++)
    printf("%d",arr[i]);
}
/**Retrive function fetch the roll as input
*I will get the value stoed the corresponding roll number
*If roll number not present it will ask to enter the existing option
*Gives the output as out of days present from total days
*/
void retrive(){
    int roll_no;
    char ch=' ';
    char ch1=' ';
    printf("Enter the roll number--> ");
    scanf("%d",&roll_no);
    if(!check(roll_no))
    {
    	printf("No such roll number exist");
        retrive();
	}
	else{
    printf("[ %s ] attended for %d out of %d number of working days",dup[roll_no-1],arr[roll_no-1],number_of_working_days);}
    printf("\nDo you want to search for otherS? TYPE y/n ");
    scanf("%c",&ch1);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
         retrive();
    else{
        printf("\nTo Navigate menu TYPE ? y/n ");
        scanf("%c",&ch1);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
            menu();
        else
            printf("Thank you");
        }
}

float attendence_cal(int no_days,int days){
	float n=((float)no_days/days*100);
return n;
}

int check(int rollno){
 if((rollno>=0&&rollno<11))
    {
	return 1;}
 
    return 0;
}
/**Attendence_percentage function will display the percentage of attendence 
*It gets input i.e roll number
*Calculate the attenedence percentage 
*AS final display shows output with name and percentage 
*/
void attendence_percentage()
{
    int rollno;
    if(number_of_working_days==0){
    	printf("Enter the attendence first\n");
    	menu();
	}
	else{
    printf("Enter roll no--> ");
    scanf("%d",&rollno);
    if(!(check(rollno)))
	{
		printf("No such roll number exist");
	}
    else{
    cal=attendence_cal(arr[rollno-1],number_of_working_days); //line 163
    printf("Attendence percentage of [ %s ] is %d",dup[rollno-1],cal);}
    char ch=' ';
    char ch1=' ';
    printf("\nDo you want to find others attendence percentage ? TYPE y/n ");
    scanf("%c",&ch1);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
        attendence_percentage();
    else{
        printf("To Navigate menu TYPE ? y/n ");
        scanf("%c",&ch1);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
            menu();
        else
            printf("Thank you");
        }
}}
int percent_check(int ro_no,int num_days ){
	if(attendence_cal(arr[ro_no-1],num_days)>75){
		return 1;
	}
	else
		return 0;
}
/**Attendece percentage is greater then 75%  will elegible for exam
*It gets input of student roll number and check the whether the persin is eligible or not.
*/
void attendence_eligibility(){
    int roll;
    char ch1,ch;
    if(number_of_working_days==0){
    printf("Enter the attendence first \n");
    menu();
	}
	else{
    printf("Enter the roll number-->  ");
    scanf("%d",&roll);
     if(!(check(roll)))
	{
		printf("No such roll number exist");
	}
    else{
    if(percent_check(roll,number_of_working_days)==1){
        printf("[ %s ] is Eligible for exam",dup[roll-1]);
    }
    else{
        printf("[ %s ] Not Eligible for exam percentage is below 75",dup[roll-1]);}}
        printf("\nDo you want to check for one more... if yes type y else n or anykey  y/n ");
    scanf("%c",&ch1);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
        attendence_eligibility();
    else{
        printf("To Navigate menu TYPE ? y/n ");
        scanf("%c",&ch1);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
            menu();
        else
            printf("Thank you");
        }}
    }

/**Remark can be anything like comments or updates
*To read type 1 
*It read the string which is entered and prints
*To write type 2
*We can report the comments in it.
*/
void remark(){
	printf("*To read remarks type 1 \n\t*To report type 2 \n");
	int itr;
		char ch=' ';
		char ch1=' ';
	scanf("%d",&itr);
	switch(itr){
		case 1:
			display();
		        printf("\nNavigate to menu type ? y/n ");
		        scanf("%c",&ch1);
		        scanf("%c",&ch);
		       // getch();
		        if(ch=='y')
		            menu();
		        else
		            printf("Thank you");
					break;
		case 2:
			sample();
			break;
	}}

void display(void){
	int i,x;
    x=*(&chat_org+1)-chat_org;
	for(i=0;i<x;i++){
		if(chat_org[i]=='|'){
			printf("\n");
		}
		else if(chat_org[i]=='@')
		break;
		else
		printf("%c",chat_org[i]);
	}
}

void sample(){
//	char ch=' ';
//	char ch1=' ';
	printf("FORMATE -> FIRST ROLL NUMBER FOLLOWED BY - THEN TYPE YOUR MESSEGE AT END CLOSE WITH | AT THE END OF REMARK CLOSE WITH @ \nEXAMPLE :1-IN LESS ATTENDENCE@\n");
scanf("%100s",chat);
cpy();
}
//
// int check(int rollno){
// if((rollno>=0&&rollno<11))
//    {
// 	return 1;}

//    return 0;
// }
