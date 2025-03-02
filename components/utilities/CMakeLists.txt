get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

file(GLOB SRCS 
    "src/*.c"
    "backoffAlgorithm/source/*.c"
)

set(INCS 
    "include"
    "backoffAlgorithm/source/include"
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
