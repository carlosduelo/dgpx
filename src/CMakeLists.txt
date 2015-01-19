
set(SOURCES tinystr.cpp
            tinyxml.cpp
            tinyxmlerror.cpp
            tinyxmlparser.cpp
            XMLParser.cpp
            tpoint.cpp
            DataContainer.cpp
            main.cpp
   )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(dgpx ${SOURCES}) 
