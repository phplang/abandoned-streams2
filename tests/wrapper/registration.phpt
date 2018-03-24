--TEST--
Test registering/unregistering a wrapper
--FILE--
<?php
// @todo register, then check exists, then unregister, then check exists etc.
echo \Stream\Wrapper\register() . "\n";
echo \Stream\Wrapper\exists() . "\n";
echo \Stream\Wrapper\getWrapper() . "\n";
echo \Stream\Wrapper\unregister();
--EXPECT--
Stream\Wrapper\register() not implemented yet...
Stream\Wrapper\exists() not implemented yet...
Stream\Wrapper\getWrapper() not implemented yet...
Stream\Wrapper\unregister() not implemented yet...
