//
// Copyright (c) 2012 Juan Palacios juan.palacios.puyana@gmail.com
// This file is part of minimathlibs.
// Subject to the BSD 2-Clause License 
// - see < http://opensource.org/licenses/BSD-2-Clause>
//

#ifndef TESTS_TRANSLATION3D_H_
#define TESTS_TRANSLATION3D_H_

#include <vector>
#include <numeric>
#include <functional>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Math/Translation3D.h"
#include "Math/Point3D.h"

namespace
{
  using namespace Math;
  //using Math::Translation3D;
  //using Math::PointXYZD;
}

class TestTranslation3D : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestTranslation3D);
  CPPUNIT_TEST(testInstantiation);
  CPPUNIT_TEST(testDefaultEquality);
  CPPUNIT_TEST(testCopyConstruction);
  CPPUNIT_TEST(testAssignment);
  CPPUNIT_TEST(testNullTranslation);
  CPPUNIT_TEST(testTranslatePoint);
  CPPUNIT_TEST(testCompoundTranslation);
  CPPUNIT_TEST(testInverse);
  CPPUNIT_TEST(testInvert);
  CPPUNIT_TEST_SUITE_END();

 protected:

  void testInstantiation()
  {
    Translation3D<double> displ1, displ2;
  }

  void testDefaultEquality()
  {
    CPPUNIT_ASSERT(Translation3D<double>() == Translation3D<double>());
  }

  void testCopyConstruction()
  {
    Translation3D<double> displ1;
    Translation3D<double> displ2(displ1);
    CPPUNIT_ASSERT(displ1==displ2);
  }

  void testAssignment()
  {
    Translation3D<double> displ1, displ2;
    displ2 = displ1;
    CPPUNIT_ASSERT(displ1==displ2);
  }

  void testNullTranslation() {
    PointXYZD p(11, 22, 33);
    CPPUNIT_ASSERT(PointXYZD(11,22,33) == Translation3D<double>()*p);
  }

  void testTranslatePoint() {
    for (int i = 0; i < 100; ++i)
    {
      PointXYZD p(11, 22, 33);
      Translation3D<double> t1(PointXYZD(i, i, i));
      CPPUNIT_ASSERT(PointXYZD(11+i, 22+i, 33+i) == t1*p);
      Translation3D<double> t2(PointXYZD(-i, -i, -i));
      CPPUNIT_ASSERT(PointXYZD(11-i, 22-i, 33-i) == t2*p);
    }
  }

  void testCompoundTranslation()
  {
    // make a vector of many translations
    std::vector<Translation3D<double> > v;
    int sum = 0;
    for (int i = 0; i<10; ++i)
    {
      sum += i;
      v.push_back(Translation3D<double>(PointXYZD(i,i,i)));
    }
    // multiply all the translations together
    Translation3D<double> t = std::accumulate(v.begin(), v.end(),
                                      Translation3D<double>(), 
                                      std::multiplies<Translation3D<double> >());
    CPPUNIT_ASSERT(PointXYZD(sum, sum, sum) == t*PointXYZD());
  }

  void testInverse()
  {
    Translation3D<double> t0(PointXYZD(1., 2., 3.));
    CPPUNIT_ASSERT(t0.inverse() == Translation3D<double>(PointXYZD(-1., -2., -3.)));
  }
  void testInvert()
  {
    Translation3D<double> t0(PointXYZD(1., 2., 3.));
    t0.invert();
    CPPUNIT_ASSERT(t0 == Translation3D<double>(PointXYZD(-1., -2., -3.)));
  }

};


#endif

