#ifndef CARTESIAN_H
#define CARTESIAN_H

#include "jord_traits.h"

namespace jord::domain
{
class Cartesian
{
public:
    Cartesian(double x, double y, float z);

    const double x;
    const double y;
    const float z;
};
} // namespace jord::domain

#endif // CARTESIAN_H
