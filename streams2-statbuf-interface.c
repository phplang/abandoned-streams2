#include "streams2.h"

static zend_class_entry *statbuf_interface_ce = NULL;
static zend_function_entry statbuf_interface_methods[] = {
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_statbuf_interface) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM, "StatBuf", statbuf_interface_methods);
    statbuf_interface_ce = zend_register_internal_class(&ce);
    statbuf_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
