#include <cmath>
#include <limits>

#include <gtest/gtest.h>

#include "geodetic.h"

using namespace md::domain;

struct TestArgs
{
    double latitude;
    double longitude;
    double altitude;
    QString datum;
};

class GeodeticTest : public ::testing::TestWithParam<TestArgs>
{
public:
    GeodeticTest()
    {
    }
};

INSTANTIATE_TEST_SUITE_P(
    instantiation, GeodeticTest,
    ::testing::Values(TestArgs({ 44.5432, 31.2344, 4584.56, datums::wgs84 }),
                      TestArgs({ 0, 0, 0, "" }),
                      TestArgs({ std::numeric_limits<double>::quiet_NaN(),
                                 std::numeric_limits<double>::quiet_NaN(), 0, "" }),
                      TestArgs({ std::numeric_limits<double>::quiet_NaN(),
                                 std::numeric_limits<double>::quiet_NaN(),
                                 std::numeric_limits<double>::quiet_NaN(), "" })));

TEST_P(GeodeticTest, testToJson)
{
    TestArgs args = GetParam();

    Geodetic geodetic(args.latitude, args.longitude, args.altitude, args.datum);
    QJsonObject json = geodetic.toJson();

    if (geodetic.isValidPosition())
    {
        EXPECT_DOUBLE_EQ(json.value(::latitude).toDouble(), args.latitude);
        EXPECT_DOUBLE_EQ(json.value(::longitude).toDouble(), args.longitude);
    }
    else
    {
        EXPECT_TRUE(std::isnan(json.value(::latitude).toDouble()));
        EXPECT_TRUE(std::isnan(json.value(::longitude).toDouble()));
    }

    if (geodetic.isValidAltitude())
    {
        EXPECT_FLOAT_EQ(json.value(::altitude).toDouble(), args.altitude);
    }
    else
    {
        EXPECT_TRUE(std::isnan(json.value(::altitude).toDouble()));
    }

    EXPECT_EQ(json.value(::datum).toString(), args.datum);
}

TEST_P(GeodeticTest, testFromJson)
{
    TestArgs args = GetParam();

    QJsonObject json({ { ::latitude, args.latitude },
                       { ::longitude, args.longitude },
                       { ::altitude, args.altitude },
                       { ::datum, args.datum } });
    Geodetic geodetic(json);

    if (geodetic.isValidPosition())
    {
        EXPECT_DOUBLE_EQ(geodetic.latitude(), args.latitude);
        EXPECT_DOUBLE_EQ(geodetic.longitude(), args.longitude);
    }

    if (geodetic.isValidAltitude())
    {
        EXPECT_FLOAT_EQ(geodetic.altitude(), args.altitude);
    }

    EXPECT_EQ(geodetic.datum(), args.datum);
}

TEST_P(GeodeticTest, testEquality)
{
    TestArgs args = GetParam();

    Geodetic first(args.latitude, args.longitude, args.altitude, args.datum);
    Geodetic second(first.toJson());

    if (first.isValidPosition())
    {
        EXPECT_DOUBLE_EQ(first.latitude(), second.latitude());
        EXPECT_DOUBLE_EQ(first.longitude(), second.longitude());
    }
    else
    {
        EXPECT_TRUE(!second.isValidPosition());
    }

    if (first.isValidAltitude())
    {
        EXPECT_FLOAT_EQ(first.altitude(), second.altitude());
    }
    else
    {
        EXPECT_TRUE(!second.isValidAltitude());
    }

    if (first.isValid() && second.isValid())
    {
        EXPECT_TRUE(first == second);
    }

    EXPECT_EQ(first.datum(), second.datum());
}
