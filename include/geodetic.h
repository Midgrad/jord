#ifndef GEODETIC_H
#define GEODETIC_H

#include <QVariantMap>

#include "jord_traits.h"

namespace md::domain
{
class Geodetic
{
public:
    Geodetic(double latitude, double longitude, float altitude,
             const QString& datum = datums::wgs84);
    Geodetic(const QVariantMap& map);
    Geodetic();

    double latitude() const;
    double longitude() const;
    float altitude() const;
    QString datum() const;

    QVariantMap toVariantMap() const;
    bool isValidPosition() const;
    bool isValidAltitude() const;
    bool isValid() const;

    Geodetic offsetted(double dLatitude, double dLongitude, float dAltitude) const;

    Geodetic& operator=(const Geodetic& other);
    friend bool operator==(const Geodetic& first, const Geodetic& second);

private:
    double m_latitude;
    double m_longitude;
    float m_altitude;
    QString m_datum;
};

bool operator==(const Geodetic& first, const Geodetic& second);
} // namespace md::domain

#endif // GEODETIC_H
