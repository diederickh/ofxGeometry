// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef WM5WINDOWAPPLICATION2_H
#define WM5WINDOWAPPLICATION2_H

#include "Wm5WindowApplication.h"

namespace Wm5
{

class WindowApplication2 : public WindowApplication
{
public:
    // Construction and destruction.
    WindowApplication2 (const char* windowTitle, int xPosition, int yPosition,
        int width, int height, const Float4& clearColor);

    virtual ~WindowApplication2 ();

    // Event callbacks.
    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnResize (int width, int height);
    virtual void OnDisplay ();

    // Allows you to do additional drawing after the screen polygon is drawn.
    virtual void ScreenOverlay ();

    void ClearScreen ();

    class ColorRGB
    {
    public:
        inline ColorRGB (unsigned char red = 0, unsigned char green = 0,
            unsigned char blue = 0)
        {
            r = red;
            g = green;
            b = blue;
        }

        inline bool operator== (ColorRGB color) const
        {
            return b == color.b && g == color.g && r == color.r;
        }

        inline bool operator!= (ColorRGB color) const
        {
            return b != color.b || g != color.g || r != color.r;
        }

        unsigned char b, g, r;
    };

    void SetPixel (int x, int y, ColorRGB color);
    void SetThickPixel (int x, int y, int thick, ColorRGB color);
    ColorRGB GetPixel (int x, int y);
    void DrawLine (int x0, int y0, int x1, int y1, ColorRGB color);
    void DrawRectangle (int xMin, int yMin, int xMax, int yMax,
        ColorRGB color, bool solid = false);
    void DrawCircle (int xCenter, int yCenter, int radius, ColorRGB color,
        bool solid = false);
    void Fill (int x, int y, ColorRGB foreColor, ColorRGB backColor);

    bool& ClampToWindow ();

    // For right-handed drawing.  You still draw to the left-handed screen,
    // but immediately before drawing, the screen is copied into another
    // buffer with the rows reversed.  You need only call DoFlip(true) once
    // for an application.  The default is 'false'.
    void DoFlip (bool doFlip);


protected:
    inline int Index (int x, int y)
    {
        // Left-handed screen coordinates.
        return x + mWidth*y;
    }

    int mScreenWidth, mScreenHeight;
    ColorRGB* mScreen;
    bool mClampToWindow;

    // For right-handed drawing.  The array mScreen is copied to
    // mFlipScreen so that the rows are reversed.
    ColorRGB* mFlipScreen;
};

}

#endif
