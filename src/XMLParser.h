#ifndef _H_XML_PARSER_
#define _H_XML_PARSER_

#include <DataContainer.h>

#include <string>

namespace dgpx
{

class XMLParser
{
public:
    XMLParser( const char* fileName )
        : _fileName( fileName )
    {}

    void parse( DataContainer& data );

private:
    const std::string _fileName;
};

}

#endif //_H_XML_PARSER_
