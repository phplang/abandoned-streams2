#include "streams2.h"
#include "zend_exceptions.h"

/***************************************************************************/
/* Stream\Context interface */

zend_class_entry *php_streams2_Context_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_getoption, 0, ZEND_RETURN_VALUE, 2)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_getschemeoptions, ZEND_RETURN_VALUE, 1, IS_ARRAY, 0)
    ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
ZEND_END_ARG_INFO(); 

ZEND_BEGIN_ARG_INFO_EX(arginfo_getparam, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_TYPE_INFO(0, param, IS_STRING, 0)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_getall, ZEND_RETURN_VALUE, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO();

static zend_function_entry context_interface_methods[] = {
    PHP_ABSTRACT_ME(Context, getOption, arginfo_getoption)
    PHP_ABSTRACT_ME(Context, getSchemeOptions, arginfo_getschemeoptions)
    PHP_ABSTRACT_ME(Context, getAllOptions, arginfo_getall)
    PHP_ABSTRACT_ME(Context, getParam, arginfo_getparam)
    PHP_ABSTRACT_ME(Context, getAllParams, arginfo_getall)
    PHP_FE_END
};

/***************************************************************************/
/* Stream\TContext trait for common contexts */
zend_class_entry *php_streams2_TContext_ce;

/* {{{ proto mixed TContext::getOption(string $scheme, string $option) */
static PHP_METHOD(TContext, getOption) {
    zend_string *scheme, *option;
    zval fname, arg, retval, *opt;
    int call_result;

    if (FAILURE == zend_parse_parameters_throw(ZEND_NUM_ARGS(), "SS", &scheme, &option)) {
        return;
    }

    ZVAL_STRING(&fname, "getSchemeOptions");
    ZVAL_STR(&arg, scheme);
    ZVAL_UNDEF(&retval);

    call_result = call_user_function(NULL, getThis(), &fname, &retval, 1, &arg);
    zval_dtor(&arg);
    zval_dtor(&fname);

    if ((FAILURE == call_result) || (Z_TYPE(retval) != IS_ARRAY)) {
        zval_dtor(&retval);
        zend_throw_exception_ex(php_streams2_Exception_ce, 0,
                                "Failure calling Context::getSchemeOptions('%s')", ZSTR_VAL(scheme));
        return;
    }

    opt = zend_symtable_find(Z_ARR(retval), option);
    zval_dtor(&retval);
    if (!opt) {
        zend_throw_exception_ex(php_streams2_NotFoundException_ce, 0,
                                "Unknown stream context option '%s' for scheme '%s'",
                                ZSTR_VAL(option), ZSTR_VAL(scheme));
        return;
    }

    RETURN_ZVAL(opt, 1, 0);
}
/* }}} */

/* {{{ proto array TContext::getSchemeOptions(string $scheme) */
static PHP_METHOD(TContext, getSchemeOptions) {
    zend_string *scheme;
    zval fname, retval, *opts;
    int call_result;

    if (FAILURE == zend_parse_parameters_throw(ZEND_NUM_ARGS(), "S", &scheme)) {
        return;
    }

    ZVAL_STRING(&fname, "getAllOptions");
    ZVAL_UNDEF(&retval);

    call_result = call_user_function(NULL, getThis(), &fname, &retval, 0, NULL);
    zval_dtor(&fname);

    if ((FAILURE == call_result) || (Z_TYPE(retval) != IS_ARRAY)) {
        zval_dtor(&retval);
        zend_throw_exception_ex(php_streams2_Exception_ce, 0,
                                "Failure calling Context::getAllOptions()");
        return;
    }

    opts = zend_symtable_find(Z_ARR(retval), scheme);
    zval_dtor(&retval);
    if (!opts) {
        array_init(return_value);
        return;
    }
    if (Z_TYPE_P(opts) != IS_ARRAY) {
        zend_throw_exception_ex(php_streams2_Exception_ce, 0,
                                "Invalid return from Context::getAllOptions()");
        return;
    }

    RETURN_ZVAL(opts, 1, 0);
}
/* }}} */

/* {{{ proto array TContext::getAllOptions() */
static PHP_METHOD(TContext, getAllOptions) {
    array_init(return_value);
}
/* }}} */

/* {{{ proto mixed TContext::getParam(string $param) */
static PHP_METHOD(TContext, getParam) {
    zend_string *param;
    zval fname, retval, *p;
    int call_result;

    if (FAILURE == zend_parse_parameters_throw(ZEND_NUM_ARGS(), "S", &param)) {
        return;
    }

    ZVAL_STRING(&fname, "getAllParams");
    ZVAL_UNDEF(&retval);

    call_result = call_user_function(NULL, getThis(), &fname, &retval, 0, NULL);
    zval_dtor(&fname);

    if ((FAILURE == call_result) || (Z_TYPE(retval) != IS_ARRAY)) {
        zval_dtor(&retval);
        zend_throw_exception_ex(php_streams2_Exception_ce, 0,
                                "Failure calling Context::getAllParams()");
        return;
    }

    p = zend_symtable_find(Z_ARR(retval), param);
    zval_dtor(&retval);
    if (!p) {
        zend_throw_exception_ex(php_streams2_Exception_ce, 0,
                                "Invalid return from Context::getAllParams()");
        return;
    }

    RETURN_ZVAL(p, 1, 0);
}
/* }}} */

/* {{{ proto array TContext::getAllParams() */
static PHP_METHOD(TContext, getAllParams) {
    array_init(return_value);
}
/* }}} */

static zend_function_entry tcontext_methods[] = {
    PHP_ME(TContext, getOption, arginfo_getoption, ZEND_ACC_PUBLIC)
    PHP_ME(TContext, getSchemeOptions, arginfo_getschemeoptions, ZEND_ACC_PUBLIC)
    PHP_ME(TContext, getAllOptions, arginfo_getall, ZEND_ACC_PUBLIC)
    PHP_ME(TContext, getParam, arginfo_getparam, ZEND_ACC_PUBLIC)
    PHP_ME(TContext, getAllParams, arginfo_getall, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

/***************************************************************************/
/* Stream\Filter */
zend_class_entry *php_streams2_Filter_ce;

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_filter, ZEND_RETURN_VALUE, 1, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO();

static zend_function_entry filter_interface_methods[] = {
    PHP_ABSTRACT_ME(Filter, doFilter, arginfo_filter)
    PHP_FE_END
};

/***************************************************************************/
/* Stream\NotificationListener */
zend_class_entry *php_streams2_NotificationListener_ce;

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_notify, ZEND_RETURN_VALUE, 6, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, severity, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
    ZEND_ARG_TYPE_INFO(0, message_code, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, bytes_transferred, IS_LONG, 0)
    ZEND_ARG_TYPE_INFO(0, bytes_total, IS_LONG, 0)
ZEND_END_ARG_INFO();

static zend_function_entry notify_interface_methods[] = {
    PHP_ABSTRACT_ME(NotificationListener, notify, arginfo_notify)
    PHP_FE_END
};

/***************************************************************************/
/* MINIT */

PHP_MINIT_FUNCTION(streams2_context) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, PHP_NS_NAME(NS_STREAM, "Context"), context_interface_methods);
    php_streams2_Context_ce = zend_register_internal_class(&ce);
    php_streams2_Context_ce->ce_flags |= ZEND_ACC_INTERFACE;

    REGISTER_NS_STRING_CONSTANT(NS_STREAM_CONTEXT, "READ_FILTER",
                                PHP_STREAMS2_CONTEXT_READ_FILTER,
                                CONST_CS | CONST_PERSISTENT);
    REGISTER_NS_STRING_CONSTANT(NS_STREAM_CONTEXT, "WRITE_FILTER",
                                PHP_STREAMS2_CONTEXT_WRITE_FILTER,
                                CONST_CS | CONST_PERSISTENT);
    REGISTER_NS_STRING_CONSTANT(NS_STREAM_CONTEXT, "NOTIFIER",
                                PHP_STREAMS2_CONTEXT_NOTIFIER,
                                CONST_CS | CONST_PERSISTENT);

    INIT_CLASS_ENTRY(ce, PHP_NS_NAME(NS_STREAM, "TContext"), tcontext_methods);
    php_streams2_TContext_ce = zend_register_internal_class(&ce);
    php_streams2_TContext_ce->ce_flags |= ZEND_ACC_TRAIT;
    zend_class_implements(php_streams2_TContext_ce, 1, php_streams2_Context_ce);

    INIT_CLASS_ENTRY(ce, PHP_NS_NAME(NS_STREAM, "Filter"), filter_interface_methods);
    php_streams2_Filter_ce = zend_register_internal_class(&ce);
    php_streams2_Filter_ce->ce_flags |= ZEND_ACC_INTERFACE;

    INIT_CLASS_ENTRY(ce, PHP_NS_NAME(NS_STREAM, "NotificationListener"), notify_interface_methods);
    php_streams2_NotificationListener_ce = zend_register_internal_class(&ce);
    php_streams2_NotificationListener_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
