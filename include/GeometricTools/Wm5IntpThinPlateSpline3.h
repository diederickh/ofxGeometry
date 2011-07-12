// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.1 (2010/10/01)

#ifndef WM5INTPTHINPLATESPLINE3_H
#define WM5INTPTHINPLATESPLINE3_H

// WARNING.  This code maps the inputs (x,y,z) to the unit cube.  The thin
// plate spline function evaluation maps the input to the unit cube and
// performs the interpolation in that space.  The idea is to keep the floating
// point numbers to order 1 for numerical stability of the algorithm. Some
// folks are not excited about this preprocessing step as it is not part of
// the classical thin plate spline algorithm.  It is easy enough for you to
// remove the remappings from the code.

#include "Wm5MathematicsLIB.h"

namespace Wm5
{

template <typename Real>
class WM5_MATHEMATICS_ITEM IntpThinPlateSpline3
{
public:
    // Construction and destruction.  Data points are of form
    // (x,y,z,f(x,y,z)).  The smoothing parameter must be nonnegative.  If you
    // want IntpThinPlateSpline3 to delete the input arrays during
    // destruction, set owner to 'true'.  Otherwise, you own the arrays and
    // must delete them yourself.
    IntpThinPlateSpline3 (int quantity, Real* X, Real* Y, Real* Z,
        Real* F, Real smooth, bool owner);

    ~IntpThinPlateSpline3 ();

    // Check this after the constructor call to see if the thin plate spline
    // coefficients were successfully computed.  If so, then calls to
    // operator()(Real,Real,Real) will work properly.
    bool IsInitialized () const;

    // Evaluate the thin plate spline interpolator.  If IsInitialized()
    // returns 'false', this operator will always return MAX_REAL.
    Real operator() (Real x, Real y, Real z);

private:
    static Real Kernel (Real t);

    bool mInitialized;
    int mQuantity;

    // Input data mapped to unit cube.
    Real* mX;
    Real* mY;
    Real* mZ;

    // Thin plate spline coefficients.
    Real* mA;
    Real mB[4];

    // Extent of input data.
    Real mXMin, mXMax, mXInvRange;
    Real mYMin, mYMax, mYInvRange;
    Real mZMin, mZMax, mZInvRange;
};

typedef IntpThinPlateSpline3<float> IntpThinPlateSpline3f;
typedef IntpThinPlateSpline3<double> IntpThinPlateSpline3d;

}

#endif
