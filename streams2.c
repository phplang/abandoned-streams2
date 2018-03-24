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
    // @todo implement this
    RETURN_STRING("Stream\\Wrapper\\register() not implemented yet...");
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
    ZEND_ARG_INFO(0, context) // @todo should be \Stream\Context interface but does not exist yet
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


ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_open, 0, 2, Stream, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
    ZEND_ARG_INFO(0, context) // @todo should be \Stream\Context interface but does not exist yet
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_opendir, 0, 1, Stream, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
    ZEND_ARG_INFO(0, context) // @todo should be \Stream\Context interface but does not exist yet
ZEND_END_ARG_INFO()

// @todo this should have return type \Stream\StatBuf but does not exist yet
ZEND_BEGIN_ARG_INFO_EX(arginfo_stream_wrapper_stat, 0, 0, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
    ZEND_ARG_INFO(0, context) // @todo should be \Stream\Context interface but does not exist yet
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_unlink, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_move, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, to, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_copy, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, to, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_mkdir, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, recursive, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_rmdir, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_touch, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_chmod, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_chusr, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_chgrp, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
ZEND_END_ARG_INFO()

static zend_class_entry *wrapper_interface_ce = NULL;
static zend_function_entry wrapper_interface_methods[] = {
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, getName, arginfo_stream_wrapper_getName)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, open, arginfo_stream_wrapper_open)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, opendir, arginfo_stream_wrapper_opendir)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, stat, arginfo_stream_wrapper_stat)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, unlink, arginfo_stream_wrapper_unlink)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, move, arginfo_stream_wrapper_move)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, copy, arginfo_stream_wrapper_copy)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, mkdir, arginfo_stream_wrapper_mkdir)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, rmdir, arginfo_stream_wrapper_rmdir)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, touch, arginfo_stream_wrapper_touch)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, chmod, arginfo_stream_wrapper_chmod)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, chusr, arginfo_stream_wrapper_chusr)
    PHP_NS_ABSTRACT_ME(NS_STREAM, Wrapper, chgrp, arginfo_stream_wrapper_chgrp)
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(streams2) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM, "Wrapper", wrapper_interface_methods);
    wrapper_interface_ce = zend_register_internal_class(&ce);
    wrapper_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return (1 == 1) &&
        (SUCCESS == PHP_MINIT(streams2_exceptions)(INIT_FUNC_ARGS_PASSTHRU)) &&
        (SUCCESS == PHP_MINIT(streams2_stream_interface)(INIT_FUNC_ARGS_PASSTHRU))
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
