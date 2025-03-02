get_filename_component(COMPONENT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

# SRCS
file(GLOB_RECURSE SRCS 
    "lan/*.c"
    "netmgr/netmgr.c" 
    "protocol/*.c" 
    "schema/*.c" 
    "cloud/*.c"
    "tls/*.c"
    "transport/*.c")

# INCS
set(INCS cloud .)
list(APPEND  INCS protocol)
list(APPEND  INCS schema)
list(APPEND  INCS lan)
list(APPEND  INCS tls)
list(APPEND  INCS netmgr)
list(APPEND  INCS transport)

if(CONFIG_ENABLE_WIFI STREQUAL "y")
    file(GLOB_RECURSE WIFI_SRCS 
        "netmgr/netconn_wifi.c" 
        "netcfg/*.c")
    list(APPEND SRCS ${WIFI_SRCS})
    list(APPEND  INCS netcfg)    
endif()

# if(CONFIG_ENABLE_WIRED STREQUAL "y")
    file(GLOB_RECURSE WIRED_SRCS 
        "netmgr/netconn_wired.c")
    list(APPEND SRCS ${WIRED_SRCS})
# endif()

if(CONFIG_ENABLE_BLUETOOTH STREQUAL "y")
    file(GLOB_RECURSE BLE_SRCS  
        "ble/*.c")
    list(APPEND SRCS ${BLE_SRCS})
    list(APPEND  INCS ble) 
endif()

add_library(${COMPONENT_NAME} 
    STATIC
    ${SRCS}
)

target_include_directories(${COMPONENT_NAME}
    PUBLIC
    ${INCS}
)

target_link_libraries(${COMPONENT_NAME} PUBLIC tal_system cJSON http_client mqtt_client)
