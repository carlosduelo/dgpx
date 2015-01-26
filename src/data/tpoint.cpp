#include <data/tpoint.h>

namespace dgpx
{

std::ostream& operator<<( std::ostream &out , const TrackPoint& point)
{
    std::time_t t = std::chrono::system_clock::to_time_t( point._time );
    return out << point._lat << " " << point._lon << " "
               << point._ele << " " << std::ctime(&t);
}

}
