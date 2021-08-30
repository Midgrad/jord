#ifndef JORD_TRAITS_H
#define JORD_TRAITS_H

namespace md::domain
{
// Datums provided in proj4 format
namespace datums
{
constexpr char wgs84[] = "WGS84";
} // namespace datums

constexpr char latitude[] = "latitude";
constexpr char longitude[] = "longitude";
constexpr char altitude[] = "altitude";
constexpr char datum[] = "datum";
} // namespace jord::domain

#endif // JORD_TRAITS_H
