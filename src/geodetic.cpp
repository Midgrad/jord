#include "geodetic.h"

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
    latitude(json.value(::latitude).toDouble(std::numeric_limits<double>::quiet_NaN())),
    longitude(json.value(::longitude).toDouble(std::numeric_limits<double>::quiet_NaN())),
    altitude(json.value(::altitude).toDouble(std::numeric_limits<double>::quiet_NaN())),
    datum(json.value(::datum).toString(datums::wgs84))
{
}

QJsonObject Geodetic::toJson() const
{
    return QJsonObject{ { ::latitude, latitude },
                        { ::longitude, longitude },
                        { ::altitude, altitude },
                        { ::datum, datum } };
}
