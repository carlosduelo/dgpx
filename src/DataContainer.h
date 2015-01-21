#ifndef _H_DATA_CONTAINER_
#define _H_DATA_CONTAINER_

#include <tpoint.h>

#include <limits>
#include <vector>

namespace dgpx
{

class XMLParser;

class DataContainer
{
friend class XMLParser;

public:
    DataContainer()
        : _maxEle( std::numeric_limits<float>::lowest() )
        , _minEle( std::numeric_limits<float>::max() )
        , _upHillEle( 0.0f )
        , _downHillEle( 0.0f )
    {}

    void compute();

    void printPoints();
    void printStats();

private:
    void _insert ( const TrackPoint& point); 

    std::vector< TrackPoint > _data;
    unsigned _maxEleIndex;
    unsigned _minEleIndex;
    float _maxEle;
    float _minEle;

    float _maxEleDiff;
    float _avgEleDiff;

    float _upHillEle;
    float _downHillEle;
};

}

#endif // _H_DATA_CONTAINER_
