--TEST--
Test that the streams2 extension exists
--FILE--
<?php
var_dump(extension_loaded('streams2'));
--EXPECT--
bool(true)
