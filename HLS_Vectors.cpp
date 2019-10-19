#include "HLS_Vectors.h"
#include <ap_int.h>

#ifndef __SYNTHESIS__
#include <iostream>
#endif

void hls_vectorOperations(
              const CVector inVector1,
              const CVector inVector2,
              CVector outVectorSum,
              ap_int<16> & outProduct
             )
{

  //partition the memory in smaller areas, to increase memory throughput and enable parallel access
  #pragma HLS array_partition variable=inVector1
  #pragma HLS array_partition variable=inVector2
  #pragma HLS array_partition variable=outVectorSum
  //maximising throughput by pipelining the function code, and unrolling and pipelining any underlying loop
  #pragma HLS pipeline

  CPPVector lVector1(inVector1), lVector2, lVectorSum;
  lVector2 = inVector2;

  // __SYNTHESIS__ is defined only during synthesis
  // wrap code you do not want to be synthesised in ifndef __SYNTHESIS__
  // conversely, wrap code you want to be synthetised, but not compiled in ifdef __SYNTHESIS__
  #ifndef __SYNTHESIS__ 
  std::cout << "Summin' stuff up with C++ classes!" << std::endl;
  #endif
  lVectorSum = lVector1 + lVector2;
  lVectorSum.copyToArray(outVectorSum);
  
  #ifndef __SYNTHESIS__ 
  std::cout << "Multiplyin' stuff up with C++ classes!" << std::endl;
  #endif
  outProduct = lVector1 * lVector2;
}