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

    double latitude() const;
    double longitude() const;
    float altitude() const;
    QString datum() const;

    QJsonObject toJson() const;
    bool isValidPosition() const;
    bool isValidAltitude() const;
    bool isValid() const;

    Geodetic& operator=(const Geodetic& other);
    friend bool operator==(const Geodetic& first, const Geodetic& second);

private:
    double m_latitude;
    double m_longitude;
    float m_altitude;
    QString m_datum;
};

bool operator==(const Geodetic& first, const Geodetic& second);
} // namespace jord::domain

#endif // GEODETIC_H
