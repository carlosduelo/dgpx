#include <tinyxml.h>
#include <iostream>

#include <string>

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

    const TiXmlElement* root = doc.FirstChildElement( "gpx" );
    if( !root )
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return 0;
    }

    const TiXmlElement* track = root->FirstChildElement("trk");
    if( !track)
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return 0;
    }

    std::string name, cmt, desc;
    // Get Name
    const TiXmlElement* pname = track->FirstChildElement("name");
    if( !pname )
        name = "Not name";
    else
        name = pname->GetText();
    // Get Cmt
    const TiXmlElement* pcmt = track->FirstChildElement("cmt");
    if( !pcmt )
        cmt = "Not cmt";
    else
        cmt = pcmt->GetText();
    // Get Desc
    const TiXmlElement* pdesc = track->FirstChildElement("desc");
    if( !pdesc )
        desc = "Not Description";
    else
        desc = pdesc->GetText();

    const TiXmlElement* trackPoints = track->FirstChildElement("trkseg");
    if( !trackPoints)
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return 0;
    }

    TiXmlElement* point = (TiXmlElement*) trackPoints->FirstChildElement("trkpt");
    unsigned npoints = 0;
    while( point )
    {
        npoints++;
        // Get Lat
        const char* sLat  = point->Attribute("lat");
        // Get Lon
        const char* sLong = point->Attribute("lon");
        // Get Ele
        const TiXmlElement* pEle = point->FirstChildElement("ele");
        const char* sElem = pEle ? pEle->GetText() : "";
        // Get Time
        const TiXmlElement* pTime = point->FirstChildElement("time");
        const char* sTime = pTime ? pTime->GetText() : "";

        point = point->NextSiblingElement("trkpt");
    }

    std::cout << "Number of points " << npoints << std::endl;
}
