#include "streams2.h"

zend_class_entry *php_streams2_Stream_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_stream_interface_construct, 0, ZEND_RETURN_VALUE, 2)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, "Stream\\Context", 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_getUri, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_isOpen, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_read, 0, 0, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, maxbytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_write, 0, 1, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_flush, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_seek, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, whence, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_isSeekable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

// @todo this should have return type \Stream\StatBuf but does not exist yet
ZEND_BEGIN_ARG_INFO_EX(arginfo_stream_interface_stat, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_interface_setOption, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, option, IS_LONG, 0)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_interface_getStream, 0, 0, Stream, 0)
ZEND_END_ARG_INFO()

static zend_function_entry stream_interface_methods[] = {
    PHP_ABSTRACT_ME(Stream, __construct, arginfo_stream_interface_construct)
    PHP_ABSTRACT_ME(Stream, getName, arginfo_stream_interface_getName)
    PHP_ABSTRACT_ME(Stream, getUri, arginfo_stream_interface_getUri)
    PHP_ABSTRACT_ME(Stream, isOpen, arginfo_stream_interface_isOpen)
    PHP_ABSTRACT_ME(Stream, read, arginfo_stream_interface_read)
    PHP_ABSTRACT_ME(Stream, write, arginfo_stream_interface_write)
    PHP_ABSTRACT_ME(Stream, flush, arginfo_stream_interface_flush)
    PHP_ABSTRACT_ME(Stream, close, arginfo_stream_interface_close)
    PHP_ABSTRACT_ME(Stream, seek, arginfo_stream_interface_seek)
    PHP_ABSTRACT_ME(Stream, isSeekable, arginfo_stream_interface_isSeekable)
    PHP_ABSTRACT_ME(Stream, stat, arginfo_stream_interface_stat)
    PHP_ABSTRACT_ME(Stream, setOption, arginfo_stream_interface_setOption)
    PHP_ABSTRACT_ME(Stream, getStream, arginfo_stream_interface_getStream)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_stream_interface) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Stream", stream_interface_methods);
    php_streams2_Stream_ce = zend_register_internal_class(&ce);
    php_streams2_Stream_ce->ce_flags |= ZEND_ACC_INTERFACE;

    REGISTER_NS_LONG_CONSTANT(NS_STREAM, "SEEK_SET", PHP_STREAMS2_STREAM_SEEK_SET,
                              CONST_CS | CONST_PERSISTENT);
    REGISTER_NS_LONG_CONSTANT(NS_STREAM, "SEEK_CUR", PHP_STREAMS2_STREAM_SEEK_CUR,
                              CONST_CS | CONST_PERSISTENT);
    REGISTER_NS_LONG_CONSTANT(NS_STREAM, "SEEK_END", PHP_STREAMS2_STREAM_SEEK_END,
                              CONST_CS | CONST_PERSISTENT);

    return SUCCESS;
}
