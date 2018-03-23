#ifndef PHP_STREAMS2_H
#define PHP_STREAMS2_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#define STREAM_SEEK_SET 0
#define STREAM_SEEK_CUR 1
#define STREAM_SEEK_END 2

PHP_FUNCTION(Open);

extern zend_module_entry streams2_module_entry;
#define phpext_streams2_ptr &streams2_module_entry

#endif //PHP_STREAMS2_H
