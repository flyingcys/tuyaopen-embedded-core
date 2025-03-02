get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(SRCS 
    "tal_network/src/tal_network.c"
    "tal_wired/src/tal_wired.c"
)

set(INCS 
    "tal_network/include"
    "tal_wired/include"
)

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}
)
target_link_libraries(${COMPONENT_NAME} PUBLIC tal_system)
