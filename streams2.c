#include "streams2.h"

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

static PHP_FUNCTION(Open) {
    RETURN_STRING("not implemented yet...");
}

static zend_function_entry streams2_functions[] = {
    PHP_NS_FE("Stream", Open, NULL)
    PHP_FE_END
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
