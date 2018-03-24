#include "streams2.h"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_open, 0, 2, Stream, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, "Stream\\Context", 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_stream_wrapper_opendir, 0, 1, Stream, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, "Stream\\Context", 1)
ZEND_END_ARG_INFO()

// @todo this should have return type \Stream\StatBuf but does not exist yet
ZEND_BEGIN_ARG_INFO_EX(arginfo_stream_wrapper_stat, 0, 0, 1)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, "Stream\\Context", 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_unlink, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_move, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, to, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_copy, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, to, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_mkdir, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, recursive, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_rmdir, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_touch, 0, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_chmod, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_chusr, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_stream_wrapper_chgrp, 0, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, group, IS_STRING, 0)
ZEND_END_ARG_INFO()

static zend_class_entry *wrapper_interface_ce = NULL;
static zend_function_entry wrapper_interface_methods[] = {
    PHP_ABSTRACT_ME(Wrapper, getName, arginfo_stream_wrapper_getName)
    PHP_ABSTRACT_ME(Wrapper, open, arginfo_stream_wrapper_open)
    PHP_ABSTRACT_ME(Wrapper, opendir, arginfo_stream_wrapper_opendir)
    PHP_ABSTRACT_ME(Wrapper, stat, arginfo_stream_wrapper_stat)
    PHP_ABSTRACT_ME(Wrapper, unlink, arginfo_stream_wrapper_unlink)
    PHP_ABSTRACT_ME(Wrapper, move, arginfo_stream_wrapper_move)
    PHP_ABSTRACT_ME(Wrapper, copy, arginfo_stream_wrapper_copy)
    PHP_ABSTRACT_ME(Wrapper, mkdir, arginfo_stream_wrapper_mkdir)
    PHP_ABSTRACT_ME(Wrapper, rmdir, arginfo_stream_wrapper_rmdir)
    PHP_ABSTRACT_ME(Wrapper, touch, arginfo_stream_wrapper_touch)
    PHP_ABSTRACT_ME(Wrapper, chmod, arginfo_stream_wrapper_chmod)
    PHP_ABSTRACT_ME(Wrapper, chusr, arginfo_stream_wrapper_chusr)
    PHP_ABSTRACT_ME(Wrapper, chgrp, arginfo_stream_wrapper_chgrp)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_wrapper_interface) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM, "Wrapper", wrapper_interface_methods);
    wrapper_interface_ce = zend_register_internal_class(&ce);
    wrapper_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
