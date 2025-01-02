#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "max.h"

#include <stdio.h>  // for printf

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/

void test_case_sample(void)
{
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}

void max_test_1(void) {
  CU_ASSERT_EQUAL( max(1,2), 2);
  CU_ASSERT_EQUAL( max(2,1), 2);
}

void max_test_2(void) {
  CU_ASSERT_EQUAL( max(2,2), 2);
  CU_ASSERT_EQUAL( max(0,0), 0);
  CU_ASSERT_EQUAL( max(-1,-1), -1);
}

void max_test_3(void) {
  CU_ASSERT_EQUAL( max(-1,-2), -1);
}

/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "max_test_1", max_test_1)) ||
        (NULL == CU_add_test(pSuite, "max_test_2", max_test_2)) ||
        (NULL == CU_add_test(pSuite, "max_test_3", max_test_3))
      )
   {;
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_NORMAL);
   CU_basic_run_tests();
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* Clean up registry and return */
   CU_cleanup_registry();
   return status;
}
