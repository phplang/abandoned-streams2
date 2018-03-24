#ifndef PHP_STREAMS2_H
#define PHP_STREAMS2_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#define NS_STREAM "Stream"
#define NS_STREAM_TRANSPORT "Stream\\Transport"
#define NS_STREAM_WRAPPER "Stream\\Wrapper"

#define STREAM_SEEK_SET 0
#define STREAM_SEEK_CUR 1
#define STREAM_SEEK_END 2

#define PHP_NS_NAMED_FE(ns, name, alias, arginfo) ZEND_NS_NAMED_FE(ns, name, ZEND_FN(alias), arginfo)
#define PHP_NS_ABSTRACT_ME(ns, classname, name, arginfo) PHP_ABSTRACT_ME(ZEND_NS_NAME(ns, classname), name, arginfo)

extern zend_module_entry streams2_module_entry;
#define phpext_streams2_ptr &streams2_module_entry

#endif //PHP_STREAMS2_H
