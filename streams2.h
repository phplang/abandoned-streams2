#ifndef INCL_STREAMS2_H_
#define INCL_STREAMS2_H_

#include "php_streams2.h"

PHP_MINIT_FUNCTION(streams2_context);
extern zend_class_entry *php_streams2_Context_ce;
extern zend_class_entry *php_streams2_TContext_ce;
extern zend_class_entry *php_streams2_Filter_ce;
extern zend_class_entry *php_streams2_NotificationListener_ce;

#define STREAMS2_EXCEPTIONS(X) \
    X(NotFound) \
    X(ConnectionReset) \
    X(Access) \
    X(Storage) \
    X(Lock)

PHP_MINIT_FUNCTION(streams2_exceptions);
extern zend_class_entry *php_streams2_Exception_ce;

#define X(name) \
    extern zend_class_entry *php_streams2_##name##Exception_ce;
STREAMS2_EXCEPTIONS(X)
#undef X

extern zend_class_entry *statbuf_file_interface_ce;

PHP_MINIT_FUNCTION(streams2_stream_interface);
PHP_MINIT_FUNCTION(streams2_wrapper_interface);
PHP_MINIT_FUNCTION(streams2_statbuf_interface);
PHP_MINIT_FUNCTION(streams2_statbuf_sizable_interface);
PHP_MINIT_FUNCTION(streams2_statbuf_file_interface);
PHP_MINIT_FUNCTION(streams2_statbuf_posixfile_interface);

#define NS_STREAM "Stream"
#define NS_STREAM_TRANSPORT "Stream\\Transport"
#define NS_STREAM_WRAPPER "Stream\\Wrapper"
#define NS_STREAM_CONTEXT "Stream\\Context"
#define NS_STREAM_STATBUF "Stream\\StatBuf"

#define PHP_STREAMS2_STREAM_SEEK_SET 0
#define PHP_STREAMS2_STREAM_SEEK_CUR 1
#define PHP_STREAMS2_STREAM_SEEK_END 2

#define PHP_STREAMS2_CONTEXT_READ_FILTER "read_filter"
#define PHP_STREAMS2_CONTEXT_WRITE_FILTER "write_filter"
#define PHP_STREAMS2_CONTEXT_NOTIFIER "notifier"

#ifndef PHP_NS_FE
# define PHP_NS_FE ZEND_NS_FE
#endif

#ifndef PHP_NS_NAME
# define PHP_NS_NAME ZEND_NS_NAME
#endif

#ifndef PHP_NS_NAMED_FE
# define PHP_NS_NAMED_FE ZEND_NS_NAMED_FE
#endif

#define ZEND_ARG_OBJ_NS_INFO(byref, name, cls, nullable) \
    { #name, ZEND_TYPE_ENCODE_CLASS_CONST(cls, nullable), byref, 0 },

#endif
