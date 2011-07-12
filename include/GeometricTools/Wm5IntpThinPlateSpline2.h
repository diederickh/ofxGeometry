// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.1 (2010/10/01)

#ifndef WM5INTPTHINPLATESPLINE2_H
#define WM5INTPTHINPLATESPLINE2_H

// WARNING.  This code maps the inputs (x,y) to the unit square.  The thin
// plate spline function evaluation maps the input to the unit square and
// performs the interpolation in that space.  The idea is to keep the floating
// point numbers to order 1 for numerical stability of the algorithm. Some
// folks are not excited about this preprocessing step as it is not part of
// the classical thin plate spline algorithm.  It is easy enough for you to
// remove the remappings from the code.

#include "Wm5MathematicsLIB.h"

namespace Wm5
{

template <typename Real>
class WM5_MATHEMATICS_ITEM IntpThinPlateSpline2
{
public:
    // Construction and destruction.  Data points are of form (x,y,f(x,y)).
    // The smoothing parameter must be nonnegative.  If you want
    // IntpThinPlateSpline2 to delete the input arrays during destruction, set
    // owner to 'true'.  Otherwise, you own the arrays and must delete them
    // yourself.
    IntpThinPlateSpline2 (int quantity, Real* X, Real* Y,
        Real* F, Real smooth, bool owner);

    ~IntpThinPlateSpline2 ();

    // Check this after the constructor call to see if the thin plate spline
    // coefficients were successfully computed.  If so, then calls to
    // operator()(Real,Real) will work properly.
    bool IsInitialized () const;

    // Evaluate the thin plate spline interpolator.  If IsInitialized()
    // returns 'false', this operator will always return MAX_REAL.
    Real operator() (Real x, Real y);

private:
    static Real Kernel (Real t);

    bool mInitialized;
    int mQuantity;

    // Input data mapped to unit cube.
    Real* mX;
    Real* mY;

    // Thin plate spline coefficients.
    Real* mA;
    Real mB[3];

    // Extent of input data.
    Real mXMin, mXMax, mXInvRange;
    Real mYMin, mYMax, mYInvRange;
};

typedef IntpThinPlateSpline2<float> IntpThinPlateSpline2f;
typedef IntpThinPlateSpline2<double> IntpThinPlateSpline2d;

}

#endif
