//
// Copyright (c) 2012 Juan Palacios juan.palacios.puyana@gmail.com
// This file is part of minimathlibs.
// Subject to the BSD 2-Clause License 
// - see < http://opensource.org/licenses/BSD-2-Clause>
//



#ifndef MATH_GEOM3DOPS_H__
#define MATH_GEOM3DOPS_H__

#include "Math/Rotation3D.h"
#include "Math/Point3D.h"
#include "Math/Translation3D.h"
//
// Helper functions for operations between the Geom3D workd and
// the Matrix world.
//
// @author Juan Palacios juan.palacios.puyana@gmail.com
//

namespace Math {

// multiplication between a 3x3 matrix and a 3D point
template <typename T, template <typename> class C>
Point3D<T, C> operator*(const Matrix<T,3>& rot, 
                        const Point3D<T, C>&  point) 
{
  double elements[3];
  for (unsigned int row = 0; row < 3; ++row) {
    double element = 0;
    for (unsigned int i = 0; i < 3; ++i) {
      element+= rot(row,i) * point[i];
    }
    elements[row] = element; // dot prod of LHS row, RHS col
  }
  return Point3D<T, C> (elements[0], elements[1], elements[2]);

} 

// multiplication between a 3x3 matrix and a 3D point
template <typename T>
Translation3D operator*(const Matrix<T,3>& rot, 
                        const Translation3D&  point) 
{
  typedef Translation3D::vector_type vector_type_;
  double elements[3];
  for (unsigned int row = 0; row < 3; ++row) {
    double element = 0;
    for (unsigned int i = 0; i < 3; ++i) {
      element+= rot(row,i) * point[i];
    }
    elements[row] = element; // dot prod of LHS row, RHS col
  }
  return Translation3D(vector_type_(elements[0], elements[1], elements[2]));

} 

///
/// Find the transformation matrix T such that
/// T * lhs = rhs
///
template <typename T1, typename T2>
T1 transformation(T1 lhs, 
                  const T2& rhs,
                  bool& success)
{
  return rhs*(lhs.inverse(success)); 
}


}

#endif
