#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_streams2.h"

static zend_function_entry streams2_functions[] = {
        ZEND_NS_FE("Stream", Open, NULL)
        {NULL, NULL, NULL}
};

zend_module_entry streams2_module_entry = {
        STANDARD_MODULE_HEADER,
        PHP_STREAMS2_EXTNAME,
        streams2_functions,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        PHP_STREAMS2_VERSION,
        STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_STREAMS2
ZEND_GET_MODULE(streams2)
#endif

PHP_FUNCTION(Open)
{
    RETURN_STRING("not implemented yet...");
}
