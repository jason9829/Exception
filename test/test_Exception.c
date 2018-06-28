#include "unity.h"
#include "Exception.h"
#include "CException.h"


//*******ERROR DEFINITION********
//#define ERR_OUT_OF_BOUND "Index out of bound bro, try again"  // error message not a good way for string might failed if allocated more than 4GB
#define ERR_OUT_OF_BOUND 3  // error message
#define ERR_UNKNOWN_COMPANY 4
#define ERR_UNKNOWN_PEOPLE 5

void setUp(void){}

void tearDown(void){}

char *namesInIntel[] = {
  "Ali",
  "David",
  "Ah Beng",
  "Man"
};

char *namesInNvidia[] = {
  "Leong",
  "Jacky",
  "OPM",
  "Benny"
};
char *namesInAMD[] = {
  "LZS",
  "Vashan",
  "Abu",
  "Ah Meng"
};
char *namesInNestle[] = {
  "Ahmad",
  "Gordan",
  "Wei"
};

// names is array of 4 of pointer to char
/*char * names[] = {
  "Ali",
  "David",
  "Ah Beng",
  "Jason"
};*/

// companies is array of 4 of pointer to char
char *companies[] = {
  "Intel",
  "Nvidia",
  "AMD",
  "Nestle"
};

char *getNamesInCompany(int companyIdx, int nameIdx)
{
  CEXCEPTION_T e;
  char *name;
  switch(companyIdx){
    case 0:   // Intel
    //Try{
      name = getNamesInTable(nameIdx,namesInIntel,4);
  //  } Catch(e)
  //  {
//if(e == ERR_UNKNOWN_PEOPLE 5){

//}
//}
      break;
    case 1:   // Nvidia
      name = getNamesInTable(nameIdx,namesInNvidia,4);
      break;
    case 2:   // AMD
      name = getNamesInTable(nameIdx,namesInAMD,4);
      break;
    case 3:   // Nestle
      name = getNamesInTable(nameIdx,namesInNestle,3);
      break;
    default:
     Throw(ERR_UNKNOWN_COMPANY);
  }
      return name;
}

char *getNamesInTable(int index, char *names[],int maxSize)
{

  if(index >= maxSize || index < 0)
  {
    Throw(ERR_OUT_OF_BOUND);
  }
  return names[index];
}

char *getName(int index)
{
  if(index >= 4 || index < 0)
  {
  Throw(ERR_OUT_OF_BOUND);
  }
  return names[index];
}

void test_getNameInCompany_given_company1_and_people2_expect_Jacky(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getNamesInCompany(1,1);
    TEST_ASSERT_EQUAL_STRING("Jacky",name);
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    TEST_FAIL_MESSAGE("Expected no ERR_UNKNOWN_COMPANY"); // if thrown but unexptected
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_1_expect_David(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(1);
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    TEST_FAIL_MESSAGE("Expected no ERR_OUT_OF_BOUND"); // if thrown but unexptected
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(-1);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");   // if not thrown and catch
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(4);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}
