
set(SOURCES xmlReader/tinystr.cpp
            xmlReader/tinyxml.cpp
            xmlReader/tinyxmlerror.cpp
            xmlReader/tinyxmlparser.cpp
            xmlReader/XMLParser.cpp
            data/tpoint.cpp
            data/DataContainer.cpp
            main.cpp
   )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(dgpx ${SOURCES})
