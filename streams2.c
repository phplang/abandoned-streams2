#include "streams2.h"

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

static zend_function_entry streams2_functions[] = {
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(streams2) {
    return (1 == 1) &&
        (SUCCESS == PHP_MINIT(streams2_exceptions)(INIT_FUNC_ARGS_PASSTHRU))
        ? SUCCESS : FAILURE;
}

zend_module_entry streams2_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_STREAMS2_EXTNAME,
    streams2_functions,
    PHP_MINIT(streams2),
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
