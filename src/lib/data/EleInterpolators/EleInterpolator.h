#ifndef _H_DATA_ELE_INTERPOLATOR_
#define _H_DATA_ELE_INTERPOLATOR_

#include <data/DataContainer.h>

namespace dgpx
{

class EleInterpolator
{
public:
    virtual ~EleInterpolartor() {}

    virtual bool init( const DataContainer& data ) = 0;

    virtual float get( float x ) const = 0;
};

}

#endif // _H_DATA_ELE_INTERPOLATOR_
