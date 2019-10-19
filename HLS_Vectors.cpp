#include "HLS_Vectors.h"
#include <ap_int.h>

#ifndef __SYNTHESIS__
#include <iostream>
#endif


void hls_vectorSum(const Vector inVector1,
              const Vector inVector2,
              Vector outVectorSum)
{
  sumLoop: for (unsigned int x = 0 ; x < ARRAY_SIZE ; x++)
  {
    outVectorSum[x] = inVector1[x] + inVector2[x];
  }
  return;
}

ap_int<16> hls_vectorScalarProduct(const Vector inVector1,
              const Vector inVector2)
{
  ap_int<16> lProduct = 0;
  productLoop: for (unsigned int x = 0 ; x < ARRAY_SIZE ; x++)
  {
    lProduct += (inVector1[x] * inVector2[x]);
  }
  return lProduct;
}

void hls_vectorOperations(
              const Vector inVector1,
              const Vector inVector2,
              Vector outVectorSum,
              ap_int<16> & outProduct
             )
{
  // __SYNTHESIS__ is defined only during synthesis
  // wrap code you do not want to be synthesised in ifndef __SYNTHESIS__
  // conversely, wrap code you want to be synthetised, but not compiled in ifdef __SYNTHESIS__
  #ifndef __SYNTHESIS__ 
  std::cout << "Multiplyin' stuff up!" << std::endl;
  #endif
  outProduct = hls_vectorScalarProduct(inVector1, inVector2);
  
  #ifndef __SYNTHESIS__ 
  std::cout << "Summin' stuff up!" << std::endl;
  #endif
  hls_vectorSum(inVector1, inVector2, outVectorSum);
}