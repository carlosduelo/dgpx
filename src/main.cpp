#include <iostream>

#include <xmlReader/XMLParser.h>

#include <string>

int main(int argc, char ** argv)
{
    if( argc != 2 )
    {
        std::cerr << "Usage: ./dgpx <file.gpx>" << std::endl;
        return 0;
    }

    dgpx::XMLParser parser( argv[1] );

    dgpx::DataContainer data;
    parser.parse( data );
    data.compute();

    data.printStats();
}
