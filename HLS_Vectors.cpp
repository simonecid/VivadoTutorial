#include "HLS_Vectors.h"
#include <ap_int.h>

#ifndef __SYNTHESIS__
#include <iostream>
#endif


// Template function to sum two vectors of any size
template<class TSrcVector, class TDestVector, unsigned int vectorSize>
void hls_vectorSum(TSrcVector inVector1,
              TSrcVector inVector2,
              TDestVector outVectorSum)
{
  // inlining the function code to enable further optimisation and save latency and resources
  #pragma HLS inline
  sumLoop: for (unsigned int x = 0 ; x < vectorSize ; x++)
  {
    outVectorSum[x] = inVector1[x] + inVector2[x];
  }
  return;
}

ap_int<16> hls_vectorScalarProduct(const Vector inVector1,
              const Vector inVector2)
{
  // inlining the function code to enable further optimisation and save latency and resources
  #pragma HLS inline
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

  //partition the memory in smaller areas, to increase memory throughput and enable parallel access
  #pragma HLS array_partition variable=inVector1
  #pragma HLS array_partition variable=inVector2
  #pragma HLS array_partition variable=outVectorSum
  //maximising throughput by pipelining the function code, and unrolling and pipelining any underlying loop
  #pragma HLS pipeline

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
  hls_vectorSum<const Vector, Vector, ARRAY_SIZE>(inVector1, inVector2, outVectorSum);
}