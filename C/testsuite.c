#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "math.h"
#include <stdio.h>

/*************** Tests unitaires du module math ****************/

/** Montage de la fixation - appelé avant chaque cas de test. **/
int init_suite(void) { return 0; }

/* Démontage de la fixation - appelé après chaque cas de test. */
int clean_suite(void) { return 0; }

/************ Cas de test - arguments du même signe ************/
void test_max_meme_signe(void) {
  CU_ASSERT_EQUAL( max(3.1415, 0.1234), 3.1415);
  CU_ASSERT_EQUAL( max(2, 1), 2);
}

/********** Cas de test - arguments de signes opposés **********/ 
void test_max_signes_opposes(void) {
  CU_ASSERT_EQUAL( max(-2.1, 2.1), 2.1);
  CU_ASSERT_EQUAL( max(2.1, -2.1), 2.1);
}

/********* Cas de test - arguments de valeurs égales ***********/ 
void test_max_egalite(void) {
  CU_ASSERT_EQUAL( max(0, 0), 0);
  CU_ASSERT_EQUAL( max(-100.01, -100.01), -100.01);
  CU_ASSERT_EQUAL( max(123.4, 123.4), 123.4);
}

/******************* Lancement des tests ***********************/
int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialisation des test CUnit */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* ajout de la suite de test */
   pSuite = CU_add_suite( "Test module math", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ajout des cas de test dans la suite de test */
   if ( (NULL == CU_add_test(pSuite, "Cas de test max : arguments du même signe", test_max_meme_signe)) ||
        (NULL == CU_add_test(pSuite, "Cas de test max : arguments de signes opposés", test_max_signes_opposes)) ||
        (NULL == CU_add_test(pSuite, "Cas de test max : arguments égaux", test_max_egalite))
      )
   {;
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* lancement de tous les tests avac l'interface de base */
   CU_basic_set_mode(CU_BRM_NORMAL);
   if ( CUE_SUCCESS != CU_basic_run_tests() )
      return CU_get_error();
   
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* cloture des tests */
   CU_cleanup_registry();
   return status;
}
