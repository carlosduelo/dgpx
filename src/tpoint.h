#ifndef _H_TRACK_POINT_
#define _H_TRACK_POINT_

#include <chrono>

namespace dgpx
{

class TrackPoint
{
public:
    TrackPoint( const float lat, const float lon,
                const float ele,
                const std::chrono::system_clock::time_point time )
                        : _lat( lat )
                        , _lon( lon )
                        , _ele( ele )
                        , _time( time )
    {}

private:
    const float _lat;
    const float _lon;
    const float _ele;
    const std::chrono::system_clock::time_point _time;
};

}

#endif // _H_TRACK_POINT_
