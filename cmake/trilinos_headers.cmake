# Add the headers for the required trilinos libraries

# amesos
file(GLOB AMESOS_HEADERS ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/amesos/src/*.h)
include_directories(${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/amesos/src)

# epetra
file(GLOB EPETRA_HEADERS ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/epetra/src/*.h)
include_directories(${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/epetra/src)

# thyra
file(GLOB_RECURSE THYRACORE_HEADERS ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/*.h)
include_directories(  ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src
                      ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src/interfaces/operator_solve/extended
                      ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src/interfaces/operator_solve/fundamental
                      ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src/support/operator_solve/client_support
                      ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src/support/operator_vector/adapter_support
                      ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/thyra/core/src/support/operator_vector/client_support)

# stratimikos
file(GLOB_RECURSE STRATIMIKOS_HEADRS ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/stratimikos/*.h)
include_directories (   ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/stratimikos/src
                        ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/stratimikos/adapters/belos/src)

# teuchos
file(GLOB TEUCHOS_HEADERS ${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/teuchos/src/*.h)
include_directories(${CMAKE_SOURCE_DIR}/contrib/trilinos/packages/teuchos/src)

# Rtop
# No headers needed at the moment (support library for Teuchos)
