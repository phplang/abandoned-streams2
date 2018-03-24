--TEST--
Test that a stream can be opened
--FILE--
<?php
\ReflectionFunction::export('Stream\Open');
echo \Stream\Open();
--EXPECT--
Function [ <internal:streams2> function Stream\Open ] {

  - Parameters [4] {
    Parameter #0 [ <required> string $uri ]
    Parameter #1 [ <required> string $mode ]
    Parameter #2 [ <required> int%S $options ]
    Parameter #3 [ <optional> Stream\Context or NULL $context ]
  }
  - Return [ Stream ]
}

Stream\Open() not implemented yet...
