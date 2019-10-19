#include "HLS_Vectors.h"
#include <ap_int.h>
#include <iostream>
#include <assert.h>
#include <vector>

int main(int argc, char const *argv[])
{
  Vector lArray1;
  Vector lArray2;
  Vector lArray3;
  ap_int<16> lProduct;

  for (int a = 0; a < ARRAY_SIZE; a++)
  {
    lArray1[a] = 0;
    lArray2[a] = 0;
  }

  hls_vectorOperations(lArray1, lArray2, lArray3, lProduct);

  // checking the sum and product of null vector is null
  for (int a = 0; a < ARRAY_SIZE; a++)
  {
    assert(lArray3[a] == 0);
  }
  assert(lProduct == 0);

  //checking sum and product of non-null vectors    
  for (int a = 0; a < ARRAY_SIZE; a++)
  {
    lArray1[a] = 0;
    lArray2[a] = 0;
  }

  lArray1[10] = 12;
  lArray2[10] = 90;
  lArray1[67] = 67;
  lArray2[67] = -2;
  lArray2[88] = -179;

  hls_vectorOperations(lArray1, lArray2, lArray3, lProduct);

  for (int a = 0; a < ARRAY_SIZE; a++)
  {
    switch (a) {
      case 10: assert(lArray3[a] == 102); break;
      case 67: assert(lArray3[a] == 65); break;
      case 88: assert(lArray3[a] == -179); break;
      default: assert(lArray3[a] == 0); break;
    }
  }
  assert(lProduct == 946);

  std::cout << "All test have succeeded!" << std::endl;

}