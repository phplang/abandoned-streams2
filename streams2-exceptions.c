#include "streams2.h"
#include "zend_exceptions.h"

#define X(name) \
    zend_class_entry *php_streams2_##name##Exception_ce;
zend_class_entry *php_streams2_Exception_ce;
STREAMS2_EXCEPTIONS(X)
#undef X

PHP_MINIT_FUNCTION(streams2_exceptions) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "Stream\\Exception", NULL);
    php_streams2_Exception_ce = zend_register_internal_class_ex(&ce, zend_ce_exception);

#define X(name) \
    INIT_CLASS_ENTRY(ce, "Stream\\" #name "Exception", NULL); \
    php_streams2_##name##Exception_ce = zend_register_internal_class_ex(&ce, php_streams2_Exception_ce);
STREAMS2_EXCEPTIONS(X)
#undef X

    return SUCCESS;
}
