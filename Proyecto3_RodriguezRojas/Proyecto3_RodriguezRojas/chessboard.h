#ifndef __DDC_IMAGER_CHESSBOARD_H
#define __DDC_IMAGER_CHESSBOARD_H

#include "imager.h"

namespace Imager
{
    class ChessBoard: public Cuboid
    {
    public:
        ChessBoard(
            double _innerSize, 
            double _xBorderSize, 
            double _yBorderSize,
            double _thickness,
            const Color& _lightSquareColor,
            const Color& _darkSquareColor,
            const Color& _borderColor); // CTexture &t);

    protected:
        // This method override provides the variety of colors
        // for the light squares, dark squares, and border.
        virtual Optics ObjectSpace_SurfaceOptics(
            const Vector& surfacePoint,
            const void *context) const;

        int SquareCoordinate(double xy) const;

    private:
        double innerSize;
        double xBorderSize;
        double yBorderSize;
        double thickness;
        Color  lightSquareColor;
        Color  darkSquareColor;
        Color  borderColor;// CTexture &t;
    };
}

#endif // __DDC_IMAGER_CHESSBOARD_H
