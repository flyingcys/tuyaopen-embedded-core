get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

file(GLOB SRCS
    "coreMQTT/source/*.c"
)

file(GLOB TRANSPORT
    "transport/*.c"
)

list(APPEND SRCS
    "src/mqtt_client_wrapper.c"
    ${TRANSPORT}
)

set(INCS
    "include"
    "coreMQTT/source/include"
    "transport"
)

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}
)

target_link_libraries(${COMPONENT_NAME} PUBLIC tal_system tal_security)
