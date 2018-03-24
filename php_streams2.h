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

PHP_FUNCTION(Open);
PHP_FUNCTION(stream_transport_register);
PHP_FUNCTION(stream_transport_unregister);
PHP_FUNCTION(stream_transport_exists);
PHP_FUNCTION(stream_wrapper_register);
PHP_FUNCTION(stream_wrapper_unregister);
PHP_FUNCTION(stream_wrapper_exists);
PHP_FUNCTION(stream_wrapper_getWrapper);

#define PHP_NS_NAMED_FE(ns, name, alias, args) ZEND_NS_NAMED_FE(ns, name, ZEND_FN(alias), args)

extern zend_module_entry streams2_module_entry;
#define phpext_streams2_ptr &streams2_module_entry

#endif //PHP_STREAMS2_H
