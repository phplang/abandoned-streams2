--TEST--
You should not be able to register a wrapper using a factory that does not return a Stream
--FILE--
<?php
$scheme = 'foo';
var_dump(\Stream\Wrapper\register(
    $scheme,
    function () {
        return 'string';
    }
));
--EXPECTF--
Fatal error: Uncaught Error: Factory did not return something implementing Stream in %s:%d
Stack trace:
%a
