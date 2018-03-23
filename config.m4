PHP_ARG_ENABLE(streams2, Whether to enable streams support, [ --enable-streams2 Enable streams2])

if test "$PHP_STREAMS2" = "yes"; then
    AC_DEFINE(HAVE_STREAMS2, 1, [Whether you have streams2])
    PHP_NEW_EXTENSION(streams2, streams2.c, $ext_shared)
fi
