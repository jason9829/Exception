#include "build/temp/_test_Exception.c"
#include "CException.h"
#include "Exception.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



char * namesInIntel[] = {

  "Ali",

  "David",

  "Ah Beng",

  "Man"

};



char * namesInNvidia[] = {

  "Leong",

  "Jacky",

  "OPM",

  "Benny"

};

char * namesInAMD[] = {

  "LZS",

  "Vashan",

  "Abu",

  "Ah Meng"

};

char * namesInNestle[] = {

  "Ahmad",

  "Gordan",

  "Wei"

};

char * companies[] = {

  "Intel",

  "Nvidia",

  "AMD",

  "Nestle"

};



char *getNamesInCompany(int companyIdx, int nameIdx)

{

  unsigned int e;

  char *name;

  switch(companyIdx){

    case 0:



      name = getNamesInTable(nameIdx,namesInIntel,4);













      break;

    case 1:

      name = getNamesInTable(nameIdx,namesInNvidia,4);

      break;

    case 2:

      name = getNamesInTable(nameIdx,namesInAMD,4);

      break;

    case 3:

      name = getNamesInTable(nameIdx,namesInNestle,3);

      break;

    default:

     Throw(4);

  }

      return name;

}



char *getNamesInTable(int index, char *names[],int maxSize)

{



  if(index >= maxSize || index < 0)

  {

    Throw(3);

  }

  return names[index];

}



char *getName(int index)

{

  if(index >= 4 || index < 0)

  {

  Throw(3);

  }

  return names[index];

}



void test_getNameInCompany_given_company1_and_people2_expect_Jacky(void)

{

    unsigned int e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getNamesInCompany(1,1);

    UnityAssertEqualString((const char*)(("Jacky")), (const char*)((name)), (

   ((void *)0)

   ), (UNITY_UINT)(116));



  } else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Expected no ERR_UNKNOWN_COMPANY")), (UNITY_UINT)(120));



  }



}



void test_Exception_given_1_expect_David(void)

{

    unsigned int e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(1);



  } else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Expected no ERR_OUT_OF_BOUND")), (UNITY_UINT)(135));



  }



}



void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void)

{

    unsigned int e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(-1);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(147));



  } else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {



  }



}



void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void)

{

    unsigned int e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(4);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(162));



  } else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {



  }



}
