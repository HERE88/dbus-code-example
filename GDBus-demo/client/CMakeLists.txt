# At least this cmake version is needed
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# The library has to be dynamically linked to the header
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/includes)
# INCLUDE_DIRECTORIES(/usr/include/glib-2.0)
# INCLUDE_DIRECTORIES(/usr/lib/glib-2.0/include)
# INCLUDE_DIRECTORIES(/usr/include/gio-unix-2.0)
# INCLUDE_DIRECTORIES(/usr/lib/x86_64-linux-gnu/glib-2.0/include/)

#changed by wanghaitao:
INCLUDE_DIRECTORIES(/usr/include/glib-2.0)
INCLUDE_DIRECTORIES(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
INCLUDE_DIRECTORIES(/usr/include/gio-unix-2.0)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/)
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/)

link_directories(${PROJECT_BINARY_DIR}/)

set(SRCclient libClient.c ${PROJECT_BINARY_DIR}/ExampleGdbusGenerated.c )
add_library(ExampleClientlib SHARED ${SRCclient})

#set(SRCclient libClient.c ${PROJECT_BINARY_DIR}/ExampleGdbusGenerated.c )
#add_library(ExampleClientlib STATIC ${SRCclient})

install(TARGETS ExampleClientlib
        LIBRARY DESTINATION usr/lib/
)