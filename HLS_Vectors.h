#define ARRAY_SIZE 100
#include <ap_int.h>
#include "HLS_Vector.h"

typedef hls::Vector<ap_int<16>, ARRAY_SIZE> CPPVector;
typedef ap_int<16> CVector[ARRAY_SIZE];

void hls_vectorOperations(
              const CVector inVector1,
              const CVector inVector2, 
              CVector outVectorSum,
              ap_int<16> & outProduct
             );