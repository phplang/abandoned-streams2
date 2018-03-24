#include "streams2.h"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_statbuf_file_interface_getCTime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_statbuf_file_interface_getMTime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_statbuf_file_interface_getATime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

static zend_class_entry *statbuf_file_interface_ce = NULL;
static zend_function_entry statbuf_file_interface_methods[] = {
    PHP_ABSTRACT_ME(File, getCTime, arginfo_statbuf_file_interface_getCTime)
    PHP_ABSTRACT_ME(File, getMTime, arginfo_statbuf_file_interface_getMTime)
    PHP_ABSTRACT_ME(File, getATime, arginfo_statbuf_file_interface_getATime)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_statbuf_file_interface) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM_STATBUF, "File", statbuf_file_interface_methods);
    statbuf_file_interface_ce = zend_register_internal_class(&ce);
    statbuf_file_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
