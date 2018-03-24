#ifndef INCL_STREAMS2_H_
#define INCL_STREAMS2_H_

#include "php_streams2.h"

PHP_MINIT_FUNCTION(streams2_exceptions);

#define NS_STREAM "Stream"
#define NS_STREAM_TRANSPORT "Stream\\Transport"
#define NS_STREAM_WRAPPER "Stream\\Wrapper"

#define STREAM_SEEK_SET 0
#define STREAM_SEEK_CUR 1
#define STREAM_SEEK_END 2

#define PHP_NS_NAMED_FE(ns, name, alias, arginfo) ZEND_NS_NAMED_FE(ns, name, ZEND_FN(alias), arginfo)
#define PHP_NS_ABSTRACT_ME(ns, classname, name, arginfo) PHP_ABSTRACT_ME(ZEND_NS_NAME(ns, classname), name, arginfo)

#ifndef PHP_NS_FE
#define PHP_NS_FE ZEND_NS_FE
#endif

#endif
