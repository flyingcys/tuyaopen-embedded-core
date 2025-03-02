/**
 * @file tkl_output.c
 * @brief the default weak implements of tuya os output, this implement only used when OS=linux
 * @version 0.1
 * @date 2019-08-15
 * 
 * @copyright Copyright 2020-2021 Tuya Inc. All Rights Reserved.
 * 
 */

#include "tkl_output.h"
#include <stdio.h>

#ifndef MAX_SIZE_OF_DEBUG_BUF
#define MAX_SIZE_OF_DEBUG_BUF (4096)
#endif

static char s_output_buf[MAX_SIZE_OF_DEBUG_BUF] = {0};
/**
* @brief Output log information
*
* @param[in] str: log information
*
* @note This API is used for outputing log information
*
* @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
*/
TUYA_WEAK_ATTRIBUTE void tkl_log_output(const char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    vsnprintf(s_output_buf, MAX_SIZE_OF_DEBUG_BUF,str,ap);
    va_end(ap);
    printf("%s", s_output_buf);
    fflush(stdout);

    return;
}

/**
* @brief Close log port
*
* @param void
*
* @note This API is used for closing log port.
*
* @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
*/
TUYA_WEAK_ATTRIBUTE OPERATE_RET tkl_log_close(void)
{
    return OPRT_OK;
}

/**
* @brief Open log port
*
* @param void
*
* @note This API is used for openning log port.
*
* @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
*/
TUYA_WEAK_ATTRIBUTE OPERATE_RET tkl_log_open(void)
{
    return OPRT_OK;
}


