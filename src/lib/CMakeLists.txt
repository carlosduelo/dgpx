
set(SOURCES xmlReader/tinystr.cpp
            xmlReader/tinyxml.cpp
            xmlReader/tinyxmlerror.cpp
            xmlReader/tinyxmlparser.cpp
            xmlReader/XMLParser.cpp
            data/tpoint.cpp
            data/DataContainer.cpp
   )

#set(LIBRARIES
#   )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library( dgpxlib SHARED ${SOURCES} )
#target_link_libraries(dgpxlib ${LIBRARIES})
