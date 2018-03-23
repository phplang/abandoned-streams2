--TEST--
Test that the streams2 extension exists
--FILE--
<?php
var_dump(interface_exists('Stream'));
class A implements Stream {}
--EXPECT--
bool(true)

Fatal error: Class A contains 2 abstract methods and must therefore be declared abstract or implement the remaining methods (Stream::__construct, Stream::getName) in /home/james/workspace/streams2/tests/stream2-interface.php on line 3
