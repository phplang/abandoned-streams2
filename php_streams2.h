#ifndef PHP_STREAMS2_H
#define PHP_STREAMS2_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

extern zend_module_entry streams2_module_entry;
#define phpext_streams2_ptr &streams2_module_entry

#endif //PHP_STREAMS2_H
