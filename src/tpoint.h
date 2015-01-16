#ifndef _H_TRACK_POINT_
#define _H_TRACK_POINT_

namespace dgpx
{

class TrackPoint
{
public:
    TrackPoint( const float lat, const float lon,
                const float ele)
                        : _lat( lat )
                        , _lon( lon )
                        , _ele( ele )
    {}

private:
    const float _lat;
    const float _lon;
    const float _ele;
    // time
};

}

#endif _H_TRACK_POINT_
