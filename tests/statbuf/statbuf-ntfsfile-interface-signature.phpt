--TEST--
Test that the Stream\StatBuf\NTFSFile interface exists and has correct method signatures
--FILE--
<?php
var_dump(interface_exists(\Stream\StatBuf\NTFSFile::class));
\ReflectionClass::export(\Stream\StatBuf\NTFSFile::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream\StatBuf\NTFSFile extends Stream\StatBuf\File ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [0] {
  }
}
