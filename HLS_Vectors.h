#define ARRAY_SIZE 100
#include <ap_int.h>

typedef ap_int<16> Vector[ARRAY_SIZE];

template<class TVector, unsigned int vectorSize>
void hls_vectorSum(const TVector inVector1,
              const TVector inVector2,
              TVector outVectorSum);

ap_int<16> hls_vectorScalarProduct(const Vector inVector1,
              const Vector inVector2);

void hls_vectorOperations(
              const Vector inVector1,
              const Vector inVector2, 
              Vector outVectorSum,
              ap_int<16> & outProduct
             );