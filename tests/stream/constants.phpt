--TEST--
Test constants are declared correctly
--FILE--
<?php
var_dump(\Stream::SEEK_SET);
var_dump(\Stream::SEEK_CUR);
var_dump(\Stream::SEEK_END);
--EXPECT--
int(0)
int(1)
int(2)
