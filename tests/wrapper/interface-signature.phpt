--TEST--
Test that the Wrapper interface exists and has correct number of required methods
--FILE--
<?php
var_dump(interface_exists(\Stream\Wrapper::class));
\ReflectionClass::export(\Stream\Wrapper::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream\Wrapper ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [13] {
    Method [ <internal:streams2> abstract public method getName ] {

      - Parameters [0] {
      }
      - Return [ string ]
    }

    Method [ <internal:streams2> abstract public method open ] {

      - Parameters [3] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <required> string $mode ]
        Parameter #2 [ <optional> Stream\Context or NULL $context ]
      }
      - Return [ Stream ]
    }

    Method [ <internal:streams2> abstract public method opendir ] {

      - Parameters [3] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <optional> int%S $flags ]
        Parameter #2 [ <optional> Stream\Context or NULL $context ]
      }
      - Return [ Stream ]
    }

    Method [ <internal:streams2> abstract public method stat ] {

      - Parameters [3] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <optional> int%S $flags ]
        Parameter #2 [ <optional> Stream\Context or NULL $context ]
      }
    }

    Method [ <internal:streams2> abstract public method unlink ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $uri ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method move ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $from ]
        Parameter #1 [ <required> string $to ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method copy ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $from ]
        Parameter #1 [ <required> string $to ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method mkdir ] {

      - Parameters [3] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <optional> bool%S $recursive ]
        Parameter #2 [ <optional> int%S $mode ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method rmdir ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $uri ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method touch ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $uri ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method chmod ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <required> int%S $mode ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method chusr ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <required> string $user ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method chgrp ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <required> string $group ]
      }
      - Return [ bool%S ]
    }
  }
}
