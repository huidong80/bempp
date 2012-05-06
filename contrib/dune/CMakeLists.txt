set(DUNE_GRID ${CMAKE_CURRENT_SOURCE_DIR}/dune-grid)
set(DUNE_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/dune-common)
set(DUNE_LOCALFUNCTIONS ${CMAKE_CURRENT_SOURCE_DIR}/dune-localfunctions)
set(DUNE_FOAMGRID ${CMAKE_CURRENT_SOURCE_DIR}/dune-foamgrid)

include_directories(
  ${DUNE_COMMON}
  ${DUNE_GRID}
  ${DUNE_FOAMGRID}
)

add_subdirectory(${DUNE_COMMON})
add_subdirectory(${DUNE_GRID})
add_subdirectory(${DUNE_LOCALFUNCTIONS})
add_subdirectory(${DUNE_FOAMGRID})


