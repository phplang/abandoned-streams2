PHP_ARG_ENABLE(streams2, Whether to enable streams support, [ --enable-streams2 Enable streams2])

if test "$PHP_STREAMS2" = "yes"; then
    AC_DEFINE(HAVE_STREAMS2, 1, [Whether you have streams2])
    PHP_NEW_EXTENSION(streams2, streams2.c \
        streams2-context.c \
        streams2-exceptions.c \
        streams2-stream-interface.c \
        streams2-wrapper-interface.c \
        streams2-statbuf-interface.c \
        streams2-statbuf-sizable-interface.c \
        streams2-statbuf-file-interface.c \
        streams2-statbuf-posixfile-interface.c \
        streams2-statbuf-ntfsfile-interface.c, $ext_shared)
fi
