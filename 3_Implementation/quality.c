//#include "student_details.c"
//#include "checking.h"
#include "unity.h"
extern int check(int rollno);
extern int passcheck(char x[]);
extern int percent_check(int ro_no,int num_days );
extern float attendence_cal(int rollno,int days);
extern int pers(int roll,int numdays);
void quality();
void setUp(void){

}
void tearDown(void){

}
int fircheck(int roll_no,int days,int exp){
    if(pers(roll_no,days)==exp)
    return 1;
    else 
    return 0;
}
int seccheck(int roll,int days,int expect){
	int x=attendence_cal(roll,days);
	if(expect==x)
	return 1;
	else
	return 0;
    }

void quality1(){
    TEST_ASSERT_EQUAL(1,check(1));
    TEST_ASSERT_EQUAL(0,check(-1));
    TEST_ASSERT_EQUAL(1,check(5));}
void quality2(){
    TEST_ASSERT_EQUAL(1,passcheck("12345"));
    TEST_ASSERT_EQUAL(1,passcheck("12345"));
    TEST_ASSERT_EQUAL(0,passcheck("  "));}
void quality3(){
    TEST_ASSERT_EQUAL(0,percent_check(1,3));
    TEST_ASSERT_EQUAL(0,percent_check(2,3));
    TEST_ASSERT_EQUAL(0,percent_check(3,3));}
void quality4(){
    TEST_ASSERT_EQUAL(1,seccheck(5,5,100));
    TEST_ASSERT_EQUAL(1,seccheck(2,4,50));
    TEST_ASSERT_EQUAL(0,seccheck(0,0,10));}
void quality5(){
    TEST_ASSERT_EQUAL(0,fircheck(1,2,1));//expect less than 75% 1 else 0
    TEST_ASSERT_EQUAL(1,fircheck(2,2,0));
    TEST_ASSERT_EQUAL(0,fircheck(3,2,1));
}


int test_code(){
    UnityBegin(NULL);
    RUN_TEST(quality1);
     RUN_TEST(quality2); RUN_TEST(quality3); RUN_TEST(quality4);RUN_TEST(quality5);
    return (UnityEnd());
} 

