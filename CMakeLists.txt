cmake_minimum_required(VERSION 3.5.0)

project(Triangle
   # triangle 1.6 was the last "official" version; i.e. 1.7 should be good to go:
   VERSION 1.7.0
   )

option(TRIANGLE_ENABLE_ACUTE "Enable the aCute extension." ON)

option(BUILD_TESTING "Enable unit tests." ON)
if(BUILD_TESTING)
   enable_testing()
endif()

set(TRIANGLE_SOURCE_ROOT    ${CMAKE_CURRENT_SOURCE_DIR})
set(TRIANGLE_BINARY_ROOT    ${CMAKE_CURRENT_BINARY_DIR})
set(TRIANGLE_SOURCE_INCLUDE ${TRIANGLE_SOURCE_ROOT}/include/)
set(TRIANGLE_BINARY_INCLUDE ${TRIANGLE_BINARY_ROOT}/include/)
file(MAKE_DIRECTORY ${TRIANGLE_BINARY_INCLUDE}/Triangle)

include_directories(${TRIANGLE_BINARY_INCLUDE})
include_directories(${TRIANGLE_SOURCE_INCLUDE})

add_subdirectory(src)
add_subdirectory(examples)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
   "${CMAKE_CURRENT_BINARY_DIR}/Triangle/TriangleConfigVersion.cmake"
   VERSION ${Triangle_VERSION}
   COMPATIBILITY AnyNewerVersion
   )

export(EXPORT TriangleTargets
   FILE "${CMAKE_CURRENT_BINARY_DIR}/Triangle/TriangleTargets.cmake"
   NAMESPACE Triangle::
   )
configure_file(cmake/TriangleConfig.cmake
   "${CMAKE_CURRENT_BINARY_DIR}/Triangle/TriangleConfig.cmake"
   COPYONLY
   )
install(EXPORT TriangleTargets
   FILE TriangleTargets.cmake
   NAMESPACE Triangle::
   DESTINATION lib/cmake/Triangle
   )
install(
   FILES
   cmake/TriangleConfig.cmake
   "${CMAKE_CURRENT_BINARY_DIR}/Triangle/TriangleConfigVersion.cmake"
   DESTINATION lib/cmake/Triangle
   COMPONENT Devel
   )
