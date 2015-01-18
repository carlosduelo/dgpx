#include <DataContainer.h>

namespace dgpx
{

void DataContainer::insert( const TrackPoint& point)
{
    _data.push_back( point );
}

}

