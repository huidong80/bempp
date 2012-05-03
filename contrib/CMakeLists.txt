project (contrib)
cmake_minimum_required (VERSION 2.8)

# Set Cache Variables

#IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#  SET(CMAKE_INSTALL_PREFIX
#    "${CMAKE_SOURCE_DIR}" CACHE PATH "Install prefix" FORCE
#    )
#ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Boost
set(BOOST_LIBRARY_DIR "" CACHE PATH "Directory containing Boost Libraries")
set(BOOST_INCLUDE_DIR "" CACHE PATH "Directory containing Boost include files")
#include_directories(${BOOST_INCLUDE_DIR})

# BLAS
set(BLAS_LIBRARIES "" CACHE STRING "Semicolon-separated list of full paths to BLAS libs")

# LAPACK
set(LAPACK_LIBRARIES "" CACHE STRING "Semicolon-separated list of full paths to LAPACK libs")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/trilinos.cmake)
