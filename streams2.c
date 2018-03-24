#include "streams2.h"

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

static PHP_FUNCTION(Open)
{
    // @todo implement this
    RETURN_STRING("Stream\\Open() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_transport_register)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\register() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_transport_unregister)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\unregister() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_transport_exists)
{
    // @todo implement this
    RETURN_STRING("Stream\\Transport\\exists() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_wrapper_register)
{
    char *scheme;
    size_t scheme_len;
    zend_fcall_info stream_factory;
    zend_fcall_info_cache fci_cache;
    zval stream;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(scheme, scheme_len)
        Z_PARAM_FUNC(stream_factory, fci_cache)
    ZEND_PARSE_PARAMETERS_END();

    stream_factory.retval = &stream;
    stream_factory.param_count = 0;
    // @todo stream_factory needs passed: string $uri, string $mode, ?\Stream\Context $context = null

    // @todo could also call this lazily?
    if (zend_call_function(&stream_factory, &fci_cache) != SUCCESS) {
        return;
    }

    // @todo if (!$stream implements \Stream)
    if (Z_TYPE(stream) != IS_OBJECT) {
        // @todo better exception type..
        zend_throw_error(NULL, "Factory did not return something implementing Stream");
    }

    // @todo do something with the scheme&stream............

    RETURN_TRUE
}

static PHP_NAMED_FUNCTION(stream_wrapper_unregister)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\unregister() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_wrapper_exists)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\exists() not implemented yet...");
}

static PHP_NAMED_FUNCTION(stream_wrapper_getWrapper)
{
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\getWrapper() not implemented yet...");
}

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_open, 0, 3, Stream, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, "Stream\\Context", 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_transport_register, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, factory, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_transport_unregister, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_transport_exists, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_register, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, factory, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_unregister, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_exists, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_getWrapper, 0, 1, Stream\\Wrapper, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO()

static zend_function_entry streams2_functions[] = {
    PHP_NS_FE(NS_STREAM, Open, arginfo_stream_open)
    PHP_NS_NAMED_FE(NS_STREAM_TRANSPORT, register, stream_transport_register, arginfo_stream_transport_register)
    PHP_NS_NAMED_FE(NS_STREAM_TRANSPORT, unregister, stream_transport_unregister, arginfo_stream_transport_unregister)
    PHP_NS_NAMED_FE(NS_STREAM_TRANSPORT, exists, stream_transport_exists, arginfo_stream_transport_exists)
    PHP_NS_NAMED_FE(NS_STREAM_WRAPPER, register, stream_wrapper_register, arginfo_stream_wrapper_register)
    PHP_NS_NAMED_FE(NS_STREAM_WRAPPER, unregister, stream_wrapper_unregister, arginfo_stream_wrapper_unregister)
    PHP_NS_NAMED_FE(NS_STREAM_WRAPPER, exists, stream_wrapper_exists, arginfo_stream_wrapper_exists)
    PHP_NS_NAMED_FE(NS_STREAM_WRAPPER, getWrapper, stream_wrapper_getWrapper, arginfo_stream_wrapper_getWrapper)
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(streams2) {
    return (1 == 1)
        && (SUCCESS == PHP_MINIT(streams2_stream_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_file)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_context)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_exceptions)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_statbuf_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_statbuf_sizable_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_statbuf_file_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_statbuf_posixfile_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_statbuf_ntfsfile_interface)(INIT_FUNC_ARGS_PASSTHRU))
        && (SUCCESS == PHP_MINIT(streams2_wrapper_interface)(INIT_FUNC_ARGS_PASSTHRU))
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
