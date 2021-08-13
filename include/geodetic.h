#ifndef GEODETIC_H
#define GEODETIC_H

#include <QJsonObject>

#include "jord_traits.h"

namespace jord::domain
{
class Geodetic
{
public:
    Geodetic(double latitude, double longitude, float altitude,
             const QString& datum = datums::wgs84);
    Geodetic(const QJsonObject& json);
    Geodetic();

    QJsonObject toJson() const;
    bool isValidPosition() const;
    bool isValidAltitude() const;
    bool isValid() const;

    const double latitude;
    const double longitude;
    const float altitude;
    const QString datum;
};
} // namespace jord::domain

#endif // GEODETIC_H
