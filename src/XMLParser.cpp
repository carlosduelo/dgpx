#include <XMLParser.h>

#include <tinyxml.h>

#include <iostream>

namespace dgpx
{

void XMLParser::parse( DataContainer& data )
{
    TiXmlDocument doc( _fileName.c_str() );
    if( !doc.LoadFile() )
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return;
    }

    const TiXmlElement* root = doc.FirstChildElement( "gpx" );
    if( !root )
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return;
    }

    const TiXmlElement* track = root->FirstChildElement("trk");
    if( !track)
    {
        std::cerr << "Error parsing gpx file" << std::endl;
        return;
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
        return;
    }

    TiXmlElement* point = (TiXmlElement*) trackPoints->FirstChildElement("trkpt");
    unsigned npoints = 0;
    while( point )
    {
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

        if( sLat && sLong && sElem && sTime )
        {
            npoints++;
            float lat = 0.0;
            float lon = 0.0;
            float ele = 0.0;
            std::chrono::system_clock::time_point time;
            try
            {
                 lat = ::atof( sLat );
                 lon = ::atof( sLong );
                 ele = ::atof( sElem );
                 std::tm tm;
                 strptime(sTime, "%Y-%m-%dT%H:%M:%SZ", &tm);
                 time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
                 data.insert( TrackPoint( lat, lon, ele, time ) );
            }
            catch(...)
            {
                std::cerr << "Error parsing point" << std::endl;
            }
        }

        point = point->NextSiblingElement("trkpt");
    }

    std::cout << "Number of points " << npoints << std::endl;
}

}
