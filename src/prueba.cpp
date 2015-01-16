#include <tinyxml.h>
#include <iostream>

int main(int argc, char ** argv)
{
    if( argc != 2 )
    {
        std::cerr << "Usage: ./dgpx <file.gpx>" << std::endl;
        return 0;
    }

    TiXmlDocument doc( argv[1] );
    if( !doc.LoadFile() )
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return 0;
    }

    const TiXmlElement* root = doc.RootElement();

    if( !root )
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return 0;
    }


}
