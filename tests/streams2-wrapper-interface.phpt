--TEST--
Test that the Wrapper interface exists and has correct number of required methods
--FILE--
<?php
var_dump(interface_exists(\Stream\Wrapper::class));
class A implements \Stream\Wrapper {}
--EXPECTF--
bool(true)

Fatal error: Class A contains 1 abstract method and must therefore be declared abstract or implement the remaining methods (Stream\Wrapper::getName) in %s on line %d
