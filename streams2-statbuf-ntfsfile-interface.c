#include "streams2.h"

static zend_class_entry *statbuf_ntfsfile_interface_ce = NULL;
static zend_function_entry statbuf_ntfsfile_interface_methods[] = {
    PHP_FE_END
};

PHP_MINIT_FUNCTION(streams2_statbuf_ntfsfile_interface) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, NS_STREAM_STATBUF, "NTFSFile", statbuf_ntfsfile_interface_methods);
    statbuf_ntfsfile_interface_ce = zend_register_internal_class(&ce);
    statbuf_ntfsfile_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;
    statbuf_ntfsfile_interface_ce->parent = statbuf_file_interface_ce;

    return SUCCESS;
}
