#include "streams2.h"

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

static zend_function_entry streams2_functions[] = {
    PHP_FE_END
};

static zend_class_entry *stream_interface_ce = NULL;
static zend_function_entry stream_interface_methods[] = {
        PHP_ABSTRACT_ME(Stream, __construct, NULL)
        PHP_ABSTRACT_ME(Stream, getName, NULL)
        PHP_FE_END
};

static PHP_MINIT_FUNCTION(streams2) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Stream", stream_interface_methods);
    stream_interface_ce = zend_register_internal_class(&ce);
    stream_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return (1 == 1) &&
        (SUCCESS == PHP_MINIT(streams2_exceptions)(INIT_FUNC_ARGS_PASSTHRU))
        ? SUCCESS : FAILURE;
}

zend_module_entry streams2_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_STREAMS2_EXTNAME,
    streams2_functions,
    PHP_MINIT(streams2),
    NULL, /* SHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    PHP_STREAMS2_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_STREAMS2
ZEND_GET_MODULE(streams2)
#endif
