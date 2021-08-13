#include "geodetic.h"

#include <cmath>
#include <limits>

using namespace jord::domain;

Geodetic::Geodetic(double latitude, double longitude, float altitude, const QString& datum) :
    latitude(latitude),
    longitude(longitude),
    altitude(altitude),
    datum(datum)
{
}

Geodetic::Geodetic(const QJsonObject& json) :
    Geodetic(json.value(::latitude).toDouble(std::numeric_limits<double>::quiet_NaN()),
             json.value(::longitude).toDouble(std::numeric_limits<double>::quiet_NaN()),
             json.value(::altitude).toDouble(std::numeric_limits<float>::quiet_NaN()),
             json.value(::datum).toString(datums::wgs84))
{
}

Geodetic::Geodetic() :
    Geodetic(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(),
             std::numeric_limits<float>::quiet_NaN())

{
}

QJsonObject Geodetic::toJson() const
{
    return QJsonObject{ { ::latitude, latitude },
                        { ::longitude, longitude },
                        { ::altitude, altitude },
                        { ::datum, datum } };
}

bool Geodetic::isValidPosition() const
{
    return !std::isnan(latitude) && !std::isnan(longitude);
}

bool Geodetic::isValidAltitude() const
{
    return !std::isnan(altitude);
}

bool Geodetic::isValid() const
{
    return this->isValidPosition() && this->isValidAltitude();
}
