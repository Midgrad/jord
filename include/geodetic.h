#ifndef GEODETIC_H
#define GEODETIC_H

#include <string>

#include "jord_traits.h"

namespace jord::domain
{
class Geodetic
{
public:
    Geodetic(double latitude, double longitude, float altitude, std::string_view datum);

    const double latitude;
    const double longitude;
    const float altitude;
    const std::string datum;
};
} // namespace jord::domain

#endif // GEODETIC_H
