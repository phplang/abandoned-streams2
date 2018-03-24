--TEST--
Test registering/unregistering a wrapper
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
