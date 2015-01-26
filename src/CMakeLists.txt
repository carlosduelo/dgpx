
# Compiling the dgpx library
add_subdirectory(lib)

# Adding includes, temporal, library install phase not implemented yet
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Compiling dgpx
set(LIBRARIES
        dgpxlib
   )

add_executable(dgpx main.cpp)
target_link_libraries(dgpx ${LIBRARIES})
