#ifndef _H_DATA_ELE_INTERPOLATOR_
#define _H_DATA_ELE_INTERPOLATOR_

#include <data/DataContainer.h>

namespace dgpx
{

class EleInterpolator
{
public:
    virtual ~EleInterpolartor() {}

    bool init( DataContainer& data ) = 0;

    float get( float x ) = 0;
};

}

#endif // _H_DATA_ELE_INTERPOLATOR_
