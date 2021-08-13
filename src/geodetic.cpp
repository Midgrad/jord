#include "geodetic.h"

using namespace jord::domain;

Geodetic::Geodetic(double latitude, double longitude, float altitude, std::string_view datum) :
    latitude(latitude),
    longitude(longitude),
    altitude(altitude),
    datum(datum)
{
}
