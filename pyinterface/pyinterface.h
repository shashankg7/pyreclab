#ifndef __PY_INTERFACE_H__
#define __PY_INTERFACE_H__

#include <Python.h> // This header was set at the first place to avoid warnings
#include <signal.h>

#include "DataReader.h"
#include "RatingMatrix.h"
#include "RecSysAlgorithm.h"
#include "MAE.h"
#include "RMSE.h"


class PrlSigHandler
{
public:

   enum EAlgType
   {
      UNKNOWN,
      FUNK_SVD,
      ITEM_AVG,
      ITEM_KNN,
      MOST_POPULAR,
      SLOPE_ONE,
      USER_AVG,
      USER_KNN
   };

   static
   void handler( int signum );

   static
   void registerObj( PyObject* obj, EAlgType type );

   static
   void unregisterObj();

   static
   struct sigaction* handlesignal( int signum );

   static
   void restoresignal( int signum, struct sigaction* pAction );

private:

   static
   EAlgType m_algType;

   static
   PyObject* m_activeObj;

};

#endif // __PY_INTERFACE_H__

