#ifndef PHP_STREAMS2_H
#define PHP_STREAMS2_H

#define PHP_STREAMS2_VERSION "1.0"
#define PHP_STREAMS2_EXTNAME "streams2"

PHP_FUNCTION(Open);

extern zend_module_entry streams2_module_entry;
#define phpext_streams2_ptr &streams2_module_entry

#endif //PHP_STREAMS2_H
