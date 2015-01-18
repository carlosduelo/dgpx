#ifndef _H_DATA_CONTAINER_
#define _H_DATA_CONTAINER_

#include <tpoint.h>

#include <vector>

namespace dgpx
{

class XMLParser;

class DataContainer
{
friend class XMLParser;

private:
    void insert ( const TrackPoint& point); 

    std::vector< TrackPoint > _data;
};

}

#endif // _H_DATA_CONTAINER_
