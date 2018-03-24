--TEST--
Test Stream\File internal implementation can write to a file
--FILE--
<?php
$f = new Stream\File("/tmp/foo", "w");
$f->write("Hello world");
var_dump(file_get_contents("/tmp/foo"));
--EXPECT--
string(11) "Hello world"
--CLEAN--
<?php
unlink("/tmp/foo");
