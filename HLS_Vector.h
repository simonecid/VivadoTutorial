

namespace hls
{
  //Base n-dimensional vector class able to run basic operations
  template <class TScalar, unsigned int length>
  class Vector
  {
    private:
      TScalar _data[length];
    public:
      //Base constructor
      Vector();
      //Initialises a vector starting from a C-style one
      Vector(const TScalar init[length]);
      //Adds two vectors
      Vector<TScalar, length> operator+ (const Vector<TScalar,length> & aVector) const;
      //Copies from a C-style vector
      void operator= (const TScalar values[length]);
      //Copies from another vector 
      void operator= (const Vector<TScalar, length> aVector);
      //Scalar multiplication
      TScalar operator* (const Vector<TScalar,length> & aVector) const;
      //Single element access
      TScalar & operator[] (unsigned int index);
      //Copies to a C-style vector
      void copyToArray(TScalar dest[length]) const;
  };
}

template <class TScalar, unsigned int length>
hls::Vector<TScalar, length>::Vector()
{
  #pragma HLS inline
  // Partitioning of class variables must be done in the constructor
  #pragma HLS array_partition variable=_data
}

template <class TScalar, unsigned int length>
hls::Vector<TScalar, length>::Vector(const TScalar init[length])
{
  #pragma HLS inline
  // Partitioning of class variables must be done in the constructor
  #pragma HLS array_partition variable=_data
  for (unsigned int x = 0; x < length; x++)
  {
    this -> _data[x] = init[x];
  }
}

template <class TScalar, unsigned int length>
hls::Vector<TScalar, length> hls::Vector<TScalar, length>::operator+ (const hls::Vector<TScalar,length> & aVector) const
{
  #pragma HLS inline
  hls::Vector<TScalar, length> lVector;
  for (unsigned int x = 0; x < length; x++)
  {
    lVector._data[x] = this -> _data[x] + aVector._data[x];
  }
  return lVector;
}

template <class TScalar, unsigned int length>
void hls::Vector<TScalar, length>::operator= (const TScalar values[length])
{
  #pragma HLS inline
  for (unsigned int x = 0; x < length; x++)
  {
    this -> _data[x] = values[x];
  }
}

template <class TScalar, unsigned int length>
void hls::Vector<TScalar, length>::operator= (const hls::Vector<TScalar, length> aVector)
{
  #pragma HLS inline
  for (unsigned int x = 0; x < length; x++)
  {
    this -> _data[x] = aVector._data[x];
  }
}

template <class TScalar, unsigned int length>
TScalar hls::Vector<TScalar, length>::operator* (const hls::Vector<TScalar,length> & aVector) const
{
  #pragma HLS inline
  TScalar lProduct = 0;
  for (unsigned int x = 0 ; x < length ; x++)
  {
    lProduct += (this -> _data[x] * aVector._data[x]);
  }
  return lProduct;
}

template <class TScalar, unsigned int length>
TScalar & hls::Vector<TScalar, length>::operator[] (unsigned int index)
{
  #pragma HLS inline
  return this -> _data[index];
}

template <class TScalar, unsigned int length>
void hls::Vector<TScalar, length>::copyToArray(TScalar dest[length]) const
{
  #pragma HLS inline
  for (unsigned int x = 0; x < length; x++)
  {
    dest[x] = this -> _data[x];
  }
}
