set (targetname calc)

set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(${targetname} SHARED calc.h calc.cpp)

install (TARGETS ${targetname} RUNTIME DESTINATION . )
