--TEST--
Test registering/unregistering a transport
--FILE--
<?php
// @todo register, then check exists, then unregister, then check exists etc.
echo \Stream\Transport\register() . "\n";
echo \Stream\Transport\exists() . "\n";
echo \Stream\Transport\unregister();
--EXPECT--
Stream\Transport\register() not implemented yet...
Stream\Transport\exists() not implemented yet...
Stream\Transport\unregister() not implemented yet...
