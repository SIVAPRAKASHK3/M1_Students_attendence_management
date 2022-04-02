#include<stdio.h>
extern void add();
extern int attendence_eligibility(int ro_no,int num_days);
int pers(int roll,int numdays){
    add();
if(attendence_eligibility(roll,numdays)==1){
    
return 1;
}
return 0;
}
// int main(){
//     printf("%d",pers(1,2));
// }