#include <DataContainer.h>

#include <iostream>

namespace dgpx
{

void DataContainer::_insert( const TrackPoint& point)
{
    if( point._ele > _maxEle )
        _maxEle = point._ele;
    if( point._ele < _minEle )
        _minEle = point._ele;

    if( _data.size() > 0 )
    {
        if( point._ele > _data.back()._ele )
            _upHillEle += point._ele - _data.back()._ele; 
        if( point._ele < _data.back()._ele )
            _downHillEle += _data.back()._ele - point._ele; 
    }

    _data.push_back( point );
}

void DataContainer::printPoints()
{
    for( unsigned i = 0; i < _data.size(); i++ )
        std::cout << _data[i] << std::endl;
}

void DataContainer::printStats()
{
    std::cout << "Stats:" << std::endl;
    std::cout << "\t " << _maxEle << std::endl;
    std::cout << "\t " << _minEle << std::endl;
    std::cout << "\t " << _upHillEle << std::endl;
    std::cout << "\t " << _downHillEle << std::endl;
}

}

