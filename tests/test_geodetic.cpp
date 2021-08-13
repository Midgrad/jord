#include <gtest/gtest.h>

#include "geodetic.h"

using namespace jord::domain;

class GeodeticTest : public testing::Test
{
public:
    GeodeticTest()
    {
    }
};

TEST_F(GeodeticTest, testToJson)
{
    double latitude = 44.5432;
    double longitude = 31.2344;
    double altitude = 31.2344;
    QString datum = datums::wgs84;

    Geodetic geodetic(latitude, longitude, altitude, datum);
    QJsonObject json = geodetic.toJson();

    EXPECT_DOUBLE_EQ(json.value(::latitude).toDouble(), latitude);
    EXPECT_DOUBLE_EQ(json.value(::longitude).toDouble(), longitude);
    EXPECT_FLOAT_EQ(json.value(::altitude).toDouble(), altitude);
    EXPECT_EQ(json.value(::datum).toString(), datum);
}

TEST_F(GeodeticTest, testFromJson)
{
    double latitude = 44.5432;
    double longitude = 31.2344;
    double altitude = 31.2344;
    QString datum = datums::wgs84;

    QJsonObject json({ { ::latitude, latitude },
                       { ::longitude, longitude },
                       { ::altitude, altitude },
                       { ::datum, datum } });
    Geodetic geodetic(json);

    EXPECT_DOUBLE_EQ(geodetic.latitude, latitude);
    EXPECT_DOUBLE_EQ(geodetic.longitude, longitude);
    EXPECT_FLOAT_EQ(geodetic.altitude, altitude);
    EXPECT_EQ(geodetic.datum, datum);
}

TEST_F(GeodeticTest, testEquality)
{
    double latitude = 44.5432;
    double longitude = 31.2344;
    double altitude = 31.2344;
    QString datum = datums::wgs84;

    Geodetic first(latitude, longitude, altitude, datum);
    Geodetic second(first.toJson());

    EXPECT_DOUBLE_EQ(first.latitude, second.latitude);
    EXPECT_DOUBLE_EQ(first.longitude, second.longitude);
    EXPECT_FLOAT_EQ(first.altitude, second.altitude);
    EXPECT_EQ(first.datum, second.datum);
}
