#include "streams2.h"

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

ZEND_BEGIN_ARG_INFO(arginfo_stream_open, 0)
        ZEND_ARG_INFO(0, uri)
        ZEND_ARG_INFO(0, mode)
        ZEND_ARG_INFO(0, options)
        ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_transport_register, 0)
        ZEND_ARG_INFO(0, scheme)
        ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_transport_unregister, 0)
        ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_transport_exists, 0)
        ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_wrapper_register, 0)
        ZEND_ARG_INFO(0, scheme)
        ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_wrapper_unregister, 0)
        ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_wrapper_exists, 0)
        ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_wrapper_getWrapper, 0)
        ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

static zend_function_entry streams2_functions[] = {
    ZEND_NS_FE(NS_STREAM, Open, arginfo_stream_open)
    ZEND_NS_NAMED_FE(NS_STREAM_TRANSPORT, register, ZEND_FN(stream_transport_register), arginfo_stream_transport_register)
    ZEND_NS_NAMED_FE(NS_STREAM_TRANSPORT, unregister, ZEND_FN(stream_transport_unregister), arginfo_stream_transport_unregister)
    ZEND_NS_NAMED_FE(NS_STREAM_TRANSPORT, exists, ZEND_FN(stream_transport_exists), arginfo_stream_transport_exists)
    ZEND_NS_NAMED_FE(NS_STREAM_WRAPPER, register, ZEND_FN(stream_wrapper_register), arginfo_stream_wrapper_register)
    ZEND_NS_NAMED_FE(NS_STREAM_WRAPPER, unregister, ZEND_FN(stream_wrapper_unregister), arginfo_stream_wrapper_unregister)
    ZEND_NS_NAMED_FE(NS_STREAM_WRAPPER, exists, ZEND_FN(stream_wrapper_exists), arginfo_stream_wrapper_exists)
    ZEND_NS_NAMED_FE(NS_STREAM_WRAPPER, getWrapper, ZEND_FN(stream_wrapper_getWrapper), arginfo_stream_wrapper_getWrapper)
    PHP_FE_END
};

ZEND_BEGIN_ARG_INFO(arginfo_stream_interface_read, 0)
        ZEND_ARG_INFO(0, maxbytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_interface_write, 0)
        ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_interface_seek, 0)
        ZEND_ARG_INFO(0, pos)
        ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_stream_interface_setOption, 0)
        ZEND_ARG_INFO(0, option)
        ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static zend_class_entry *stream_interface_ce = NULL;
static zend_function_entry stream_interface_methods[] = {
        PHP_ABSTRACT_ME(Stream, __construct, NULL)
        PHP_ABSTRACT_ME(Stream, getName, NULL)
        PHP_ABSTRACT_ME(Stream, getUri, NULL)
        PHP_ABSTRACT_ME(Stream, isOpen, NULL)
        PHP_ABSTRACT_ME(Stream, read, arginfo_stream_interface_read)
        PHP_ABSTRACT_ME(Stream, write, arginfo_stream_interface_write)
        PHP_ABSTRACT_ME(Stream, flush, NULL)
        PHP_ABSTRACT_ME(Stream, close, NULL)
        PHP_ABSTRACT_ME(Stream, seek, arginfo_stream_interface_seek)
        PHP_ABSTRACT_ME(Stream, isSeekable, NULL)
        PHP_ABSTRACT_ME(Stream, stat, NULL)
        PHP_ABSTRACT_ME(Stream, setOption, arginfo_stream_interface_setOption)
        PHP_ABSTRACT_ME(Stream, getStream, NULL)
        PHP_FE_END
};

static PHP_MINIT_FUNCTION(streams2) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Stream", stream_interface_methods);
    stream_interface_ce = zend_register_internal_class(&ce);
    stream_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    zend_declare_class_constant_long(stream_interface_ce, "SEEK_SET", strlen("SEEK_SET"), STREAM_SEEK_SET);
    zend_declare_class_constant_long(stream_interface_ce, "SEEK_CUR", strlen("SEEK_CUR"), STREAM_SEEK_CUR);
    zend_declare_class_constant_long(stream_interface_ce, "SEEK_END", strlen("SEEK_END"), STREAM_SEEK_END);

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

PHP_FUNCTION(Open)
{
    // @todo implement this
    RETURN_STRING("Stream\\Open() not implemented yet...");
}

PHP_FUNCTION(stream_transport_register)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\register() not implemented yet...");
}

PHP_FUNCTION(stream_transport_unregister)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\unregister() not implemented yet...");
}

PHP_FUNCTION(stream_transport_exists)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\exists() not implemented yet...");
}

PHP_FUNCTION(stream_wrapper_register)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\register() not implemented yet...");
}

PHP_FUNCTION(stream_wrapper_unregister)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\unregister() not implemented yet...");
}

PHP_FUNCTION(stream_wrapper_exists)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\exists() not implemented yet...");
}

PHP_FUNCTION(stream_wrapper_getWrapper)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\getWrapper() not implemented yet...");
}

#ifdef COMPILE_DL_STREAMS2
ZEND_GET_MODULE(streams2)
#endif
