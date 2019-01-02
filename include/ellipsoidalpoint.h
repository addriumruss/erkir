/**********************************************************************************
*  MIT License                                                                    *
*                                                                                 *
*  Copyright (c) 2018-2019 Vahan Aghajanyan <vahancho@gmail.com>                  *
*                                                                                 *
*  Latitude/longitude spherical geodesy tools         (c) Chris Veness 2005-2016  *
*  www.movable-type.co.uk/scripts/latlong-convert-coords.html                     *
*  www.movable-type.co.uk/scripts/geodesy/docs/module-latlon-ellipsoidal.html     *
*                                                                                 *
*  Permission is hereby granted, free of charge, to any person obtaining a copy   *
*  of this software and associated documentation files (the "Software"), to deal  *
*  in the Software without restriction, including without limitation the rights   *
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
*  copies of the Software, and to permit persons to whom the Software is          *
*  furnished to do so, subject to the following conditions:                       *
*                                                                                 *
*  The above copyright notice and this permission notice shall be included in all *
*  copies or substantial portions of the Software.                                *
*                                                                                 *
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
*  SOFTWARE.                                                                      *
***********************************************************************************/

#ifndef ELLIPSOIDAL_POINT_H
#define ELLIPSOIDAL_POINT_H

#include "point.h"

namespace erkir
{

namespace ellipsoidal
{

//! Implements geodetic point based on ellipsoidal earth model.
/*!
  Includes ellipsoid parameters and datums for different coordinate systems, and methods for
  converting between them and to Cartesian coordinates.
*/
class Point : public erkir::Point
{
public:
  /// The datums.
  /*!
    Note that precision of various datums will vary, and WGS-84 (original) is not defined to be
    accurate to better than �1 metre. No transformation should be assumed to be accurate to better
    than a meter; for many datums somewhat less.
  */
  enum class Datum
  {
    ED50,
    Irl1975,
    NAD27,
    NAD83,
    NTF,
    OSGB36,
    Potsdam,
    TokyoJapan,
    WGS72,
    WGS84
  };

  //! Constructs a point with the given \p latitude and \p longitude and \p datum.
  Point(const Latitude &latitude, const Longitude &longitude, Datum datum = Datum::WGS84);

  /// Return the datum.
  Datum datum() const;

private:
  Datum m_datum;
};

} // ellipsoidal

} // erkir

#endif // ELLIPSOIDAL_POINT_H

