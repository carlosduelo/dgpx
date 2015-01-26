#ifndef _H_DATA_ELE_FACTORY_INTERPOLATOR_
#define _H_DATA_ELE_FACTORY_INTERPOLATOR_

#include <data/EleInterpolators/Bilinear.h>

namespace dgpx
{

EleInterpolator* CreateEleInterpolator( const uint32_t typeInter,
                                        const DataContainer& data )
{
    switch( typeInter )
    {
        case ELE_INTERPOLATOR_BILINEAR:
            return new Simple(); 
        default:
            return 0;
    }
}

}
#endif // _H_DATA_ELE_FACTORY_INTERPOLATOR_
