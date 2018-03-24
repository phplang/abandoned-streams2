#include "streams2.h"
#include "zend_exceptions.h"

zend_class_entry *php_streams2_File_ce;
static zend_object_handlers file_handlers;

typedef struct _streams2_file {
    php_stream *stream;
    zend_object std;
} streams2_file;

static inline streams2_file* file_from_zend_object(zend_object* obj) {
    return ((streams2_file*)(obj + 1)) - 1;
}

static inline zend_object* file_to_zend_object(streams2_file* obj) {
    return ((zend_object*)(obj + 1)) - 1;
}

static zend_bool verifyURIScheme(zend_string *uri) {
    const char *sep = strstr(ZSTR_VAL(uri), "://");
    if (sep) {
        return 0;
    }
    const char *colon = strchr(ZSTR_VAL(uri), ':');
    if (!colon) {
        return 1;
    }
    if ((colon - ZSTR_VAL(uri)) != 4) {
        return 1;
    }
    if (!strncasecmp(ZSTR_VAL(uri), "data", 4) ||
        !strncasecmp(ZSTR_VAL(uri), "zlib", 4)) {
        return 0;
    }
    return 1;
}

/***************************************************************************/

/* {{{ proto void File::__construct(string $uri, ?Stream\Context $ctx = NULL) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_ctor, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
    ZEND_ARG_OBJ_NS_INFO(0, context, PHP_NS_NAME(NS_STREAM, "Context"), 1)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, __construct) {
    streams2_file *fobj = file_from_zend_object(Z_OBJ_P(getThis()));
    zend_string *uri, *mode;
    zval *ctx = NULL;

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "PP|z!", &uri, &mode, &ctx) == FAILURE) {
        return;
    }

    if (!verifyURIScheme(uri)) {
        zend_throw_exception_ex(php_streams2_NotFoundException_ce, 0,
                                "Illegal URI: '%s'", ZSTR_VAL(uri));
        return;
    }

    // TODO context
    fobj->stream = php_stream_open_wrapper_ex(ZSTR_VAL(uri), ZSTR_VAL(mode), 0, NULL, NULL);
    if (!fobj->stream) {
        zend_throw_exception_ex(php_streams2_Exception_ce, 0, "Failed opening file");
        return;
    }
}
/* }}} */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_getvoid, ZEND_RETURN_VALUE, 0, IS_VOID, 0)
ZEND_END_ARG_INFO();
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_getbool, ZEND_RETURN_VALUE, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO();
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_getstring, ZEND_RETURN_VALUE, 0, IS_STRING, 0)
ZEND_END_ARG_INFO();

#define FETCH_OPEN_STREAM(varname) \
    php_stream *varname = file_from_zend_object(Z_OBJ_P(getThis()))->stream; \
    if (!varname) { \
        zend_throw_exception_ex(php_streams2_Exception_ce, 0, \
                                "Stream object is not open"); \
    }

/* {{{ proto string File::getName() */
static PHP_METHOD(File, getName) {
    FETCH_OPEN_STREAM(stream);
    if (zend_parse_parameters_none_throw() == FAILURE) { return; }
    RETURN_STRING(stream->ops->label);
}
/* }}} */

/* {{{ proto string File::getUri() */
static PHP_METHOD(File, getUri) {
    FETCH_OPEN_STREAM(stream);
    if (zend_parse_parameters_none_throw() == FAILURE) { return; }
    RETURN_STRING("TODO");
}
/* }}} */

/* {{{ proto bool File::isOpen() */
static PHP_METHOD(File, isOpen) {
    if (zend_parse_parameters_none_throw() == FAILURE) { return; }
    RETURN_BOOL(file_from_zend_object(Z_OBJ_P(getThis()))->stream);
}
/* }}} */

/* {{{ proto string File::read(int $max_bytes = 0) */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_read, ZEND_RETURN_VALUE, 0, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, max_bytes, IS_LONG, 0)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, read) {
    zend_long max_bytes = 0;
    zend_string *ret;
    FETCH_OPEN_STREAM(stream);

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "|l!", &max_bytes) == FAILURE) {
        return;
    }

    if (max_bytes <= 0) {
        max_bytes = 8192;
    }
    ret = zend_string_alloc(max_bytes, 0);
    ZSTR_LEN(ret) = php_stream_read(stream, ZSTR_VAL(ret), max_bytes);
    ZSTR_VAL(ret)[ZSTR_LEN(ret)] = 0;
    RETURN_NEW_STR(ret);
}
/* }}} */

/* {{{ proto int File::write(string $data) */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_write, ZEND_RETURN_VALUE, 0, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, write) {
    zend_string *data;
    FETCH_OPEN_STREAM(stream);

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "S", &data) == FAILURE) {
        return;
    }

    RETURN_LONG(php_stream_write(stream, ZSTR_VAL(data), ZSTR_LEN(data)));
}
/* }}} */

/* {{{ proto bool File::flush() */
static PHP_METHOD(File, flush) {
    FETCH_OPEN_STREAM(stream);
    RETURN_BOOL(SUCCESS == php_stream_flush(stream));
}
/* }}} */

