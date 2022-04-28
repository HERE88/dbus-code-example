cmake_minimum_required (VERSION 2.8.1)

project(gdbus-demo)

set(CMAKE_VERBOSE_MAKEFILE off)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0")

#######################################################################################
# this var must be define by designer,a lot of cmakeVar will be define by this var    #
#######################################################################################
#set(APP_NAME "gdbus-demo1")

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(gdbus)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(example)

##################### config CPack #############################################
set(CPACK_GENERATOR "TGZ")

set(CPACK_RPM_PACKAGE_DESCRIPTION_SUMMARY "install gdbus-demo")
set(CPACK_RPM_PACKAGE_VENDOR "vesoft")
set(CPACK_RPM_PACKAGE_NAME "gdbus-demo")
set(CPACK_RPM_PACKAGE_VERSION_MAJOR "0")
set(CPACK_RPM_PACKAGE_VERSION_MINOR "1")
set(CPACK_RPM_PACKAGE_VERSION_PATCH "0")
#set(CPACK_SET_DESTDIR true)
#set(CPACK_INSTALL_PREFIX "/usr")

include(CPack)

install(FILES   includes/libClient.h
        DESTINATION usr/include/gdbus-demo/
)