set (targetname app)

add_executable (${targetname} main.cpp resourse.rc)

target_include_directories(${targetname} PRIVATE ${CMAKE_HOME_DIRECTORY}/src/calc)

target_link_libraries (${targetname} calc)

install (TARGETS ${targetname} DESTINATION .)
