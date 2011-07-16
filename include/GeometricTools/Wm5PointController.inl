// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

//----------------------------------------------------------------------------
inline int PointController::GetNumPoints () const
{
    return mNumPoints;
}
//----------------------------------------------------------------------------
inline float* PointController::GetPointLinearSpeed () const
{
    return mPointLinearSpeed;
}
//----------------------------------------------------------------------------
inline float* PointController::GetPointAngularSpeed () const
{
    return mPointAngularSpeed;
}
//----------------------------------------------------------------------------
inline AVector* PointController::GetPointLinearAxis () const
{
    return mPointLinearAxis;
}
//----------------------------------------------------------------------------
inline AVector* PointController::GetPointAngularAxis () const
{
    return mPointAngularAxis;
}
//----------------------------------------------------------------------------