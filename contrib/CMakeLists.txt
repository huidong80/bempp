
# Set Cache Variables

set(TBB_INCLUDE_DIR "" CACHE STRING "Full path to Intel TBB include directory")
set(TBB_LIBRARY_DIR "" CACHE STRING "Full path to the directory with Intel TBB libraries")
set(LAPACK_LIBRARIES "" CACHE STRING "Lapack libs")
set(BLAS_LIBRARIES "" CACHE STRING "BLAS Libs")

# Threading building blocks
find_library(TBB_LIBRARY_DEBUG tbb_debug ${TBB_LIBRARY_DIR})
find_library(TBB_LIBRARY_RELEASE tbb ${TBB_LIBRARY_DIR})


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dune)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/trilinos.cmake)
