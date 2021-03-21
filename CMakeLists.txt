cmake_minimum_required ( VERSION 3.19.6 )

project (SiriusStudyProject CXX)

set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SiriusStudyProject_BINARY_DIR}/out )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SiriusStudyProject_BINARY_DIR}/out )

set (CMAKE_CXX_STANDARD 17 )
set (CMAKE_CXX_STANDARD_REQUIRED ON )
set (CMAKE_CXX_EXTENSIONS OFF )

add_subdirectory (src)

if (WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)
endif()

if (WIN32)
    write_file(${CMAKE_HOME_DIRECTORY}/openstudio.cmd "set PATH=%PATH%;${CMAKE_HOME_DIRECTORY}\\distr\\nsis-3.06.1")
    string ( REGEX REPLACE "/" "\\\\" path_sln "${SiriusStudyProject_BINARY_DIR}/${CMAKE_PROJECT_NAME}.sln" )
    write_file(${CMAKE_HOME_DIRECTORY}/openstudio.cmd "start \"\" /WAIT \"${path_sln}\" /useenv" APPEND)
endif()

set ( PACKAGE_GENERATORS_DEFAULT "NSIS;ZIP" )
set ( CPACK_GENERATOR ${PACKAGE_GENERATORS_DEFAULT} )
set ( CPACK_PACKAGE_VERSION "1.0.0")
set ( CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF )
set ( CPACK_ARCHIVE_COMPONENT_INSTALL OFF )
set ( CPACK_MONOLITHIC_INSTALL ON )

set ( CPACK_NSIS_MODIFY_PATH ON )

set ( CPACK_NSIS_PACKAGE_NAME "Калькулятор")
set ( CPACK_NSIS_DISPLAY_NAME "Калькулятор")
set ( CPACK_PACKAGE_DESCRIPTION_SUMMARY "Калькулятор" )

set ( CPACK_PACKAGE_VENDOR "ГК Росатом" )
set ( CPACK_NSIS_CONTACT "staff@rosatom.ru")

set ( CPACK_PACKAGE_EXECUTABLES "app" "Калькулятор")
set ( CPACK_CREATE_DESKTOP_LINKS app)
set ( CPACK_NSIS_INSTALLED_ICON_NAME app.exe)
set ( CPACK_NSIS_URL_INFO_ABOUT "rosatom.ru")
set ( CPACK_NSIS_HELP_LINK "rosatom.ru")

set ( CPACK_NSIS_INSTALL_ROOT "$LOCALAPPDATA")
set ( CPACK_PACKAGE_INSTALL_DIRECTORY "Programs\\\\ROSATOM\\\\CALCULATOR" )
set ( CPACK_NSIS_EXECUTABLES_DIRECTORY ".")

set ( CPACK_NSIS_MUI_FINISHPAGE_RUN "app.exe" )

set ( CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON )
string ( REGEX REPLACE "/" "\\\\\\\\" CPACK_NSIS_MUI_ICON "${CMAKE_HOME_DIRECTORY}/src/app/rosatom.ico" )

set ( CPACK_PACKAGE_FILE_NAME "Calculator-x86-64-${CPACK_PACKAGE_VERSION}.1")

string ( APPEND CPACK_NSIS_DEFINES "  BrandingText \\\"${CPACK_NSIS_DISPLAY_NAME}, ${CPACK_PACKAGE_VENDOR}, 2021\\\"\n" )
string ( APPEND CPACK_NSIS_DEFINES "  RequestExecutionLevel user" )

include(CPack)
