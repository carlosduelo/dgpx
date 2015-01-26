#ifndef _H_DATA_ELE_BILINEAR_INTERPOLATOR_
#define _H_DATA_ELE_BILINEAR_INTERPOLATOR_

#include <data/EleInterpolators/EleInterpolator.h>

namespace dgpx
{

class Simple 
{
public:
    bool init( const DataContainer& data );

    float get( const float x ) const;

private:

};

}

#endif // _H_DATA_ELE_BILINEAR_INTERPOLATOR_

