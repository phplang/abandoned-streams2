--TEST--
Test that the Stream\StatBuf\Sizable interface exists and has correct method signatures
--FILE--
<?php
var_dump(interface_exists(\Stream\StatBuf\File::class));
\ReflectionClass::export(\Stream\StatBuf\File::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream\StatBuf\File ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [3] {
    Method [ <internal:streams2> abstract public method getCTime ] {

      - Parameters [0] {
      }
      - Return [ int%S ]
    }

    Method [ <internal:streams2> abstract public method getMTime ] {

      - Parameters [0] {
      }
      - Return [ int%S ]
    }

    Method [ <internal:streams2> abstract public method getATime ] {

      - Parameters [0] {
      }
      - Return [ int%S ]
    }
  }
}
