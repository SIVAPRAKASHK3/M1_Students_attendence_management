#include<string.h>
#include<stdio.h>
char str1[6]="12345";
int passcheck(char x[]){
	if(strcmp(x,str1)==0)
	return 1;
	
	return 0;
}
//void remark(){ 
//	printf("*To read remarks type 1 \n\t*To report type 2 \n");
//	int itr;
//		char ch=' ';
//		char ch1=' ';
//	scanf("%d",&itr);
//	switch(itr){
//		case 1:
//			display();
//		        printf("\nNavigate to menu type ? y/n ");
//		        scanf("%c",&ch1);
//		        scanf("%c",&ch);
//		       // getch();
//		        if(ch=='y')
//		            menu();
//		        else
//		            printf("Thank you");
//					break;
//		case 2:
//			sample();
//			break;
//	}}
//
//void sample(){
////	char ch=' ';
////	char ch1=' ';
//	printf("FORMATE -> FIRST ROLL NUMBER FOLLOWED BY - THEN TYPE YOUR MESSEGE AT END CLOSE WITH | AT THE END OF REMARK CLOSE WITH @ \nEXAMPLE :1-IN ATTENTIV|2.TALKATTIVE@\n");
//scanf("%100s",chat);
//cpy();
//}
