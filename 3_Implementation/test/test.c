/**
 * @file test_student_management.c
 * @author Mohammad Karamathulla 40020717
 * @brief 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include "student.h"

/* Modify these two lines according to the project */
#define PROJECT_NAME    "Student"

/* Prototypes for all the test functions */
void test_stud(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_stud);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_stud(void) {
  TEST_ASSERT_EQUAL(SUCCESS, Add());

}
