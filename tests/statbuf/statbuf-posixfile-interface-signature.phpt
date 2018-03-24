--TEST--
Test that the Stream\StatBuf\PosixFile interface exists and has correct method signatures
--FILE--
<?php
var_dump(interface_exists(\Stream\StatBuf\PosixFile::class));
\ReflectionClass::export(\Stream\StatBuf\PosixFile::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream\StatBuf\PosixFile extends Stream\StatBuf\File ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:streams2> abstract public method getMode ] {

      - Parameters [0] {
      }
      - Return [ int%S ]
    }
  }
}
