--TEST--
Test that the Wrapper interface exists and has correct number of required methods
--FILE--
<?php
var_dump(interface_exists(\Stream\Wrapper::class));
class A implements \Stream\Wrapper {}
--EXPECTF--
bool(true)

Fatal error: Class A contains 13 abstract methods and must therefore be declared abstract or implement the remaining methods (Stream\Wrapper::getName, Stream\Wrapper::open, Stream\Wrapper::opendir, ...) in %s on line %d
