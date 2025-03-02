get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(SRCS 
    "coreHTTP/source/core_http_client.c"
    "coreHTTP/source/dependency/3rdparty/http_parser/http_parser.c"
    "src/http_client_wrapper.c"
    "src/http_download.c"
)

set(INCS 
    "include"
    "coreHTTP"
    "coreHTTP/source/include"
    "coreHTTP/source/dependency/3rdparty/http_parser"
)

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}
)

target_link_libraries(${COMPONENT_NAME} PUBLIC mqtt_client tal_system)