/* {{{ proto void File::close() */
static PHP_METHOD(File, close) {
    FETCH_OPEN_STREAM(stream);
    php_stream_close(stream);
    file_from_zend_object(Z_OBJ_P(getThis()))->stream = NULL;
}
/* }}} */

/* {{{ proto bool File::seek(int $pos, int $whence = SEEK_SET) */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_seek, ZEND_RETURN_VALUE, 1, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, whence, IS_LONG, 0)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, seek) {
    zend_long pos, whence = PHP_STREAMS2_STREAM_SEEK_SET;
    FETCH_OPEN_STREAM(stream);

    if (zend_parse_parameters_throw(ZEND_NUM_ARGS(), "l|l!", &pos, &whence) == FAILURE) {
        return;
    }

    RETURN_BOOL(SUCCESS == php_stream_seek(stream, pos, whence));
}
/* }}} */

/* {{{ proto bool File::isSeekable() */
static PHP_METHOD(File, isSeekable) {
    FETCH_OPEN_STREAM(stream);
    if (FAILURE == zend_parse_parameters_none_throw()) { return; }

    RETURN_TRUE;
}
/* }}} */

/* {{{ Stream\Statbuf File::stat() */
static PHP_METHOD(File, stat) {
    FETCH_OPEN_STREAM(stream);
    if (FAILURE == zend_parse_parameters_none_throw()) { return; }

    /* TODO */
}
/* }}} */

/* {{{ Stream\Statbuf File::setOption(int $option, $value) */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_setoption, ZEND_RETURN_VALUE, 2, _IS_BOOL, 0)
    ZEND_ARG_TYPE_INFO(0, option, IS_LONG, 0)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, setOption) {
    FETCH_OPEN_STREAM(stream);
    if (FAILURE == zend_parse_parameters_none_throw()) { return; }

    /* TODO */
    RETURN_FALSE;
}
/* }}} */

/* {{{ Stream\Statbuf File::getStream() */
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_getstream, ZEND_RETURN_VALUE, 0, Stream, 0)
ZEND_END_ARG_INFO();
static PHP_METHOD(File, getStream) {
    zend_throw_exception(php_streams2_Exception_ce, "No underlying stream", 0);
}
/* }}} */

static zend_function_entry file_methods[] = {
    PHP_ME(File, __construct, arginfo_ctor, ZEND_ACC_CTOR | ZEND_ACC_PUBLIC)
    PHP_ME(File, getName, arginfo_getstring, ZEND_ACC_PUBLIC)
    PHP_ME(File, getUri, arginfo_getstring, ZEND_ACC_PUBLIC)
    PHP_ME(File, isOpen, arginfo_getbool, ZEND_ACC_PUBLIC)
    PHP_ME(File, read, arginfo_read, ZEND_ACC_PUBLIC)
    PHP_ME(File, write, arginfo_write, ZEND_ACC_PUBLIC)
    PHP_ME(File, flush, arginfo_getbool, ZEND_ACC_PUBLIC)
    PHP_ME(File, close, arginfo_getvoid, ZEND_ACC_PUBLIC)
    PHP_ME(File, seek, arginfo_seek, ZEND_ACC_PUBLIC)
    PHP_ME(File, isSeekable, arginfo_getbool, ZEND_ACC_PUBLIC)
    PHP_ME(File, stat, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(File, setOption, arginfo_setoption, ZEND_ACC_PUBLIC)
    PHP_ME(File, getStream, arginfo_getstream, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

static zend_object* file_create(zend_class_entry *ce) {
    streams2_file *fobj = ecalloc(1, sizeof(streams2_file) + zend_object_properties_size(ce));
    zend_object *ret = file_to_zend_object(fobj);
    zend_object_std_init(ret, ce);
    ret->handlers = &file_handlers;
    object_properties_init(ret, ce);
    return ret;
}

static zend_object* file_clone(zval *src) {
    zend_object *zsrc = Z_OBJ_P(src);
    streams2_file *fsrc = file_from_zend_object(zsrc);
    zend_object *zdst = file_create(Z_OBJCE_P(src));
    streams2_file *fdst = file_from_zend_object(zdst);

    zend_objects_clone_members(zdst, zsrc);
    if (fsrc->stream) {
        // TODO: Make Streams clonable.
        zend_throw_exception(php_streams2_Exception_ce, "Stream is not clonable", 0);
    }

    return zdst;
}

static void file_free(zend_object *zobj) {
    streams2_file *fobj = file_from_zend_object(zobj);
    if (fobj->stream) {
        php_stream_close(fobj->stream);
    }
    zend_object_std_dtor(zobj);
}

PHP_MINIT_FUNCTION(streams2_file) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, PHP_NS_NAME(NS_STREAM, "File"), file_methods);
    php_streams2_File_ce = zend_register_internal_class(&ce);
    zend_class_implements(php_streams2_File_ce, 1, php_streams2_Stream_ce);
    php_streams2_File_ce->create_object = file_create;
    memcpy(&file_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    file_handlers.offset = XtOffsetOf(streams2_file, std);
    file_handlers.free_obj = file_free;
    file_handlers.clone_obj = file_clone;

    return SUCCESS;
}
