
set(SOURCES tinystr.cpp
            tinyxml.cpp
            tinyxmlerror.cpp
            tinyxmlparser.cpp
            prueba.cpp
   )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(prueba ${SOURCES}) 
