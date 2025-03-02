get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(SRCS 
    "src/tal_kv.c"
    "src/kv_serialize.c"
)

set(LITTLEFS
    "littlefs/lfs_util.c"
    "littlefs/lfs.c"
)

list(APPEND SRCS ${LITTLEFS})

set(INCS 
    "include"
    "littlefs"
    "port"
)

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}

    PRIVATE
    "port"
)

target_compile_definitions(${COMPONENT_NAME} PUBLIC "-DLFS_CONFIG=lfs_config.h")

target_link_libraries(${COMPONENT_NAME} PUBLIC tal_system tal_security cJSON utilities)

