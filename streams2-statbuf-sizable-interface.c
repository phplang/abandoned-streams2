#include "streams2.h"

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_statbuf_sizable_interface_getSize, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

static zend_class_entry *statbuf_sizable_interface_ce = NULL;
static zend_function_entry statbuf_sizable_interface_methods[] = {
    PHP_ABSTRACT_ME(Sizable, getSize, arginfo_statbuf_sizable_interface_getSize)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_statbuf_sizable_interface) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM_STATBUF, "Sizable", statbuf_sizable_interface_methods);
    statbuf_sizable_interface_ce = zend_register_internal_class(&ce);
    statbuf_sizable_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
