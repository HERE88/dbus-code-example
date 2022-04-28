# At least this cmake version is needed
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# The library has to be dynamically linked to the header
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/includes)
# INCLUDE_DIRECTORIES(/usr/local/include/glib-2.0)
# INCLUDE_DIRECTORIES(/usr/local/lib/glib-2.0/include)
# INCLUDE_DIRECTORIES(/usr/local/include/gio-unix-2.0)
# INCLUDE_DIRECTORIES(/usr/local/lib/x86_64-linux-gnu/glib-2.0/include/)

#changed by wanghaitao:
INCLUDE_DIRECTORIES(/usr/include/glib-2.0/)
INCLUDE_DIRECTORIES(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
INCLUDE_DIRECTORIES(/usr/include/gio-unix-2.0)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/)
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/)

link_directories(${PROJECT_BINARY_DIR}/)

add_executable(SvrExample SvrExample.c libServer.c ${PROJECT_BINARY_DIR}/ExampleGdbusGenerated.c)
target_link_libraries(SvrExample pthread gio-2.0 gobject-2.0 gmodule-2.0 gthread-2.0 rt glib-2.0)

install(TARGETS SvrExample
	DESTINATION usr/bin/
)
