--TEST--
Test that the streams2 extension exists
--FILE--
<?php
var_dump(interface_exists('Stream'));
class A implements Stream {}
--EXPECTF--
bool(true)

Fatal error: Class A contains 13 abstract methods and must therefore be declared abstract or implement the remaining methods (Stream::__construct, Stream::getName, Stream::getUri, ...) in %s on line %d
