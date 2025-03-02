get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

SET(MBEDTLS_PATH "mbedtls")

file(GLOB MBEDTLS_SRCS "${MBEDTLS_PATH}/library/*.c")

set(SRCS 
    "src/cipher_wrapper.c"
    "${MBEDTLS_SRCS}"
)

set(INCS 
    "port"
    "include"
    "${MBEDTLS_PATH}/include"
    "${MBEDTLS_PATH}/library"
)

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}
)

target_compile_definitions(${COMPONENT_NAME} PUBLIC "-DMBEDTLS_CONFIG_FILE=\"tuya_tls_config.h\"")

target_link_libraries(${COMPONENT_NAME} PUBLIC tal_system tal_kv)