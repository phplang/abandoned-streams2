#ifndef INCL_STREAMS2_H_
#define INCL_STREAMS2_H_

#include "php_streams2.h"

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

#define NS_STREAM "Stream"
#define NS_STREAM_TRANSPORT "Stream\\Transport"
#define NS_STREAM_WRAPPER "Stream\\Wrapper"

#define STREAM_SEEK_SET 0
#define STREAM_SEEK_CUR 1
#define STREAM_SEEK_END 2

#ifndef PHP_NS_ABSTRACT_ME
# define PHP_NS_ABSTRACT_ME(ns, classname, name, arginfo) \
         PHP_ABSTRACT_ME(ZEND_NS_NAME(ns, classname), name, arginfo)
#endif

#ifndef PHP_NS_FE
# define PHP_NS_FE ZEND_NS_FE
#endif

#ifndef PHP_NS_NAMED_FE
# define PHP_NS_NAMED_FE ZEND_NS_NAMED_FE
#endif

#define ZEND_ARG_OBJ_NS_INFO(byref, name, cls, nullable) \
    { #name, ZEND_TYPE_ENCODE_CLASS_CONST(cls, nullable), byref, 0 },

#endif
