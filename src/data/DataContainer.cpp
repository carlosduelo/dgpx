#include <data/DataContainer.h>

#include <iostream>
#include <math.h>

namespace dgpx
{

void DataContainer::_insert( const TrackPoint& point)
{
    if( point._ele > _maxEle )
    {
        _maxEle = point._ele;
        _maxEleIndex = _data.size();
    }
    if( point._ele < _minEle )
    {
        _minEle = point._ele;
        _minEleIndex = _data.size();
    }

    if( _data.size() > 0 )
    {
    }

    _data.push_back( point );
}

void DataContainer::compute()
{

    for( unsigned i = 0; i < _data.size(); i++ )
    {
        if( i < _data.size() - 1 )
        {
            float eleDiff = fabsf( _data[ i + 1 ]._ele - _data[i]._ele );
            _avgEleDiff += eleDiff;
            _maxEleDiff = fmaxf( _maxEleDiff, eleDiff );

            if( _data[i]._ele > _data[i + 1 ]._ele )
                _upHillEle += _data[i]._ele - _data[ i + 1 ]._ele;
            if( _data[i]._ele < _data[ i + 1 ]._ele )
                _downHillEle += _data[i + 1]._ele - _data[ i ]._ele;
        }
    }

    _avgEleDiff /= (float) _data.size() - 1;

}

void DataContainer::printPoints()
{
    for( unsigned i = 0; i < _data.size(); i++ )
        std::cout << _data[i] << std::endl;
}

void DataContainer::printStats()
{
    std::cout << "Stats from GPX:" << std::endl;
    std::cout << "\t Max Elevation: " << _maxEle << std::endl;
    std::cout << "\t Min Elevation: " << _minEle << std::endl;
    std::cout << "\t Elevation gain upHill: " << _upHillEle << std::endl;
    std::cout << "\t Elevation gain downHill: " << _downHillEle << std::endl;
    std::cout << "\t Max elevation difference: " << _maxEleDiff << std::endl;
    std::cout << "\t Average elevation difference: " << _avgEleDiff << std::endl;
}

}

